/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Spot.cpp
*/

#include "Spot.hpp"

namespace RayTracer {
    Spot::Spot() {
        _origin = Math::Vector3D(0, 0, 0);
        _intensity = Math::Vector3D();
    }

    Spot::Spot(const Math::Vector3D &origin, const Math::Vector3D& intensity) {
        _origin = origin;
        _intensity = intensity;
    }
} // RayTracer