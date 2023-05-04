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

namespace RayTracer::Utils {

    class ConfigManager {
        public:
            ConfigManager(const std::string &plugins) {
                _builder = std::make_unique<ObjectFactory>(plugins);
            };
            ~ConfigManager() = default;
            Config getConf(const std::string& path);
            std::unique_ptr<ICamera> createCamera(Config &conf);
            std::unique_ptr<ILight> createLight(Config &conf);
            std::vector<std::unique_ptr<IObject>> createObjects(Config &conf);
        private:
            Config::Camera _getCamera(const libconfig::Setting& root);
            Config::Light _getLight(const libconfig::Setting& root);
            void _getSphere(const libconfig::Setting& primitive);
            void _getPlane(const libconfig::Setting& primitive);
            void _getPrimitives(const libconfig::Setting &root);
            //
            std::vector<std::pair<IBuilder *, std::unique_ptr<IData>>> _primitives;
            std::unique_ptr<ObjectFactory> _builder;
    };

} // RayTracer

#endif //RAYTRACER_CONFIGMANAGER_HPP
