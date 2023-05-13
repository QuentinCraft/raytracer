/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PPMRenderer.cpp
*/

#include <thread>
#include <fstream>
#include "PPMRenderer.hpp"

RayTracer::PPMRenderer::PPMRenderer(int width, int height) : ARenderer(width, height)
{
}

RayTracer::PPMRenderer::~PPMRenderer()
{
}

void RayTracer::PPMRenderer::build(std::unique_ptr<RayTracer::Scene> &scene, bool fast)
{
    int nbThreads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    std::mutex mutex;

    std::vector<std::vector<std::optional<Math::Vector3D>>> res(scene->_camera->getHeight(), std::vector<std::optional<Math::Vector3D>>(scene->_camera->getWidth()));

    auto f = [&](auto n) {
        int x = n * (scene->_camera->getHeight() / (nbThreads));
        int xEnd = ((n + 1) * (scene->_camera->getWidth() / (nbThreads)));
        std::vector<std::optional<Math::Vector3D>> temp(scene->_camera->getWidth());

        bool status = true;

        for (int yt = 0; yt < scene->_camera->getHeight(); yt++) {
            status = !status;
            for (int xt = x; xt < xEnd; xt++) {
                double u = yt / scene->_camera->getWidth() * 2 -1;
                double v = xt / scene->_camera->getHeight() * 2 - 1;
                if ((xt % 2 == status) || !fast) {
                    Math::Vector3D color = scene->_camera->pointAt(u, v, scene->_objects, scene->_lights, scene->_ambientLight);
                    mutex.lock();
                    res[xt][yt] = color;
                    mutex.unlock();
                } else {
                    res[xt][yt] = std::nullopt;
                }
            }
        }
    };

    threads.reserve(nbThreads);
    for (int i = 0; i < nbThreads; i++) {
        threads.emplace_back(f, i);
    }

    for (auto &x: threads)
        x.join();

    std::ofstream file("render.ppm");
    file << "P3\n" << scene->_camera->getWidth() << " " << scene->_camera->getHeight() << "\n255\n";
    for (int i = 0; i < scene->_camera->getHeight(); i++) {
        for (int j = 0; j < scene->_camera->getHeight(); j++) {
            if (!res[i][j].has_value()) {
                Math::Vector3D temp;
                int div = 0;
                if (i - 1 >= 0) {
                    temp += res[i - 1][j].value();
                    div++;
                }
                if (i + 1 < scene->_camera->getHeight()) {
                    temp += res[i + 1][j].value();
                    div++;
                }
                if (j - 1 >= 0) {
                    temp += res[i][j - 1].value();
                    div++;
                }
                if (j + 1 < scene->_camera->getHeight()) {
                    temp += res[i][j + 1].value();
                    div++;
                }
                res[i][j] = Math::Vector3D();
                res[i][j].value()._x = temp._x / div;
                res[i][j].value()._y = temp._y / div;
                res[i][j].value()._z = temp._z / div;
            }
            if (std::isnan(res[i][j].value()._x) || std::isnan(res[i][j].value()._y) || std::isnan(res[i][j].value()._z))
                file << "255 255 255" << std::endl;
            else
                file << (unsigned int) std::clamp(std::round(res[i][j].value()._x), 0.0, 255.0) << " " << (unsigned int) std::clamp(std::round(res[i][j].value()._y), 0.0, 255.0) << " " << (unsigned int) std::clamp(std::round(res[i][j].value()._z), 0.0, 255.0) << std::endl;
        }
    }
    file.close();
}