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

namespace RayTracer::Utils {

    class ConfigManager {
        public:
            static Config getConf(const std::string& path);
            static Config::Camera _getCamera(const libconfig::Setting& root);
            static Config::Light _getLight(const libconfig::Setting& root);
            static void _getSphere(const libconfig::Setting& primitive);
            static void _getPlane(const libconfig::Setting& primitive);
            static void _getPrimitives(const libconfig::Setting &root);
    };

} // RayTracer

#endif //RAYTRACER_CONFIGMANAGER_HPP
