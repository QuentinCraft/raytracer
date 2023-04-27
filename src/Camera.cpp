/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Camera3D.cpp
*/
#include "Camera.hpp"

namespace RayTracer {
    Camera::Camera() {
        _origin = Math::Vector3D (0, 0, 0);
        _width = 800;
        _height = 800;
        _fov = 90;
    }

    Camera::Camera(const Math::Vector3D &origin, double width, double height, double fov) {
        _origin = origin;
        _width = width;
        _height = height;
        _fov = fov;
    }

    Ray Camera::ray(double u, double v) const {
        Math::Vector3D direction(u * (_fov / 90),
                                 -v * (_fov / 90),
                                 1);
        Ray ray(_origin, direction);
        return ray;
    }

    Math::Vector3D Camera::pointAt(double u, double v, std::vector<RayTracer::Sphere> &spheres, const RayTracer::Spot &spot) const {

        RayTracer::Ray r = ray(u, v);
        Math::Vector3D savedHitPoint;
        RayTracer::Sphere savedSphere;
        int i = 0;

        for (auto &sphere : spheres) {
            std::optional<Math::Vector3D> hitPoint = sphere.hits(r);
            if (hitPoint.has_value()) {
                if (i == 0) {
                    savedHitPoint = hitPoint.value();
                    savedSphere = sphere;
                    i++;
                } else {
                    if (Math::MathUtils::distance(_origin, hitPoint.value()) < Math::MathUtils::distance(_origin, savedHitPoint) && Math::MathUtils::distance(_origin, hitPoint.value()) > 0) {
                        savedHitPoint = hitPoint.value();
                        savedSphere = sphere;
                    }
                }
            }
        }
        Math::Vector3D normal = savedSphere.normal(savedHitPoint);
        Math::Vector3D lightDir(spot._origin, savedHitPoint);

        double dot = std::max(normal.dot(lightDir.normalized()), 0.0);
        Math::Vector3D hitColor(savedSphere._color);
        hitColor *= dot;
        for (auto &sphere : spheres) {
            if (sphere == savedSphere)
                continue;
            RayTracer::Ray bouncingRay(savedHitPoint, lightDir);
            std::optional<Math::Vector3D> hitPoint = sphere.hits(bouncingRay);
            if (hitPoint.has_value()) {
                hitColor *= 0.7;
            }
        }
        Math::Vector3D color = Math::MathUtils::toRGB(hitColor * (savedSphere._color));
        return color;
    }

    Math::Vector3D Camera::pointAt(double u, double v, std::vector<RayTracer::Plane> &Planes, const RayTracer::Spot &spot) const {

        RayTracer::Ray r = ray(u, v);
        RayTracer::Plane plane = Planes.front();
        std::optional<Math::Vector3D> hitPoint = plane.hits(r);
        if (hitPoint.has_value()) {
            return Math::Vector3D(std::round(std::clamp((100.0 + (u * v ) * -30), 0.0, 255.0)), std::round(std::clamp((100.0 + (u * v) * -30), 0.0, 255.0)), std::round(std::clamp((100.0 + (u * v ) * -30), 0.0, 255.0)));
        }
        return Math::Vector3D(0, 0, 0);

//        Math::Vector3D savedHitPoint;
//        RayTracer::Plane savedPlane;
//        int i = 0;
//
//        for (auto &Plane : Planes) {
//            std::optional<Math::Vector3D> hitPoint = Plane.hits(r);
//            if (hitPoint.has_value()) {
//                if (i == 0) {
//                    savedHitPoint = hitPoint.value();
//                    savedPlane = Plane;
//                    i++;
//                } else {
//                    if (Math::MathUtils::distance(_origin, hitPoint.value()) < Math::MathUtils::distance(_origin, savedHitPoint) && Math::MathUtils::distance(_origin, hitPoint.value()) > 0) {
//                        savedHitPoint = hitPoint.value();
//                        savedPlane = Plane;
//                    }
//                }
//            }
//        }
//        Math::Vector3D normal = savedPlane.normal(savedHitPoint);
//        Math::Vector3D lightDir(spot._origin, savedHitPoint);
//
//        double dot = std::max(normal.dot(lightDir.normalized()), 0.0);
//        Math::Vector3D hitColor(savedPlane._color);
//        hitColor *= dot;
//        for (auto &Plane : Planes) {
//            if (Plane == savedPlane)
//                continue;
//            RayTracer::Ray bouncingRay(savedHitPoint, lightDir);
//            std::optional<Math::Vector3D> hitPoint = Plane.hits(bouncingRay);
//            if (hitPoint.has_value()) {
//                hitColor *= 0.7;
//            }
//        }
//        Math::Vector3D color = Math::MathUtils::toRGB(hitColor * (savedPlane._color));
//        return color;
    }
} // RayTracer