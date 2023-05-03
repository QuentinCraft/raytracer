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
        Math::Vector3D rayDirection = ray._direction.normalized();

        //equation for the open angle of a cone 2 * tan^-1 (r/h)
        double angle = 2.0 * std::atan(_radius / _height);
        double cosAngle2 = std::cos(angle) * std::cos(angle);

        double a = rayDirection._x * rayDirection._x + rayDirection._z * rayDirection._z - cosAngle2 * rayDirection._y * rayDirection._y;
        double b = 2.0 * (rayOrigin._x * rayDirection._x + rayOrigin._z * rayDirection._z - cosAngle2 * rayOrigin._y * rayDirection._y);
        double c = rayOrigin._x * rayOrigin._x + rayOrigin._z * rayOrigin._z - cosAngle2 * rayOrigin._y * rayOrigin._y;

        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {
            return std::nullopt;
        }

        double t1 = (-b - sqrt(discriminant)) / (2 * a);
        double t2 = (-b + sqrt(discriminant)) / (2 * a);

        double t = std::min(t1, t2);

        Math::Vector3D hitPoint = ray._origin + rayDirection * t;
        if (hitPoint._y < _origin._y) {
            return std::nullopt;
        }
        if  ((Math::Utils::sup(hitPoint._y, _origin._y - _height / 2.0) || Math::Utils::equal(hitPoint._y, _origin._y - _height / 2.0)) &&
            (Math::Utils::inf(hitPoint._y, _origin._y + _height / 2.0) || Math::Utils::equal(hitPoint._y, _origin._y + _height / 2.0))) {
            // if (Math::Utils::inf(discriminant, 0))
            //     return std::nullopt;
            if (Math::Utils::inf(t, 0))
                return std::nullopt;
            PipeLine pipe;
            pipe._position = hitPoint;
            pipe._color = _color;
            pipe.id = _id;
            pipe._info = "Cone";
            return pipe;
        }

        double t_top = (_origin._y + _height / 2.0 - ray._origin._y) / ray._direction._y;
        if (t_top <= 0)
            return std::nullopt;

        Math::Vector3D hitPoint_top = ray._origin + ray._direction * t_top;
        //calculate the distance between the hitpoint and the base of the cone
        double dist_top = sqrt((hitPoint_top._x - _origin._x) * (hitPoint_top._x - _origin._x) + (hitPoint_top._z - _origin._z) * (hitPoint_top._z - _origin._z));

        if (Math::Utils::inf(dist_top, _radius /  2 * 5 * std::atan(cosAngle2)) || Math::Utils::equal(dist_top, _radius /  2 * 5 * std::atan(cosAngle2))) {
            PipeLine pipe;
            pipe._position = hitPoint_top;
            pipe._color = _color;
            pipe.id = _id;
            pipe._info = "TopCone";
            return pipe;
        }

        double distanceToOrigin = sqrt(hitPoint._x * hitPoint._x + hitPoint._z * hitPoint._z);
        double coneRadiusAtY = _radius * (1 - hitPoint._y / _height);
        if (distanceToOrigin > coneRadiusAtY) {
            return std::nullopt;
        }

        return std::nullopt;
    }


    Math::Vector3D Cone::normal(const PipeLine &pipe) const {
        if (pipe._info == "TopCone")
            return Math::Vector3D(0, -1, 0);
        else if (pipe._info == "Cone")
            return  Math::Vector3D((_origin - pipe._position)._x, 0, (_origin - pipe._position)._z);
        return Math::Vector3D();
    }

    bool Cone::operator==(const Cone &cone) const {
        return _origin == cone._origin && _radius == cone._radius && _color == cone._color;
    }

} // RayTracer
