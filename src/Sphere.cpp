/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Sphere.cpp
*/

#include "Sphere.hpp"

namespace RayTracer {
    Sphere::Sphere() {
        _center = Math::Point3D();
        _radius = 0;
    }

    Sphere::Sphere(const Math::Point3D& center, double radius) {
        _center = center;
        _radius = radius;
    }

    bool Sphere::hits(Ray const &ray) const {
        Ray rayBis(ray._origin - _center, ray._direction);
        double a = rayBis._direction.dot(rayBis._direction);
        double b = 2 * rayBis._direction.dot(rayBis._origin);
        double c = rayBis._origin.dot(rayBis._origin) - _radius * _radius;

        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0)
            return false;
        else
            return true;
    }
} // RayTracer
