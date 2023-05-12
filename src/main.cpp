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
#include "utils/ObjFile/ObjFile.hpp"

#include <ctime>


int main(int argc, char **argv) {
    auto begin = std::chrono::high_resolution_clock::now();

    std::unique_ptr<RayTracer::IObjFile> obj = std::make_unique<RayTracer::ObjFile>();

    obj->load("scenes/cube.obj");

    return 0;
    if (argc == 1) {
        std::cerr << "Usage: ./bsraytracer [config]" << std::endl;
        return 84;
    }
    std::ofstream file("render.ppm");
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
    file << "P3\n" << scene->_camera->getWidth() << " " << scene->_camera->getHeight() << "\n255\n";

    for (int y = 0; y < scene->_camera->getWidth(); y++) {
        for (int x = 0; x < scene->_camera->getHeight(); x++) {
            double u = x / scene->_camera->getWidth() * 2 -1;
            double v = y / scene->_camera->getHeight() * 2 - 1;
            Math::Vector3D color = scene->_camera->pointAt(u, v, scene->_objects, scene->_lights, scene->_ambientLight);
            file << ((unsigned int) color._x) << " " << ((unsigned int) color._y) << " " << ((unsigned int) color._z) << std::endl;
        }
    }
    file.close();

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "Time: " << std::round((elapsed.count() * 1e-9) / 0.01) * 0.01 << " seconds." << std::endl;
    return 0;
}