/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Cylinder.cpp
*/

#include "Cylinder.hpp"
#include "objects/PipeLine.hpp"

namespace RayTracer {
    Cylinder::Cylinder() {
        _origin = Math::Vector3D();
        _radius = 0;
        _id = globalId++;
        _length = 0;
    }

    Cylinder::Cylinder(const Math::Vector3D& center, double radius, double length, const Math::Vector3D& color) {
        _origin = center;
        _radius = radius;
        _id = globalId++;
        _length = length;
    }

    std::optional<PipeLine> Cylinder::hits(Ray const& ray) const {
        Math::Vector3D rayOrigin = ray._origin - _origin;
        double a = ray._direction._x * ray._direction._x + ray._direction._z * ray._direction._z;
        double b = 2 * (rayOrigin._x * ray._direction._x + rayOrigin._z * ray._direction._z);
        double c = rayOrigin._x * rayOrigin._x + rayOrigin._z * rayOrigin._z - (_radius * _radius);

        double discriminant = b * b - 4.0 * a * c;

        double d1 = (-b - sqrt(discriminant)) / (2 * a);
        double t = d1;


        Math::Vector3D hitPoint = ray._origin + ray._direction * t;

        if (
            (Math::Utils::sup(hitPoint._y, _origin._y - _length / 2.0) || Math::Utils::equal(hitPoint._y, _origin._y - _length / 2.0)) &&
            (Math::Utils::inf(hitPoint._y, _origin._y + _length / 2.0) || Math::Utils::equal(hitPoint._y, _origin._y + _length / 2.0))) {
            if (Math::Utils::inf(discriminant, 0))
                return std::nullopt;
            if (Math::Utils::inf(t, 0))
                return std::nullopt;
            PipeLine pipe;
            pipe._object = std::make_shared<Cylinder>(*this);
            pipe._position = hitPoint;
            pipe._id = _id;
            pipe._info = "Cylinder";
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
            pipe._object = std::make_shared<Cylinder>(*this);
            pipe._position = hitPoint_top;
            pipe._id = _id;
            pipe._info = "TopCylinder";
            return pipe;
        }

        if (Math::Utils::inf(dist_bot, _radius) || Math::Utils::equal(dist_bot, _radius)) {
            PipeLine pipe;
            pipe._object = std::make_shared<Cylinder>(*this);
            pipe._position = hitPoint_bot;
            pipe._id = _id;
            pipe._info = "BotCylinder";
            return pipe;
        }

        return std::nullopt;
    }

    Math::Vector3D Cylinder::normal(const PipeLine &pipe) const {
        if (pipe._info == "TopCylinder" ) {
            return {0, -1, 0};
        } else if (pipe._info == "BotCylinder") {
            return {0, 1, 0};
        } else if (pipe._info == "Cylinder") {
            return {(_origin - pipe._position)._x, 0, (_origin - pipe._position)._z};
        }
        return Math::Vector3D();
    }

    bool Cylinder::operator==(const Cylinder &cylinder) const {
        return _origin == cylinder._origin && _radius == cylinder._radius;
    }

} // RayTracer
