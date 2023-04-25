/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Spot.cpp
*/

#include "Spot.hpp"

namespace RayTracer {
    Spot::Spot() {
        _origin = Math::Point3D(0, 0, 0);
        _intensity = 0;
    }

    Spot::Spot(const Math::Point3D &origin, double intensity) {
        _origin = origin;
        _intensity = intensity;
    }
} // RayTracer