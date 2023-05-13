/*
** EPITECH PROJECT, 2023
** GraphicalRenderer.cpp
** File description:
** GraphicalRenderer
*/

#include <thread>
#include "GraphicalRenderer.hpp"

RayTracer::GraphicalRenderer::GraphicalRenderer(int width, int height, std::pair<std::string, std::string> currentConfig) : ARenderer(width, height)
{
    _displayModule = std::make_unique<SFMLDisplayModule>(width, height);
    _isRunning = true;
    _currentConfig = currentConfig.second;
    _currentConfigPath = currentConfig.first;
    _reload = false;
}

RayTracer::GraphicalRenderer::~GraphicalRenderer()
{
}

void RayTracer::GraphicalRenderer::eventHandler()
{
    EventType type = _displayModule->eventHandler();

    if (type == EventType::CLOSE) {
        _isRunning = false;
    }
}

void RayTracer::GraphicalRenderer::build(std::unique_ptr<RayTracer::Scene> &scene, bool fast)
{
    std::mutex mutex;
    int nbThreads = std::thread::hardware_concurrency() - 1;
    bool waiting = true;

    _displayModule->clear();
    _displayModule->display();

    std::thread displayThread([&]() {
        auto oldT = std::chrono::steady_clock::now();
        auto newT = std::chrono::steady_clock::now();

        while (_isRunning && _displayModule->isOpen()) {
            eventHandler();
            if (!_isRunning)
                return;

            newT = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsedTime = newT - oldT;
            if (static_cast<int>(elapsedTime.count() * 10) % 2 == 0) {
                if (!waiting)
                    continue;
                std::ifstream file(_currentConfigPath);
                std::stringstream buffer;
                buffer << file.rdbuf();
                if (buffer.str() != _currentConfig) {
                    std::cout << "Reloading..." << std::endl;
                    configManager = std::make_unique<RayTracer::Utils::ConfigManager>("plugins");
                    RayTracer::Utils::Config config;
                    bool fileIsOk = false;
                    while (_isRunning && !fileIsOk) {
                        eventHandler();
                        try {
                            config = configManager->getConf(_currentConfigPath);
                            _currentConfig = configManager->getConfigFile().second;
                        } catch (RayTracer::Utils::Error &e) {
                            continue;
                        }
                        fileIsOk = true;
                    }
                    if (!_isRunning)
                        return;
                    try {
                        scene->_camera = configManager->createCamera(config);
                        scene->_objects = configManager->createObjects(config);
                        scene->_ambientLight = configManager->createAmbientLight(config);
                        scene->_lights = configManager->createLight(config);
                    } catch (RayTracer::Utils::Error &e) {
                    }
                    //return;
                    waiting = false;
                }
                file.close();
                continue;
            }
            mutex.lock();
            _displayModule->clear();
            _displayModule->display();
            mutex.unlock();
        }
    });

    while (_isRunning && _displayModule->isOpen()) {
        {
            std::vector<std::thread> threads;

            auto f = [&](auto n) {
                int x = n * (scene->_camera->getHeight() / (nbThreads));
                int xEnd = ((n + 1) * (scene->_camera->getWidth() / (nbThreads)));

                for (int yt = 0; yt < scene->_camera->getHeight(); yt++) {
                    for (int xt = x; xt < xEnd; xt++) {
                        double u = yt / scene->_camera->getWidth() * 2 -1;
                        double v = xt / scene->_camera->getHeight() * 2 - 1;
                        Math::Vector3D color = scene->_camera->pointAt(u, v, scene->_objects, scene->_lights, scene->_ambientLight);
                        mutex.lock();
                        _displayModule->draw(Math::Vector3D(static_cast<double>(yt), static_cast<double>(xt), 0.0), color);
                        if (!_isRunning) {
                            mutex.unlock();
                            return;
                        }
                        mutex.unlock();
                    }
                }
            };

            threads.reserve(nbThreads);
            for (int i = 0; i < nbThreads; i++) {
                threads.emplace_back(f, i);
            }

            for (auto &x: threads)
                x.join();

            waiting = true;
            while (waiting && _isRunning) {
                std::cout << "Waiting for config file to change..." << std::endl;
            }
            std::cout << "Done" << std::endl;
        }
    }
    displayThread.join();
    _displayModule->close();
}