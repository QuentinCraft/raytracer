/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Camera3D.cpp
*/
#include <iostream>
#include "Camera.hpp"

namespace RayTracer {

    static double distance(const Math::Vector3D& a, const Math::Vector3D& b) {
        return sqrt(pow(a._x - b._x, 2) + pow(a._y - b._y, 2) + pow(a._z - b._z, 2));
    }

    static bool canConnect(const Math::Vector3D& a, const Math::Vector3D& b, const Math::Vector3D& c) {
        double distAB = distance(a, b);
        double distBC = distance(b, c);
        double distAC = distance(a, c);
        if (Math::Utils::inf((distAB + distBC), distAC) || Math::Utils::inf(distAC + distBC, distAB)) {
            return false;
        } else {
            return true;
        }
    }

    Camera::Camera() {
        _origin = Math::Vector3D (0, 0, 0);
        _width = 800;
        _height = 800;
        _fov = 90;
        _rotation = Math::Vector3D(0, 0, 0);
    }

    Camera::Camera(const Math::Vector3D &origin, double width, double height, double fov) {
        _origin = origin;
        _width = width;
        _height = height;
        _fov = fov;
        _rotation = Math::Vector3D(0, 0, 0);
    }

    Ray Camera::ray(double u, double v) const {
        Math::Vector3D direction(u * (_fov / 90),
                                 -v * (_fov / 90),
                                 1);
        Ray ray(_origin, direction.normalized());
        return ray;
    }

    Math::Vector3D Camera::pointAt(double u, double v,
                                   std::vector<std::shared_ptr<IObject>> &objects,
                                   std::vector<std::shared_ptr<ILight>> &lights,
                                   std::shared_ptr<Ambient> &ambient) const {
        Ray r = ray(u, v);
        Math::Vector3D savedHitPoint;
        std::shared_ptr<IObject> savedObject;
        int i = 0;

        for (auto &object : objects) {
            std::optional<PipeLine> hitPoint = object->hits(r);
            if (hitPoint.has_value()) {
                if (i == 0) {
                    savedHitPoint = hitPoint.value()._position;
                    savedObject = object;
                    i++;
                } else {
                    if (Math::Utils::distance(_origin, hitPoint.value()._position) < Math::Utils::distance(_origin, savedHitPoint)) {
                        savedHitPoint = hitPoint.value()._position;
                        savedObject = object;
                    }
                }
            }
        }
        if (i == 0)
            return {0, 0, 0};
        Math::Vector3D normal = savedObject->normal(savedHitPoint).normalized();
        Math::Vector3D lightDir(lights.front()->getOrigin(), savedHitPoint);

        double dot = std::max(normal.dot(lightDir.normalized()), 0.0);
        Math::Vector3D hitColor(savedObject->getColor());
        hitColor *= (ambient->getIntensity() + dot);
        Ray bouncingRay(savedHitPoint, (lights.front()->getOrigin() - savedHitPoint).normalized());
        for (auto &object : objects) {
            if (object == savedObject)
                continue;
            std::optional<PipeLine> pipe = object->hits(bouncingRay);

            if (pipe.has_value()) {
                if (canConnect(savedHitPoint, pipe.value()._position, lights.front()->getOrigin()))
                    continue;
                if (Math::Utils::inf(Math::Utils::distance(bouncingRay._origin, lights.front()->getOrigin()), Math::Utils::distance(bouncingRay._origin, pipe.value()._position)))
                    continue;
                hitColor *= ambient->getIntensity();
                break;
            }
        }
        Math::Vector3D color = Math::Utils::toRGB(hitColor);
        return color;
    }

} // RayTracer