/*
** EPITECH PROJECT, 2023
** B-OOP-400-STG-4-1-raytracer-quentin.erdinger
** File description:
** Cone
*/

#include "Cone.hpp"

namespace RayTracer {
    Cone::Cone() {
        _origin = Math::Vector3D();
        _radius = 0;
        _height = 0;
        _color = Math::Vector3D(255, 255, 255);
    }

    Cone::Cone(const Math::Vector3D& center, double radius, double height, const Math::Vector3D& color) {
        _origin = center;
        _radius = radius;
        _height = height;
        _color = color;
    }

    std::optional<PipeLine> Cone::hits(Ray const& ray) const {


        double radiusBis = _radius;
        if (radiusBis > _height)
            radiusBis = _height;
        Math::Vector3D rayOrigin = ray._origin - _origin;
        //equation for the open angle of a cone 2 * tan^-1 (r/h)
        double angle = 2.0 * std::atan((radiusBis / (radiusBis < _height ? 1.87 : 1)) / _height);
        double cosAngle2 = 1 - std::cos(angle) * std::cos(angle);

        double a = ray._direction._x * ray._direction._x + ray._direction._z * ray._direction._z - cosAngle2 * ray._direction._y * ray._direction._y;
        double b = 2.0 * (rayOrigin._x * ray._direction._x + rayOrigin._z * ray._direction._z - cosAngle2 * rayOrigin._y * ray._direction._y);
        double c = rayOrigin._x * rayOrigin._x + rayOrigin._z * rayOrigin._z - cosAngle2 * rayOrigin._y * rayOrigin._y;

        double discriminant = b * b - 4 * a * c;

        double t1 = (-b - sqrt(discriminant)) / (2 * a);
        double t2 = (-b + sqrt(discriminant)) / (2 * a);

        double t = t1;

        Math::Vector3D hitPoint = ray._origin + ray._direction * t;
        if (hitPoint._y < _origin._y) {
            return std::nullopt;
        }

        if  ((Math::Utils::sup(hitPoint._y, _origin._y - _height) || Math::Utils::equal(hitPoint._y, _origin._y - _height)) &&
            (Math::Utils::inf(hitPoint._y, _origin._y + _height) || Math::Utils::equal(hitPoint._y, _origin._y + _height))) {
            if (Math::Utils::inf(discriminant, 0))
                return std::nullopt;
            if (Math::Utils::inf(t, 0))
                return std::nullopt;
            PipeLine pipe;
            pipe._position = hitPoint;
            pipe._color = _color;
            pipe.id = _id;
            pipe._info = "Cone";
            return pipe;
        }

        double t_top = (_origin._y + _height - ray._origin._y) / ray._direction._y;
        if (t_top <= 0)
            return std::nullopt;

        Math::Vector3D hitPoint_top = ray._origin + ray._direction * t_top;

        double dist_top = sqrt((hitPoint_top._x - _origin._x) * (hitPoint_top._x - _origin._x) + (hitPoint_top._z - _origin._z) * (hitPoint_top._z - _origin._z));

        if (Math::Utils::inf(dist_top, (radiusBis > _height ? radiusBis / 2 : radiusBis)) || Math::Utils::equal(dist_top, (radiusBis > _height ? radiusBis / 2 : radiusBis))) {
            PipeLine pipe;
            pipe._position = hitPoint_top;
            pipe._color = _color;
            pipe.id = _id;
            pipe._info = "TopCone";
            return pipe;
        }

        return std::nullopt;
    }

    Math::Vector3D Cone::normal(const PipeLine &pipe) const {
        if (pipe._info == "TopCone")
            return Math::Vector3D(0, -1, 0);
        else if (pipe._info == "Cone")
            return Math::Vector3D((_origin - pipe._position)._x, 0, (_origin - pipe._position)._z);
        return Math::Vector3D();
    }

    bool Cone::operator==(const Cone &cone) const {
        return _origin == cone._origin && _radius == cone._radius && _color == cone._color;
    }

} // RayTracer
