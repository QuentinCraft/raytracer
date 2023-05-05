/*
** EPITECH PROJECT, 2023
** B-OOP-400-STG-4-1-raytracer-quentin.erdinger
** File description:
** Plane
*/

#include "Plane.hpp"
#include "objects/PipeLine.hpp"

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
            if (Math::Utils::equal(denominator, 0))
                denominator = 0.000000001;
            double D = p0l0.dot(_normal) / denominator;
            if (Math::Utils::sup(D, 0)) {
                PipeLine pipe;
                pipe.object = std::make_shared<Plane>(*this);
                pipe._position = ray._origin + ray._direction * D;
                double scale = 0.2;
                char ax;
                char ay;
                char az;
                if (Math::Utils::inf(pipe._position._x, 0))
                    ax = fmodf(std::abs(pipe._position._x) * scale, 1) < 0.5;
                else
                    ax = fmodf(std::abs(pipe._position._x) * scale, 1) > 0.5;

                if (Math::Utils::inf(pipe._position._y, 0))
                    ay = fmodf(std::abs(pipe._position._y) * scale, 1) < 0.5;
                else
                    ay = fmodf(std::abs(pipe._position._y) * scale, 1) > 0.5;

                if (Math::Utils::inf(pipe._position._z, 0))
                    az = fmodf(std::abs(pipe._position._z) * scale, 1) < 0.5;
                else
                    az = fmodf(std::abs(pipe._position._z) * scale, 1) > 0.5;


                float pattern = (ax) ^ (ay) ^ (az);
                if (pattern)
                    pipe._color = {0.9 - _color._x, 0.9 - _color._y, 0.9 - _color._z};
                else
                    pipe._color = _color;
                pipe.id = _id;
                return pipe;
            }
        }
        return std::nullopt;
    }

    Math::Vector3D Plane::normal(const PipeLine &pipe) const {
        return _normal * -1;
    }

    bool Plane::operator==(const Plane &plane) const {
        return _origin == plane._origin && _normal == plane._normal;
    }


} // RayTracer