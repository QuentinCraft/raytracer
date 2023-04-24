/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Ray.cpp
*/

#include "Ray.hpp"

namespace RayTracer {
    Ray::Ray() {
        _origin = Math::Point3D();
        _direction = Math::Vector3D();
    }

    Ray::Ray(const Math::Point3D &origin, const Math::Vector3D &direction) {
        _origin = origin;
        _direction = direction;
    }

    Ray::Ray(const Ray &ray) {
        _origin = ray._origin;
        _direction = ray._direction;
    }
} // RayTracer