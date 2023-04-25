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
        _width = 1920;
        _height = 1080;
        _fov = 90;
    }

    Camera::Camera(const Math::Point3D &origin, double width, double height, double fov) {
        _origin = origin;
        _width = width;
        _height = height;
        _fov = fov;
    }

    Ray Camera::ray(double u, double v) const {
        Math::Vector3D direction(u * (_fov / 90),
                                 v * (_fov / 90),
                                 1);
        Ray ray(_origin, direction);
        return ray;
    }
} // RayTracer