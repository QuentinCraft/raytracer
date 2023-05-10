/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ConfigManager.cpp
*/

#include "ConfigManager.hpp"
#include "utils/string/StringUtils.hpp"
#include "utils/factory/ObjectFactory.hpp"
#include "cameras/Camera.hpp"

RayTracer::Utils::Config::Camera RayTracer::Utils::ConfigManager::_getCamera(const libconfig::Setting& root) {
    RayTracer::Utils::Config::Camera cam;

    try {
        const libconfig::Setting& camera = root["camera"];
        const libconfig::Setting& resolution = camera["resolution"];
        const libconfig::Setting& position = camera["position"];
        const libconfig::Setting& rotation = camera["rotation"];

        cam.resolution._y = static_cast<int>(resolution["height"]);
        cam.resolution._x = static_cast<int>(resolution["width"]);
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
            Math::Vector3D vec_intensity;

            vec._x = point["x"];
            vec._y = point["y"];
            vec._z = point["z"];
            libconfig::Setting& intensity = point["intensity"];
            vec_intensity._x = intensity["x"];
            vec_intensity._y = intensity["y"];
            vec_intensity._z = intensity["z"];
            light.points.push_back({vec, vec_intensity});
        }

        for (int i = 0; i < directional.getLength(); i++) {
            const libconfig::Setting& dir = directional[i];
            Math::Vector3D vec;

            vec._x = dir["x"];
            vec._y = dir["y"];
            vec._z = dir["z"];
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
        int x = primitive["x"];
        int y = primitive["y"];
        int z = primitive["z"];
        int r = primitive["r"];
        std::string texture = primitive["texture"];
        std::cout << "[Sphere]----------------------" << std::endl;
        std::cout << "pos : " << x << ", " << y << ", " << z << std::endl;
        std::cout << "texture : " << texture << std::endl;

        auto builder = _builder->createObjectBuilder("sphere");
        std::unique_ptr<IData> data = builder->createData();
        data->setCenter(Math::Vector3D(x, y, z));
        data->setPoint(Math::Vector3D(x, y, z));
        //data->setColor(Math::Vector3D(colorX, colorY, colorZ));
        for (auto &i : _textures) {
            if (i.first == texture) {
                data->setTexture(i.second);
                break;
            }
        }
        data->setRadius(r);
        _primitives.emplace_back(builder, std::move(data));
    } catch (libconfig::SettingNotFoundException &e) {
        throw Error("Error: Invalid settings in [Primitives/Sphere] part");
    }
}


void RayTracer::Utils::ConfigManager::_getPlane(
        const libconfig::Setting &primitive) {
    try {
        const libconfig::Setting& normal = primitive["normal"];
        int x = primitive["x"];
        int y = primitive["y"];
        int z = primitive["z"];
        std::string texture = primitive["texture"];
        float normalX = normal["x"];
        float normalY = normal["y"];
        float normalZ = normal["z"];
        std::cout << "[Plane]-----------------------" << std::endl;
        std::cout << "pos : " << x << ", " << y << ", " << z << std::endl;
        std::cout << "normal : " << normalX << ", " << normalY << ", " << normalZ << std::endl;
        std::cout << "texture : " << texture << std::endl;

        auto builder = _builder->createObjectBuilder("plane");
        std::unique_ptr<IData> data = builder->createData();
        //data->setColor(Math::Vector3D(colorX, colorY, colorZ));
        for (auto &i : _textures) {
            if (i.first == texture) {
                data->setTexture(i.second);
                break;
            }
        }
        data->setPoint(Math::Vector3D(x, y, z));
        data->setNormal(Math::Vector3D(normalX, normalY, normalZ));
        _primitives.emplace_back(builder, std::move(data));
    } catch (libconfig::SettingNotFoundException &e) {
        throw Error("Error: Invalid settings in [Primitives/Plane] part");
    }
}

void RayTracer::Utils::ConfigManager::_getCylinder(const libconfig::Setting &primitive) {
     try {
         int x = primitive["x"];
         int y = primitive["y"];
         int z = primitive["z"];
         std::string texture = primitive["texture"];
         float radius = primitive["r"];
         float length = primitive["l"];
         std::cout << "[Cylinder]-----------------------" << std::endl;
         auto builder = _builder->createObjectBuilder("cylinder");
         std::unique_ptr<IData> data = builder->createData();
         data->setCenter(Math::Vector3D(x, y, z));
         data->setRadius(radius);
         data->setLength(length);
         for (auto &i : _textures) {
             if (i.first == texture) {
                 data->setTexture(i.second);
                 break;
             }
         }
         //data->setColor(Math::Vector3D(colorX, colorY, colorZ));
         _primitives.emplace_back(builder, std::move(data));
     } catch (libconfig::SettingNotFoundException &e) {
         throw Error("Error: Invalid settings in [Primitives/Cylinder] part");
     }
}

