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
        _color = Math::Vector3D(255, 255, 255);
    }

    Sphere::Sphere(const Math::Point3D& center, double radius) {
        _center = center;
        _radius = radius;
        _color = color;
    }

    std::optional<Math::Vector3D> Sphere::hits(Ray const &ray) const {
        Ray rayBis(ray._origin - _center, ray._direction);
        double a = rayBis._direction.dot(rayBis._direction);
        double b = 2 * rayBis._origin.dot(rayBis._direction);
        double c = rayBis._origin.dot(rayBis._origin) - (_radius * _radius);

        double discriminant = b * b - 4.0 * a * c;

        if (discriminant < 0)
            return std::nullopt;
        double D = (-b - sqrt(discriminant)) / (2 * a);
        return ray._origin + ray._direction * D;
    }

    Math::Vector3D Sphere::normal(const Math::Point3D &point) const {
        return Math::Vector3D((_center - point).toVector());
    }

    bool Sphere::operator==(const Sphere &sphere) const {
        return _center == sphere._center && _radius == sphere._radius && _color == sphere._color;
    }


} // RayTracer
