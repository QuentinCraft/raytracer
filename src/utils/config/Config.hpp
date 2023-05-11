/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Config.hpp
*/
#ifndef CONFIG_HPP_
#define CONFIG_HPP_
#include <iostream>
#include <vector>
#include "maths/Vector3D.hpp"
#include "utils/builder/IBuilder.hpp"
#include "utils/config/data/IData.hpp"

namespace RayTracer::Utils {

    // Config Data Structure
    struct Config {
        // Camera Settings
        struct Camera {

            Math::Vector3D resolution, position, rotation;

            double fieldOfView = 0.0f;
            int superSampling = 0;
            int recursionDepth = 0;
        } camera;

        // Light Settings
        struct Light {
            double ambient, diffuse;

            std::vector <std::pair<Math::Vector3D, Math::Vector3D>> points;
            std::vector <Math::Vector3D> directional_lights;
        } light;

        std::vector<std::pair<std::shared_ptr<IBuilder>, std::unique_ptr<IData>>> primitives;
        std::vector<std::string> includes;
    };

}

#endif /*CONFIG_HPP_*/