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
}


void Plane::getCoefficients(double &a, double &b, double &c, double &d) const {
    a = _normal._x;
    b = _normal._y;
    c = _normal._z;
    d = -(_point.dot(_normal));
}

Math::Vector3D Plane::normal(const Math::Vector3D &point) const {
    double a, b, c, d;
    getCoefficients(a, b, c, d);
    Math::Vector3D normal(a, b, c);
    double length = std::sqrt(normal._x * normal._x + normal._y * normal._y + normal._z * normal._z);
    normal._x /= length;
    normal._y /= length;
    normal._z /= length;
    return normal;
}



//        double t = (_point - ray._origin).dot(_normal) / denominator;
//        if (t < 0) {
//            // Plane is behind the ray origin, no intersection
//            return std::nullopt;
//        }
//        return ray._origin + ray._direction * t;
    // }

//function that calculate the normal of a plan 


    bool Plane::operator==(const Plane &plane) const {
        return _point == plane._point && _normal == plane._normal;
    }


} // RayTracer