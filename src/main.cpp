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

#include "texture/ChessBoard.hpp"
#include "texture/ATexture.hpp"
#include "texture/ITexture.hpp"

#include "materials/Plastic.hpp"
#include "materials/Chrome.hpp"


#include <ctime>

int main() {
    std::ofstream file("render.ppm");

    std::unique_ptr<RayTracer::Scene> scene = std::make_unique<RayTracer::Scene>();
    RayTracer::Chrome chrome;
    RayTracer::Plastic plastic;

    std::shared_ptr<RayTracer::ChessBoard> chessBoard = std::make_shared<RayTracer::ChessBoard>(chrome, plastic, Math::Vector3D(255, 255, 255), Math::Vector3D(1, 1, 1));
    std::shared_ptr<RayTracer::ATexture> basic = std::make_shared<RayTracer::ATexture>();



    scene->_objects.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(-4, 4, 10), 4, basic));
    scene->_objects.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(0, 4, 0), 4, basic));
    scene->_objects.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(-10, 4, -11), 4, basic));
    scene->_objects.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(4, 4, -10), 4, basic));
    scene->_objects.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(0, 2, -13), 1, basic));


    scene->_objects.push_back(std::make_shared<RayTracer::Plane>(Math::Vector3D(0, 0, 0), Math::Vector3D(0, 1, 0), chessBoard));
    scene->_objects.push_back(std::make_shared<RayTracer::Plane>(Math::Vector3D(0, 20, 0), Math::Vector3D(0, -1, 0), chessBoard));
    scene->_objects.push_back(std::make_shared<RayTracer::Plane>(Math::Vector3D(0, 0, -20), Math::Vector3D(0, 0, 1), chessBoard));
    scene->_objects.push_back(std::make_shared<RayTracer::Plane>(Math::Vector3D(0, 0, 20), Math::Vector3D(0, 0, -1), chessBoard));
    scene->_objects.push_back(std::make_shared<RayTracer::Plane>(Math::Vector3D(-20, 0, 0), Math::Vector3D(1, 0, 0), chessBoard));
    scene->_objects.push_back(std::make_shared<RayTracer::Plane>(Math::Vector3D(20, 0, 0), Math::Vector3D(-1, 0, 0), chessBoard));

    scene->_lights.push_back(std::make_shared<RayTracer::Spot>(Math::Vector3D(-1, 2, -15), Math::Vector3D(35, 35, 35)));

    scene->_ambientLight = std::make_shared<RayTracer::Ambient>(Math::Vector3D(0.2, 0.2, 0.2));

    scene->_camera = std::make_unique<RayTracer::Camera>(Math::Vector3D(0, 3, -25), 800, 800, 110);

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

//int main(int argc, char **argv)
//{
//    if (argc == 1) {
//        std::cerr << "Usage: ./bsraytracer [config]" << std::endl;
//        return 84;
//    }
//    std::unique_ptr<RayTracer::Utils::ConfigManager> configManager = std::make_unique<RayTracer::Utils::ConfigManager>("plugins");
//    RayTracer::Utils::Config config = configManager->getConf(argv[1]);
//
//    auto objects = configManager->createObjects(config);
//
//    configManager->createCamera(config);
//    configManager->createLight(config);
//    return 0;
//}