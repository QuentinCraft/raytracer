/*
** EPITECH PROJECT, 2023
** B-OOP-400-STG-4-1-raytracer-quentin.erdinger
** File description:
** Plane
*/

#include "Plane.hpp"

namespace RayTracer {
    Plane::Plane() {
        _origin = Math::Vector3D();
        _normal = Math::Vector3D().normalized();
        _color = Math::Vector3D(255, 255, 255);
        _id = -1;
    }

    Plane::Plane(const Math::Vector3D& point, const Math::Vector3D& normal) {
        _color = Math::Vector3D(255, 255, 255);
        _origin = point;
        _normal = normal.normalized();
        _id = -1;
    }

    Plane::Plane(const Math::Vector3D &point, const Math::Vector3D &normal,
                 const Math::Vector3D &color) {
        _origin = point;
        _normal = normal.normalized();
        _color = color;
        _id = -1;
    }

    std::optional<PipeLine> Plane::hits(Ray const &ray) const {
        Ray rayBis(ray._origin - _origin, ray._direction.normalized());

        double denominator = rayBis._direction.dot(_normal);
        if (denominator < 1e-6) {
            Math::Vector3D p0l0 = _origin - rayBis._origin;
            double D = p0l0.dot(_normal) / denominator;
            if (Math::Utils::sup(D, 0)) {
                PipeLine pipe;
                pipe._position = ray._origin + ray._direction * D;
                pipe._color = _color;
                pipe.id = _id;
                return pipe;
            }
        }
        return std::nullopt;
    }

    Math::Vector3D Plane::normal(const Math::Vector3D &point) const {
        return _normal * -1;
    }

    bool Plane::operator==(const Plane &plane) const {
        return _origin == plane._origin && _normal == plane._normal;
    }


} // RayTracer