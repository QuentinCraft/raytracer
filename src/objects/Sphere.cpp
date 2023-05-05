/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Sphere.cpp
*/

#include "Sphere.hpp"
#include "objects/PipeLine.hpp"

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

        if (Math::Utils::inf(discriminant, 0))
            return std::nullopt;
        double D = (-b - sqrt(discriminant)) / (2 * a);
        if (Math::Utils::inf(D, 0))
            return std::nullopt;
        PipeLine pipe;
        pipe._position = ray._origin + rayBis._direction * D;
        pipe.id = _id;
//        double scale = 0.2;
//        char ax;
//        char ay;
//        char az;
//        if (Math::Utils::inf(pipe._position._x, 0))
//            ax = fmodf(std::abs(pipe._position._x) * scale, 1) < 0.5;
//        else
//            ax = fmodf(std::abs(pipe._position._x) * scale, 1) > 0.5;
//
//        if (Math::Utils::inf(pipe._position._y, 0))
//            ay = fmodf(std::abs(pipe._position._y) * scale, 1) < 0.5;
//        else
//            ay = fmodf(std::abs(pipe._position._y) * scale, 1) > 0.5;
//
//        if (Math::Utils::inf(pipe._position._z, 0))
//            az = fmodf(std::abs(pipe._position._z) * scale, 1) < 0.5;
//        else
//            az = fmodf(std::abs(pipe._position._z) * scale, 1) > 0.5;
//
//
//        float pattern = (ax) ^ (ay) ^ (az);
//        if (pattern)
//            pipe._color = {0.9 - _color._x, 0.9 - _color._y, 0.9 - _color._z};
//        else
            pipe._color = _color;
        pipe.object = std::make_shared<Sphere>(*this);
        return pipe;
    }

    Math::Vector3D Sphere::normal(const PipeLine &pipe) const {
        return Math::Vector3D(_origin - pipe._position).normalized();
    }

    bool Sphere::operator==(const Sphere &sphere) const {
        return _origin == sphere._origin && _radius == sphere._radius && _color == sphere._color;
    }

} // RayTracer
