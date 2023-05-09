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

#include "utils/config/ConfigManager.hpp"
#include "utils/loader/LibraryLoader.hpp"
#include "utils/loader/PluginsManager.hpp"

#include <ctime>

int main(int argc, char **argv)
{
    if (argc == 1) {
        std::cerr << "Usage: ./bsraytracer [config]" << std::endl;
        return 84;
    }
    std::ofstream file("render.ppm");
    std::unique_ptr<RayTracer::Utils::ConfigManager> configManager = std::make_unique<RayTracer::Utils::ConfigManager>("plugins");
    std::unique_ptr<RayTracer::Scene> scene = std::make_unique<RayTracer::Scene>();
    RayTracer::Utils::Config config = configManager->getConf(argv[1]);

    scene->_camera = configManager->createCamera(config);
    scene->_objects = configManager->createObjects(config);
    scene->_ambientLight = configManager->createAmbientLight(config);
    scene->_lights = configManager->createLight(config);
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

    return 0;
}