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

#include "../../Vector3D.hpp"

namespace RayTracer::Utils::Config {

    class ConfigManager {
        public:
            // Config Data Structure
            struct Config {
                // Camera Settings
                struct Camera {

                    Math::Vector3D resolution, position, rotation;

                    double fieldOfView = 0.0f;
                } camera;

                // Light Settings
                struct Light {
                    double ambient, diffuse;

                    std::vector<Math::Vector3D> points;
                    std::vector<Math::Vector3D> directional_lights;
                } light;
            };
            // Config Throw Error Class
            class Error : public std::exception {
                public:
                    explicit Error(const std::string err) : _error(err) {};
                    [[nodiscard]] const char *what() const noexcept {
                        return _error.c_str();
                    }
                    std::string _error;
            };

            //
            static Config getConf(const std::string& path);
            static Config::Camera _getCamera(const libconfig::Setting& root);
            static Config::Light _getLight(const libconfig::Setting& root);
    };

} // RayTracer

#endif //RAYTRACER_CONFIGMANAGER_HPP
