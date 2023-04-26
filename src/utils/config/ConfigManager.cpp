/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ConfigManager.cpp
*/

#include "ConfigManager.hpp"

RayTracer::Utils::Config::ConfigManager::Config::Camera RayTracer::Utils::Config::ConfigManager::_getCamera(const libconfig::Setting& root) {
    RayTracer::Utils::Config::ConfigManager::Config::Camera cam;

    try {
        const libconfig::Setting& camera = root["camera"];
        const libconfig::Setting& resolution = camera["resolution"];
        const libconfig::Setting& position = camera["position"];
        const libconfig::Setting& rotation = camera["rotation"];

        cam.resolution._x = static_cast<int>(resolution["height"]);
        cam.resolution._y = static_cast<int>(resolution["width"]);
        cam.resolution._z = 0;
        cam.fieldOfView = camera["fieldOfView"];

        cam.rotation._x = static_cast<int>(rotation["x"]);
        cam.rotation._y = static_cast<int>(rotation["y"]);
        cam.rotation._z = static_cast<int>(rotation["z"]);

        cam.position._y = static_cast<int>(position["y"]);
        cam.position._x = static_cast<int>(position["x"]);
        cam.position._z = static_cast<int>(position["z"]);
    } catch (libconfig::SettingNotFoundException &e) {
        throw Error("Error: Invalid settings in [Camera] part");
    }

    return cam;
}

RayTracer::Utils::Config::ConfigManager::Config::Light RayTracer::Utils::Config::ConfigManager::_getLight(
        const libconfig::Setting &root) {
    RayTracer::Utils::Config::ConfigManager::Config::Light light;

    try {
        const libconfig::Setting& lightSetting = root["lights"];
        const libconfig::Setting& points = lightSetting["point"];
        const libconfig::Setting& directional = lightSetting["directional"];

        light.ambient = lightSetting["ambient"];
        light.diffuse = lightSetting["diffuse"];

        for (int i = 0; i < points.getLength(); i++) {
            const libconfig::Setting& point = points[i];
            Math::Vector3D vec;

            vec._x = static_cast<int>(point["x"]);
            vec._y = static_cast<int>(point["y"]);
            vec._z = static_cast<int>(point["z"]);
            light.points.push_back(vec);
        }

        for (int i = 0; i < directional.getLength(); i++) {
            const libconfig::Setting& dir = directional[i];
            Math::Vector3D vec;

            vec._x = static_cast<int>(dir["x"]);
            vec._y = static_cast<int>(dir["y"]);
            vec._z = static_cast<int>(dir["z"]);
            light.directional_lights.push_back(vec);
        }

    } catch (libconfig::SettingNotFoundException &e) {
        throw Error("Error: Invalid settings in [Light] part");
    }
    return light;
}

RayTracer::Utils::Config::ConfigManager::Config RayTracer::Utils::Config::ConfigManager::getConf(const std::string& path) {
    RayTracer::Utils::Config::ConfigManager::Config cnf;
    libconfig::Config config;

    try {
        config.readFile(path.c_str());
    } catch (libconfig::FileIOException &e) {
        throw Error("Error: Cannot read file : [" + path + "]");
    } catch (libconfig::ParseException &e) {
        throw Error("Error: Cannot be parsed the config file (lines: " + std::to_string(e.getLine()) + ")");
    }

    const libconfig::Setting& root = config.getRoot();
    cnf.camera = _getCamera(root);
    cnf.light = _getLight(root);
    return cnf;
}