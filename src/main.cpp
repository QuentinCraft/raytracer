/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** main.cpp
*/

#include <iostream>
#include <fstream>
#include <memory>

#include "scenes/Scene.hpp"

#include "cameras/Camera.hpp"

#include "objects/Sphere.hpp"
#include "objects/Plane.hpp"
#include "objects/Cylinder.hpp"
#include "objects/Cone.hpp"

#include "utils/config/ConfigManager.hpp"
#include "utils/loader/LibraryLoader.hpp"
#include "utils/loader/PluginsManager.hpp"

#include "texture/ChessBoard.hpp"
#include "texture/ATexture.hpp"
#include "texture/ITexture.hpp"


#include "materials/Plastic.hpp"
#include "materials/Chrome.hpp"
#include <chrono>

#include <ctime>
#include <thread>
#include <list>

#include "renderer/GraphicalRenderer.hpp"

int main(int argc, char **argv) {
//    std::unique_ptr<RayTracer::IRenderer> renderer = std::make_unique<RayTracer::GraphicalRenderer>(800, 800);
//    renderer->build();
//    return 0;
    auto begin = std::chrono::high_resolution_clock::now();

    std::unique_ptr<RayTracer::IObjFile> obj = std::make_unique<RayTracer::ObjFile>();
    bool fast = false;

    if (argc == 1) {
        std::cerr << "Usage: ./bsraytracer [config] <flag>" << std::endl;
        return 84;
    }
    if (argc == 3 && std::string(argv[2]) == "-f")
        fast = true;
    std::cout << "Fast: " << (fast ? "true" : "false") << std::endl;
    std::unique_ptr<RayTracer::Utils::ConfigManager> configManager = std::make_unique<RayTracer::Utils::ConfigManager>("plugins");
    std::unique_ptr<RayTracer::Scene> scene = std::make_unique<RayTracer::Scene>();

    RayTracer::Utils::Config config;
    try {
        config = configManager->getConf(argv[1]);
    } catch (RayTracer::Utils::Error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }

    scene->_camera = configManager->createCamera(config);
    scene->_objects = configManager->createObjects(config);
    scene->_ambientLight = configManager->createAmbientLight(config);
    scene->_lights = configManager->createLight(config);
    for (auto x : config.includes) {
        std::cout << "building... using [" << x << "]" << std::endl;
        RayTracer::Utils::Config other = configManager->getConf(x, true);
        auto newObjs = configManager->createObjects(other);
        for (auto &obj : newObjs)
            scene->_objects.push_back(obj);
        auto newLights = configManager->createLight(other);
        for (auto &light : newLights)
            scene->_lights.push_back(light);
        std::cout << "--------------------------------" << std::endl;
    }
//
    if (fast) {
        scene->_camera->setRecursionDepth(1);
        scene->_camera->setSuperSampling(1);
    }
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

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "Time: " << std::round((elapsed.count() * 1e-9) / 0.01) * 0.01 << " seconds." << std::endl;
    return 0;
}