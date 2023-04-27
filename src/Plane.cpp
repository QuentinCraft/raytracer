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
        if (std::abs(denominator) < 1e-6) {
            // Ray is parallel to the plane, no intersection
            return std::nullopt;
        } // ray is not parallel to plane, compute intersection point
        double t = (_point - ray._origin).dot(_normal) / denominator;
        if (t < 0) {
            // Plane is behind the ray origin, no intersection
            return std::nullopt;
        }
        return ray._origin + ray._direction * t;
    }

    Math::Vector3D Plane::normal(const Math::Vector3D &point) const {
        return _normal;
    }

    bool Plane::operator==(const Plane &plane) const {
        return _point == plane._point && _normal == plane._normal;
    }


} // RayTracer