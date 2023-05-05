/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** pipeLine.hpp
*/

#ifndef RAYTRACER_PIPELINE_HPP
#define RAYTRACER_PIPELINE_HPP

#include "maths/Vector3D.hpp"
#include "objects/AObject.hpp"

#include <memory>

namespace RayTracer {
    struct PipeLine {
        Math::Vector3D _position;
        Math::Vector3D _color;
        std::string _info;
        std::shared_ptr<AObject> object;
        int id;
    };
};

#endif //RAYTRACER_PIPELINE_HPP
