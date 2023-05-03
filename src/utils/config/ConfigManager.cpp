/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ConfigManager.cpp
*/

#include "ConfigManager.hpp"
#include "utils/string/StringUtils.hpp"
#include "objects/PlaneData.hpp"
#include "objects/SphereData.hpp"
#include "utils/factory/ObjectFactory.hpp"

RayTracer::Utils::Config::Camera RayTracer::Utils::ConfigManager::_getCamera(const libconfig::Setting& root) {
    RayTracer::Utils::Config::Camera cam;

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
        throw RayTracer::Utils::Error("Error: Invalid settings in [Camera] part");
    }

    return cam;
}

RayTracer::Utils::Config::Light RayTracer::Utils::ConfigManager::_getLight(
        const libconfig::Setting &root) {
    RayTracer::Utils::Config::Light light;

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
        throw RayTracer::Utils::Error("Error: Invalid settings in [Light] part");
    }
    return light;
}

void RayTracer::Utils::ConfigManager::_getSphere(
        const libconfig::Setting &primitive) {
    try {
        const libconfig::Setting& color = primitive["color"];
        int x = primitive["x"];
        int y = primitive["y"];
        int z = primitive["z"];
        int r = primitive["r"];
        int colorX = color["r"];
        int colorY = color["g"];
        int colorZ = color["b"];
        std::cout << "[Sphere]----------------------" << std::endl;
        std::cout << "pos : " << x << ", " << y << ", " << z << std::endl;
        std::cout << "color : " << colorX << ", " << colorY << ", " << colorZ << std::endl;
        std::unique_ptr<IData> data = std::make_unique<RayTracer::SphereData>();
        data->setPoint(Math::Vector3D(x, y, z));
        data->setColor(Math::Vector3D(colorX, colorY, colorZ));
        data->setRadius(r);
        IBuilder *builder = _builder->createObjectBuilder("sphere");
        _primitives.push_back({builder, std::move(data)});

    } catch (libconfig::SettingNotFoundException &e) {
        throw Error("Error: Invalid settings in [Primitives/Sphere] part");
    }
}


void RayTracer::Utils::ConfigManager::_getPlane(
        const libconfig::Setting &primitive) {
    try {
        const libconfig::Setting& color = primitive["color"];
        std::string axis = primitive["axis"];
        int position = primitive["position"];
        double pos = static_cast<double>(position);
        int colorX = color["r"];
        int colorY = color["g"];
        int colorZ = color["b"];
        std::cout << "[Plane]-----------------------" << std::endl;
        std::cout << "axis : " << axis << std::endl;
        std::cout << "pos : " << position << std::endl;
        std::cout << "color : " << colorX << ", " << colorY << ", " << colorZ << std::endl;
        std::unique_ptr<IData> data = std::make_unique<RayTracer::PlaneData>();
        data->setAxis(axis);
        data->setColor((Math::Vector3D){(axis == "X") ? pos : 0,
                         (axis == "Y") ? pos : 0,
                         (axis == "Z") ? pos : 0});
        data->setColor(Math::Vector3D(colorX, colorY, colorZ));
        IBuilder *builder = _builder->createObjectBuilder("plane");
        _primitives.push_back({builder, std::move(data)});
    } catch (libconfig::SettingNotFoundException &e) {
        throw Error("Error: Invalid settings in [Primitives/Plane] part");
    }
}

void RayTracer::Utils::ConfigManager::_getPrimitives(
        const libconfig::Setting &root) {
    try {
        const libconfig::Setting& primitives = root["primitives"];
        for (int i = 0; i < primitives.getLength(); i++) {
            const libconfig::Setting& primitive = primitives[i];
            for (int x = 0; x < primitive.getLength(); x++) {
                std::string item = RayTracer::Utils::StringUtils::split(primitive[x].getPath(), ".")[1];
                if (item == "spheres")
                    _getSphere(primitive[x]);
                if (item == "planes")
                    _getPlane(primitive[x]);
            }
        }
    } catch (libconfig::SettingNotFoundException &e) {
        throw Error("Error: Invalid settings in [Primitives] part");
    }
}

RayTracer::Utils::Config RayTracer::Utils::ConfigManager::getConf(const std::string& path) {
    RayTracer::Utils::Config cnf;
    libconfig::Config config;

    try {
        config.readFile(path.c_str());
    } catch (libconfig::FileIOException &e) {
        throw RayTracer::Utils::Error("Error: Cannot read file : [" + path + "]");
    } catch (libconfig::ParseException &e) {
        throw RayTracer::Utils::Error("Error: Cannot be parsed the config file (lines: " + std::to_string(e.getLine()) + ")");
    }

    const libconfig::Setting& root = config.getRoot();
    cnf.camera = _getCamera(root);
    cnf.light = _getLight(root);
    _getPrimitives(root);
    cnf.primitives = std::move(_primitives);
    return cnf;
}