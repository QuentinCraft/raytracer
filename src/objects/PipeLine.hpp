/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** pipeLine.hpp
*/

#ifndef RAYTRACER_PIPELINE_HPP
#define RAYTRACER_PIPELINE_HPP

#include "maths/Vector3D.hpp"

namespace RayTracer {
    struct PipeLine {
        Math::Vector3D _position;
        Math::Vector3D _color;
        int id;
        std::string _info;
    };
};

#endif //RAYTRACER_PIPELINE_HPP
