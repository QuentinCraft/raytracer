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
#include "renderer/PPMRenderer.hpp"

int main(int argc, char **argv) {
    bool reload = false;
    auto begin = std::chrono::high_resolution_clock::now();

    std::unique_ptr<RayTracer::IObjFile> obj = std::make_unique<RayTracer::ObjFile>();
    bool fast = false;
    bool graph = false;

    if (argc == 1) {
        std::cerr << "Usage: ./bsraytracer [config] <flags>" << std::endl;
        return 84;
    }
    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "-f")
            fast = true;
        if (std::string(argv[i]) == "-g")
            graph = true;
    }
    std::cout << "Fast: " << (fast ? "true" : "false") << std::endl;
    std::unique_ptr<RayTracer::Utils::ConfigManager> configManager;
    std::unique_ptr<RayTracer::Scene> scene;
    RayTracer::Utils::Config config;
    bool stopProgram = false;

    while (!stopProgram) {
        while (1) {
            configManager = std::make_unique<RayTracer::Utils::ConfigManager>("plugins");
            scene = std::make_unique<RayTracer::Scene>();
            try {
                config = configManager->getConf(argv[1]);
            } catch (RayTracer::Utils::Error &e) {
                if (!reload) {
                    std::cerr << e.what() << std::endl;
                    return 84;
                } else {
                    reload = true;
                    continue;
                }
            }
            reload = true;
            break;
        }

        scene->_camera = configManager->createCamera(config);
        try {
            scene->_objects = configManager->createObjects(config);
        } catch (RayTracer::Utils::Error &e) {
            std::cerr << e.what() << std::endl;
            return 84;
        }
        scene->_ambientLight = configManager->createAmbientLight(config);
        scene->_lights = configManager->createLight(config);
        try {
            for (auto x: config.includes) {
                std::cout << "building... using [" << x << "]" << std::endl;
                RayTracer::Utils::Config other = configManager->getConf(x, true);
                auto newObjs = configManager->createObjects(other);
                for (auto &obj: newObjs)
                    scene->_objects.push_back(obj);
                auto newLights = configManager->createLight(other);
                for (auto &light: newLights)
                    scene->_lights.push_back(light);
                std::cout << "--------------------------------" << std::endl;
            }
        } catch (RayTracer::Utils::Error &e) {
            std::cerr << e.what() << std::endl;
            return 84;
        }

//
        if (fast) {
            scene->_camera->setRecursionDepth(1);
            scene->_camera->setSuperSampling(1);
        }
        std::unique_ptr<RayTracer::IRenderer> renderer;
        if (!graph)
            renderer = std::make_unique<RayTracer::PPMRenderer>(scene->_camera->getWidth(),
                                                                scene->_camera->getHeight());
        else
            renderer = std::make_unique<RayTracer::GraphicalRenderer>(scene->_camera->getWidth(),
                                                                      scene->_camera->getHeight(),
                                                                      configManager->getConfigFile(),
                                                                      &stopProgram);
        renderer->build(scene, fast);
        if (!graph)
            break;
    }



    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "Time: " << std::round((elapsed.count() * 1e-9) / 0.01) * 0.01 << " seconds." << std::endl;
    return 0;
}