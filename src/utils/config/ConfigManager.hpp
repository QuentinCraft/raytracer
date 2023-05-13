/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ConfigManager.hpp
*/

#ifndef RAYTRACER_CONFIGMANAGER_HPP
#define RAYTRACER_CONFIGMANAGER_HPP

#include <iostream>
#include <exception>

#include <map>
#include <vector>

#include <libconfig.h++>

#include "maths/Vector3D.hpp"
#include "Config.hpp"
#include "utils/Error.hpp"

#include "utils/config/data/IData.hpp"
#include "utils/builder/IBuilder.hpp"
#include "utils/factory/ObjectFactory.hpp"
#include "cameras/ICamera.hpp"
#include "utils/ObjFile/ObjFile.hpp"

namespace RayTracer::Utils {

    class ConfigManager {
        public:
            ConfigManager(const std::string &plugins) {
                _builder = std::make_unique<ObjectFactory>(plugins);
                _objFileParser = std::make_unique<RayTracer::ObjFile>();
                _globalId = 0;
                _lastConfig = "";
            };
            ~ConfigManager() {
                _textures.clear();
                std::cout << "ConfigManager destructor" << std::endl;
            };
            Config getConf(const std::string& path, bool includeConfig = false);
            std::pair<std::string, std::string> getConfigFile();
            std::unique_ptr<ICamera> createCamera(Config &conf);
            std::vector<std::shared_ptr<ILight>> createLight(Config &conf);
            std::vector<std::shared_ptr<IObject>> createObjects(Config &conf);
            std::shared_ptr<Ambient> createAmbientLight(Config &conf);
        private:
            Config::Camera _getCamera(const libconfig::Setting& root);
            Config::Light _getLight(const libconfig::Setting& root);
            std::vector<std::string> _getInclude(const libconfig::Setting &root);
            void _getSphere(const libconfig::Setting& primitive);
            void _getPlane(const libconfig::Setting& primitive);
            void _getCylinder(const libconfig::Setting& primitive);
            void _getUnlimitedCylinder(const libconfig::Setting& primitive);
            void _getCone(const libconfig::Setting& primitive);
            void _getObjFile(const libconfig::Setting& primitive);
            void _getTextures(const libconfig::Setting& root);
            std::vector<std::pair<std::shared_ptr<RayTracer::IBuilder>, std::unique_ptr<RayTracer::Utils::IData>>> _getPrimitives(const libconfig::Setting &root);
            //
            std::vector<std::pair<std::shared_ptr<IBuilder>, std::unique_ptr<IData>>> _primitives;
            int _globalId;
            std::vector<std::pair<std::string, std::shared_ptr<ITexture>>> _textures;
            std::unique_ptr<ObjectFactory> _builder;
            std::unique_ptr<RayTracer::IObjFile> _objFileParser;
            std::string _lastConfig;
            std::string _lastConfigPath;
    };

} // RayTracer

#endif //RAYTRACER_CONFIGMANAGER_HPP
