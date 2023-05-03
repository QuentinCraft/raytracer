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
        PipeLine savedHitPoint;
        std::shared_ptr<IObject> savedObject;
        int i = 0;

        for (auto &object : objects) {
            std::optional<PipeLine> hitPoint = object->hits(r);
            if (hitPoint.has_value()) {
                if (i == 0) {
                    savedHitPoint = hitPoint.value();
                    savedObject = object;
                    i++;
                } else {
                    if (Math::Utils::distance(_origin, hitPoint.value()._position) < Math::Utils::distance(_origin, savedHitPoint._position)) {
                        savedHitPoint = hitPoint.value();
                        savedObject = object;
                    }
                }
            }
        }
        if (i == 0)
            return {85, 95, 255};


        // LAMBERT
        Math::Vector3D normal = savedObject->normal(savedHitPoint).normalized();
        Math::Vector3D lightDir(lights.front()->getOrigin(), savedHitPoint._position);
        double dot = std::max(normal.dot(lightDir.normalized()), 0.0);
        Math::Vector3D hitColor(savedObject->getColor());
        hitColor *= (ambient->getIntensity() + dot);

        // DROP SHADOW
        Ray bouncingRay(savedHitPoint._position, (lights.front()->getOrigin() - savedHitPoint._position).normalized());
        for (auto &object : objects) {
            if (object == savedObject)
                continue;
            std::optional<PipeLine> pipe = object->hits(bouncingRay);
            if (pipe.has_value()) {
                if (canConnect(savedHitPoint._position, pipe.value()._position, lights.front()->getOrigin()))
                    continue;
                if (Math::Utils::inf(Math::Utils::distance(bouncingRay._origin, lights.front()->getOrigin()), Math::Utils::distance(bouncingRay._origin, pipe.value()._position)))
                    continue;
                hitColor *= ambient->getIntensity();
                break;
            }
        }

        // REFLECTION
        if (savedObject->getColor() == Math::Vector3D(1, 0, 1)) {
            hitColor = Math::Vector3D(0.3, 0.3, 1) + (dot * 0.3);
            Math::Vector3D reflect = r._direction - ((normal * r._direction.dot(normal)) * 2);
            Ray bouncingRayRe(savedHitPoint._position, reflect);
            for (auto &object : objects) {
                if (object == savedObject)
                    continue;
                std::optional<PipeLine> pipe = object->hits(bouncingRayRe);
                if (pipe.has_value()) {
                    Math::Vector3D normal2 = object->normal(pipe.value()).normalized();
                    Math::Vector3D lightDir2(lights.front()->getOrigin(), pipe.value()._position);
                    double dot2 = std::max(normal2.dot(lightDir2.normalized()), 0.0);
                    Math::Vector3D hitColor2(object->getColor());
                    hitColor2 *= (ambient->getIntensity() + dot2);
                    hitColor = hitColor2 + (dot * 0.3);

                    Ray bouncingRay3(pipe.value()._position, (lights.front()->getOrigin() - pipe.value()._position).normalized());
                    for (auto &object3 : objects) {
                        if (object3 == object)
                            continue;
                        std::optional<PipeLine> pipe3 = object3->hits(bouncingRay3);
                        if (pipe3.has_value()) {
                            if (canConnect(pipe3.value()._position, pipe3.value()._position, lights.front()->getOrigin()))
                                continue;
                            if (Math::Utils::inf(Math::Utils::distance(bouncingRay3._origin, lights.front()->getOrigin()), Math::Utils::distance(bouncingRay3._origin, pipe3.value()._position)))
                                continue;
                            hitColor *= ambient->getIntensity();
                            break;
                        }
                    }
                    break;
                }
            }
        }

        Math::Vector3D color = Math::Utils::toRGB(hitColor);
        return color;
    }

} // RayTracer