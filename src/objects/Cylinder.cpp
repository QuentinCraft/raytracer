/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Cylinder.cpp
*/

#include "Cylinder.hpp"

namespace RayTracer {
    Cylinder::Cylinder() {
        _origin = Math::Vector3D();
        _radius = 0;
        _length = 0;
        _color = Math::Vector3D(255, 255, 255);
    }

    Cylinder::Cylinder(const Math::Vector3D& center, double radius, double length, const Math::Vector3D& color) {
        _origin = center;
        _radius = radius;
        _length = length;
        _color = color;
    }

    std::optional<PipeLine> Cylinder::hits(Ray const& ray) const {
        Math::Vector3D rayOrigin = ray._origin - _origin;
        double a = ray._direction._x * ray._direction._x + ray._direction._z * ray._direction._z;
        double b = 2 * (rayOrigin._x * ray._direction._x + rayOrigin._z * ray._direction._z);
        double c = rayOrigin._x * rayOrigin._x + rayOrigin._z * rayOrigin._z - (_radius * _radius);

        double discriminant = b * b - 4.0 * a * c;
        if (Math::Utils::inf(discriminant, 0))
            return std::nullopt;

        double d1 = (-b - sqrt(discriminant)) / (2 * a);
        double d2 = (-b + sqrt(discriminant)) / (2 * a);
        double t = std::min(d1, d2);

        Math::Vector3D hitPoint = ray._origin + ray._direction * t;
        double dist = sqrt(hitPoint._x * hitPoint._x + hitPoint._z * hitPoint._z);

        if ((Math::Utils::inf(dist, _radius) || Math::Utils::equal(dist, _radius)) &&
            (Math::Utils::sup(hitPoint._y, _origin._y - _length / 2.0) || Math::Utils::equal(hitPoint._y, _origin._y - _length / 2.0)) &&
            (Math::Utils::inf(hitPoint._y, _origin._y + _length / 2.0) || Math::Utils::equal(hitPoint._y, _origin._y + _length / 2.0))) {
            PipeLine pipe;
            pipe._position = hitPoint;
            pipe._color = _color;
            pipe.id = _id;
            return pipe;
        }

        if (Math::Utils::equal(ray._direction._y, 0))
            return std::nullopt;

        double t_top = (_origin._y + _length / 2.0 - ray._origin._y) / ray._direction._y;
        if (t_top <= 0)
            return std::nullopt;

        double t_bot = (_origin._y - _length / 2.0 - ray._origin._y) / ray._direction._y;
        if (t_bot <= 0)
            return std::nullopt;


        Math::Vector3D hitPoint_top = ray._origin + ray._direction * t_top;
        double dist_top = sqrt((hitPoint_top._x - _origin._x) * (hitPoint_top._x - _origin._x) + (hitPoint_top._z - _origin._z) * (hitPoint_top._z - _origin._z));

        Math::Vector3D hitPoint_bot = ray._origin + ray._direction * t_bot;
        double dist_bot = sqrt((hitPoint_bot._x - _origin._x) * (hitPoint_bot._x - _origin._x) + (hitPoint_bot._z - _origin._z) * (hitPoint_bot._z - _origin._z));

        if (Math::Utils::inf(dist_top, _radius) || Math::Utils::equal(dist_top, _radius)) {
            PipeLine pipe;
            pipe._position = hitPoint_top;
            pipe._color = _color;
            pipe.id = _id;
            return pipe;
        }

        if (Math::Utils::inf(dist_bot, _radius) || Math::Utils::equal(dist_bot, _radius)) {
            PipeLine pipe;
            pipe._position = hitPoint_bot;
            pipe._color = _color;
            pipe.id = _id;
            return pipe;
        }

        return std::nullopt;
    }

    Math::Vector3D Cylinder::normal(const Math::Vector3D &point) const {
        return Math::Vector3D((_origin - point));
    }

    bool Cylinder::operator==(const Cylinder &cylinder) const {
        return _origin == cylinder._origin && _radius == cylinder._radius && _color == cylinder._color;
    }

} // RayTracer