std::vector<std::pair<std::shared_ptr<RayTracer::IBuilder>, std::unique_ptr<RayTracer::Utils::IData>>> RayTracer::Utils::ConfigManager::_getPrimitives(
        const libconfig::Setting &root) {
    std::vector<std::pair<std::shared_ptr<IBuilder>, std::unique_ptr<IData>>> data;
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
                if (item == "cylinders")
                    _getCylinder(primitive[x]);
            }
        }
    } catch (libconfig::SettingNotFoundException &e) {
        throw Error("Error: Invalid settings in [Primitives] part");
    }
    data = std::move(_primitives);
    return data;
}

void RayTracer::Utils::ConfigManager::_getTextures(const libconfig::Setting &root) {
    try {
        const libconfig::Setting& textures = root["textures"];
        for (int i = 0; i < textures.getLength(); i++) {
            std::cout << "[Texture]-----------------------" << std::endl;
            const libconfig::Setting& texture = textures[i];
            std::string name = texture["name"];
            std::string material1 = texture["material1"];
            std::string material2 = texture["material2"];
            std::string type = texture["type"];
            const libconfig::Setting& color1 = texture["color1"];
            const libconfig::Setting& color2 = texture["color2"];
            float color1X = color1["r"];
            float color1Y = color1["g"];
            float color1Z = color1["b"];
            float color2X = color2["r"];
            float color2Y = color2["g"];
            float color2Z = color2["b"];
            std::cout << name << std::endl;
            std::cout << "color1 : " << color1X << ", " << color1Y << ", " << color1Z << std::endl;
            std::cout << "color2 : " << color2X << ", " << color2Y << ", " << color2Z << std::endl;
            auto matA = _builder->createMaterial(material1);
            auto matB = _builder->createMaterial(material2);
            if (!matA || !matB)
                throw Error("Error: Invalid material name in [Textures] part");
            auto builder = _builder->createTextureBuilder(type);
            const auto &mat1 = *matA.get();
            const auto &mat2 = *matB.get();
            _textures.push_back({name, builder->build(mat1, mat2, Math::Vector3D(color1X, color1Y, color1Z),
                                                Math::Vector3D(color2X, color2Y, color2Z))});
        }
    } catch (libconfig::SettingNotFoundException &e) {
        throw Error("Error: Invalid settings in [Textures] part");
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
    _textures.push_back({"basic", std::make_shared<RayTracer::ATexture>()});
    _getTextures(root);
    cnf.camera = _getCamera(root);
    cnf.light = _getLight(root);
    cnf.primitives = _getPrimitives(root);

    return cnf;
}

std::vector<std::shared_ptr<RayTracer::IObject>> RayTracer::Utils::ConfigManager::createObjects(RayTracer::Utils::Config &conf) {
    std::vector<std::shared_ptr<RayTracer::IObject>> objects;

    for (auto &x : conf.primitives) {
        std::cout << "building object [" << x.first->getBuilderName() << "]" << " addr : " << x.first << " ";
        objects.emplace_back(x.first->applyData(x.second).build(&_globalId));
        x.first->reset();
        std::cout << " [OK]" << std::endl;
    }
    return objects;
}

std::unique_ptr<RayTracer::ICamera> RayTracer::Utils::ConfigManager::createCamera(RayTracer::Utils::Config &conf) {
//    std::cout << "Creating camera : " << std::endl;
//    std::cout << "Position : " << conf.camera.position._x << "," << conf.camera.position._y << std::endl;
//    std::cout << "Resolution : " << conf.camera.resolution._x << "," << conf.camera.resolution._y << std::endl;
//    std::cout << "Rotation : " << conf.camera.rotation._x << "," << conf.camera.rotation._y << std::endl;
//    std::cout << "FOV : " << conf.camera.fieldOfView << std::endl;
    std::cout << "building object [camera]";
    auto x = std::make_unique<RayTracer::Camera>(conf.camera.position, conf.camera.resolution._y, conf.camera.resolution._x, conf.camera.fieldOfView);
    std::cout << " [OK]" << std::endl;
    return std::move(x);
}

std::shared_ptr<RayTracer::Ambient> RayTracer::Utils::ConfigManager::createAmbientLight(RayTracer::Utils::Config &conf)
{
    return std::make_shared<RayTracer::Ambient>(Math::Vector3D(conf.light.ambient, conf.light.ambient, conf.light.ambient));
}

std::vector<std::shared_ptr<RayTracer::ILight>> RayTracer::Utils::ConfigManager::createLight(RayTracer::Utils::Config &conf) {
    std::vector<std::shared_ptr<RayTracer::ILight>> points;

    for (auto &point : conf.light.points) {
        std::cout << "building object [light]";
        points.push_back(std::make_shared<RayTracer::Spot>(point.first, point.second));
        std::cout << " [OK]" << std::endl;
    }
    return points;
}
