/*
** EPITECH PROJECT, 2023
** B-OOP-400-STG-4-1-raytracer-quentin.erdinger
** File description:
** Plane
*/

#include "Plane.hpp"

namespace RayTracer {
    Plane::Plane() {
        _point = Math::Vector3D();
        _normal = Math::Vector3D();
    }

    Plane::Plane(const Math::Vector3D& point, const Math::Vector3D& normal) {
        _point = point;
        _normal = normal;
    }

    std::optional<Math::Vector3D> Plane::hits(Ray const &ray) const {
        double denominator = ray._direction.dot(_normal);
        if (denominator < 1e-6) {
            Math::Vector3D p0l0 = _point - ray._origin;
            double D = p0l0.dot(_normal) / denominator;
            return ray._origin + ray._direction * D;
        }
        return std::nullopt;


//        double t = (_point - ray._origin).dot(_normal) / denominator;
//        if (t < 0) {
//            // Plane is behind the ray origin, no intersection
//            return std::nullopt;
//        }
//        return ray._origin + ray._direction * t;
    }

    Math::Vector3D Plane::normal(const Math::Vector3D &point) const {
        return _normal;
    }

    bool Plane::operator==(const Plane &plane) const {
        return _point == plane._point && _normal == plane._normal;
    }


} // RayTracer