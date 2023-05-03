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

namespace RayTracer::Utils {

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

            std::vector <Math::Vector3D> points;
            std::vector <Math::Vector3D> directional_lights;
        } light;
    };

}

#endif /*CONFIG_HPP_*/