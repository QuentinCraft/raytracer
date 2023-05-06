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

int main() {
    std::ofstream file("render.ppm");

    std::unique_ptr<RayTracer::Scene> scene = std::make_unique<RayTracer::Scene>();

    scene->_objects.push_back(std::make_shared<RayTracer::Cone>(Math::Vector3D(0, 6, 0), 6, 3, Math::Vector3D(1, 0, 0)));
    scene->_objects.push_back(std::make_shared<RayTracer::Cylinder>(Math::Vector3D(0, 1, 0), 6, 3, Math::Vector3D(1, 0, 0)));

    scene->_objects.push_back(std::make_shared<RayTracer::Plane>(Math::Vector3D(0, 0, 0), Math::Vector3D(0, 1, 0), Math::Vector3D(0.5, 0.5, 1)));
    scene->_objects.push_back(std::make_shared<RayTracer::Plane>(Math::Vector3D(0, 0, 6), Math::Vector3D(0, 0, -1), Math::Vector3D(0.5, 0.5, 1)));
    scene->_lights.push_back(std::make_shared<RayTracer::Spot>(Math::Vector3D(0, 10, -15), Math::Vector3D(1, 1, 1)));

    scene->_ambientLight = std::make_shared<RayTracer::Ambient>(Math::Vector3D(0.25, 0.25, 0.25));

    scene->_camera = std::make_unique<RayTracer::Camera>(Math::Vector3D(0, 10, -25), 800, 800, 110);

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
