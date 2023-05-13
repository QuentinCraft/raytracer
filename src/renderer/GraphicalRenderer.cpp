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
    int nbThreads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    std::mutex mutex;

    _displayModule->clear();
    _displayModule->display();
    while (_isRunning && _displayModule->isOpen()) {

        eventHandler();

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
                    eventHandler();
                    if (!_isRunning) {
                        mutex.unlock();
                        return;
                    }
                    mutex.unlock();
                }
                if (!fast) {
                    mutex.lock();
                    _displayModule->display();
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

        _displayModule->display();
        bool waiting = true;
        while (_isRunning && _displayModule->isOpen() && waiting) {
            eventHandler();
        }
    }
    _displayModule->close();
}