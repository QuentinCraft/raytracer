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
        Math::Vector3D rayOrigin = ray._origin - _origin;
        PipeLine pipe;
        pipe._info = "Cone";

        double r2 = _radius * _radius;
        double h2 = _height * _height;

        double a = ray._direction._x * ray._direction._x + ray._direction._z * ray._direction._z - r2 / h2 * ray._direction._y * ray._direction._y;
        double b = 2 * (rayOrigin._x * ray._direction._x + rayOrigin._z * ray._direction._z - r2 / h2 * rayOrigin._y * ray._direction._y);
        double c = rayOrigin._x * rayOrigin._x + rayOrigin._z * rayOrigin._z - r2 / h2 * rayOrigin._y * rayOrigin._y;

        double discriminant = b * b - 4 * a * c;

        if (Math::Utils::inf(discriminant, 0))
            return std::nullopt;

        double t1 = (-b - sqrt(discriminant)) / (2 * a);
        double t2 = (-b + sqrt(discriminant)) / (2 * a);

        double y1 = ray._origin._y + t1 * ray._direction._y;
        double y2 = ray._origin._y + t2 * ray._direction._y;

        if ((y1 < _origin._y || y1 > _origin._y + _height) && (y2 < _origin._y || y2 > _origin._y + _height))
            return std::nullopt;

        double t = t1;
        if (y1 < _origin._y || y1 > _origin._y + _height) {
            pipe._info = "TopCone";
            t = t2;
        } else if (y2 >= _origin._y && y2 <= _origin._y + _height && y2 < y1) {
            t = t2;
        }

        Math::Vector3D hitPoint = ray._origin + ray._direction * t;
        if (hitPoint._y < _origin._y || hitPoint._y > _origin._y + _height)
            return std::nullopt;

        pipe._position = hitPoint;
        pipe._color = _color;
        pipe.id = _id;
        return pipe;
    }

    Math::Vector3D Cone::normal(const PipeLine &pipe) const {
        Math::Vector3D hitPoint = pipe._position - _origin;
        double dist = sqrt(hitPoint._x * hitPoint._x + hitPoint._z * hitPoint._z);
        double cosTheta = dist / sqrt(dist * dist + _height * _height);
        double sinTheta = _height / sqrt(dist * dist + _height * _height);
        if (pipe._info == "TopCone") {
            std::cout << "Top hitted" << std::endl;
            return {0, 1, 0};
        } else if (pipe._info == "Cone") {
            if (Math::Utils::sup(hitPoint._y, _origin._y + _height)) {
                return {0, sinTheta, 0};
            } else if (Math::Utils::inf(hitPoint._y, _origin._y)) {
                return {0, -sinTheta, 0};
            } else {
                return Math::Vector3D(hitPoint._x * cosTheta, sinTheta, hitPoint._z * cosTheta).normalized();
            }
        }
        return Math::Vector3D();
    }

    bool Cone::operator==(const Cone &cone) const {
        return _origin == cone._origin && _radius == cone._radius && _color == cone._color;
    }

} // RayTracer
