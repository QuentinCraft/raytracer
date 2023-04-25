/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Sphere.cpp
*/

#include "Sphere.hpp"

namespace RayTracer {
    Sphere::Sphere() {
        _center = Math::Point3D();
        _radius = 0;
    }

    Sphere::Sphere(const Math::Point3D& center, double radius) {
        _center = center;
        _radius = radius;
    }

    std::optional<Math::Point3D> Sphere::hits(Ray const &ray) const {
        Ray rayBis(ray._origin - _center, ray._direction);
        double a = rayBis._direction.dot(rayBis._direction);
        double b = 2 * rayBis._direction.dot(rayBis._origin);
        double c = rayBis._origin.dot(rayBis._origin) - _radius * _radius;

        double discriminant = (b * b) - (4 * (a * c));

        if (discriminant < 0)
            return std::nullopt;
        else {
            double D = ((-b) - sqrt(discriminant)) / (2 * a);

            double Px = ray._origin._x;
            double Py = ray._origin._y;
            double Pz = ray._origin._z;

            double Vx = ray._direction._x;
            double Vy = ray._direction._y;
            double Vz = ray._direction._z;

            double vNorm = sqrt(Vx * Vx + Vy * Vy + Vz * Vz);

            double Qx = Px + (D/vNorm) * Vx;
            double Qy = Py + (D/vNorm) * Vy;
            double Qz = Pz + (D/vNorm) * Vz;

            return Math::Point3D(Qx, Qy, Qz);
        }
    }

    Math::Vector3D Sphere::normal(const Math::Point3D &point) const {
        return Math::Vector3D((_center - point).toVector());
    }


} // RayTracer
