/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Sphere.cpp
*/

#include "Sphere.hpp"

namespace RayTracer {
    Sphere::Sphere() {
        _id = 0;
        _origin = Math::Vector3D();
        _color = Math::Vector3D();
        _rotation = Math::Vector3D();
        _scale = Math::Vector3D();
        _radius = 0;
    }

    Sphere::Sphere(const Math::Vector3D& center, double radius, const Math::Vector3D& color) {
        _id = 0;
        _origin = center;
        _radius = radius;
        _color = color;
        _rotation = Math::Vector3D();
        _scale = Math::Vector3D();
    }

    std::optional<PipeLine> Sphere::hits(Ray const &ray) const {
        Ray rayBis(ray._origin - _origin, ray._direction.normalized());
        double a = rayBis._direction.dot(rayBis._direction);
        double b = 2 * rayBis._origin.dot(rayBis._direction);
        double c = rayBis._origin.dot(rayBis._origin) - (_radius * _radius);

        double discriminant = b * b - 4.0 * a * c;

        if (discriminant < 0)
            return std::nullopt;
        double D = (-b - sqrt(discriminant)) / (2 * a);
        PipeLine pipe;
        pipe._position = ray._origin + ray._direction.normalized() * D;
        pipe.id = _id;
        pipe._color = _color;
        return pipe;
    }

    Math::Vector3D Sphere::normal(const Math::Vector3D &point) const {
        return Math::Vector3D(_origin - point).normalized();
    }

    bool Sphere::operator==(const Sphere &sphere) const {
        return _origin == sphere._origin && _radius == sphere._radius && _color == sphere._color;
    }


} // RayTracer
