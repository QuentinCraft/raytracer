/*
** EPITECH PROJECT, 2023
** GraphicalRenderer.cpp
** File description:
** GraphicalRenderer
*/

#include <thread>
#include "GraphicalRenderer.hpp"

RayTracer::GraphicalRenderer::GraphicalRenderer(int width, int height) : ARenderer(width, height)
{
    _displayModule = std::make_unique<SFMLDisplayModule>(width, height);
    _isRunning = true;
}

RayTracer::GraphicalRenderer::~GraphicalRenderer()
{
}

void RayTracer::GraphicalRenderer::eventHandler()
{
    EventType type = _displayModule->eventHandler();

    if (type == EventType::CLOSE)
        _isRunning = false;
}

void RayTracer::GraphicalRenderer::build(std::unique_ptr<RayTracer::Scene> &scene, bool fast)
{
    int nbThreads = std::thread::hardware_concurrency() - 1;
    std::vector<std::thread> threads;
    std::mutex mutex;

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
            if (static_cast<int>(elapsedTime.count() * 10) % 2 == 0)
                continue;
            mutex.lock();
            _displayModule->clear();
            _displayModule->display();
            mutex.unlock();
        }
    });

    while (_isRunning && _displayModule->isOpen()) {
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

        bool waiting = true;
        displayThread.join();
    }
    _displayModule->close();
}