/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Camera3D.cpp
*/

#include "Camera.hpp"

namespace RayTracer {
    Camera::Camera() {
        _origin = Math::Point3D(0, 0, 0);
    }

    Ray Camera::ray(double x, double y) const {
        Math::Point3D origin = _screen.pointAt(x, y);
        Math::Vector3D direction(0, 0, 1);
        Ray ray(origin, direction);
        return ray;
    }
} // RayTracer