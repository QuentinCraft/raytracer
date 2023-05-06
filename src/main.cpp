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
    RayTracer::AMaterial emerald(Math::Vector3D(0.07568, 0.61424, 0.07568), Math::Vector3D(0.633, 0.727811, 0.633), 76.8, 1.57, false);

    std::shared_ptr<RayTracer::ChessBoard> chessBoardChrome = std::make_shared<RayTracer::ChessBoard>(chrome, chrome, Math::Vector3D(200, 200, 200), Math::Vector3D(25, 25, 25));
    std::shared_ptr<RayTracer::ChessBoard> chessBoardPlastic = std::make_shared<RayTracer::ChessBoard>(plastic, plastic, Math::Vector3D(200, 200, 200), Math::Vector3D(25, 25, 25));
    std::shared_ptr<RayTracer::ChessBoard> chessBoardPlasticChrome = std::make_shared<RayTracer::ChessBoard>(plastic, chrome, Math::Vector3D(200, 200, 200), Math::Vector3D(25, 25, 25));
    std::shared_ptr<RayTracer::ChessBoard> chessBoardChromePlastic = std::make_shared<RayTracer::ChessBoard>(chrome, plastic, Math::Vector3D(200, 200, 200), Math::Vector3D(25, 25, 25));


    std::shared_ptr<RayTracer::ATexture> basic = std::make_shared<RayTracer::ATexture>();
    std::shared_ptr<RayTracer::ATexture> basicChrome = std::make_shared<RayTracer::ATexture>(chrome, Math::Vector3D(235, 228, 235));
    std::shared_ptr<RayTracer::ATexture> redChrome = std::make_shared<RayTracer::ATexture>(chrome, Math::Vector3D(200, 50, 50));
    std::shared_ptr<RayTracer::ATexture> basicPlastic = std::make_shared<RayTracer::ATexture>(plastic, Math::Vector3D(150, 80, 150));
    std::shared_ptr<RayTracer::ATexture> basicEmerald = std::make_shared<RayTracer::ATexture>(emerald, Math::Vector3D(230, 230, 230));

    scene->_objects.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(-3, 4, -4), 4, basicPlastic));
    scene->_objects.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(-10, 4, -11), 4, basicChrome));
    scene->_objects.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(4, 4, -10), 4, redChrome));
    scene->_objects.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(0, 2, -13), 1, basicEmerald));


    scene->_objects.push_back(std::make_shared<RayTracer::Plane>(Math::Vector3D(0, 0, 0), Math::Vector3D(0, 1, 0), chessBoardChrome));
    scene->_objects.push_back(std::make_shared<RayTracer::Plane>(Math::Vector3D(0, 20, 0), Math::Vector3D(0, -1, 0), basic));
    scene->_objects.push_back(std::make_shared<RayTracer::Plane>(Math::Vector3D(0, 0, -20), Math::Vector3D(0, 0, 1), basic));
    scene->_objects.push_back(std::make_shared<RayTracer::Plane>(Math::Vector3D(0, 0, 20), Math::Vector3D(0, 0, -1), basic));
    scene->_objects.push_back(std::make_shared<RayTracer::Plane>(Math::Vector3D(-20, 0, 0), Math::Vector3D(1, 0, 0), basic));
    scene->_objects.push_back(std::make_shared<RayTracer::Plane>(Math::Vector3D(20, 0, 0), Math::Vector3D(-1, 0, 0), basic));

    scene->_ambientLight = std::make_shared<RayTracer::Ambient>(Math::Vector3D(0.15, 0.15, 0.15));
    scene->_lights.push_back(std::make_shared<RayTracer::Spot>(Math::Vector3D(-1, 9, -21), Math::Vector3D(70, 70, 70)));

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