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

    static PipeLine closestPoint(const Ray &r, std::vector<std::shared_ptr<IObject>> &objects,
                                       std::vector<std::shared_ptr<ILight>> &lights,
                                       std::shared_ptr<Ambient> &ambient) {
        PipeLine savedHitPoint;
        savedHitPoint.object = nullptr;
        int i = 0;
        for (auto &object : objects) {
            std::optional<PipeLine> hitPoint = object->hits(r);
            if (hitPoint.has_value()) {
                if (i == 0) {
                    savedHitPoint = hitPoint.value();
                    i++;
                } else {
                    if (Math::Utils::distance(r._origin, hitPoint.value()._position) < Math::Utils::distance(r._origin, savedHitPoint._position))
                        savedHitPoint = hitPoint.value();
                }
            }
        }
        return savedHitPoint;
    }
    static Math::Vector3D lambert(PipeLine &object, std::vector<std::shared_ptr<ILight>> &lights,
                                 std::shared_ptr<Ambient> &ambient) {
        Math::Vector3D normal = object.object->normal(object).normalized();
        Math::Vector3D lightDir(lights.front()->getOrigin(), object._position);
        double dot = std::max(normal.dot(lightDir.normalized()), 0.0);
        Math::Vector3D hitColor(object.object->getColor());
        hitColor *= (ambient->getIntensity() + dot);
        return hitColor;
    }

    static Math::Vector3D dropShadow(PipeLine &savedHitPoint, Math::Vector3D hitColor,
                           std::vector<std::shared_ptr<IObject>> &objects,
                           std::vector<std::shared_ptr<ILight>> &lights,
                           std::shared_ptr<Ambient> &ambient) {
        Ray bouncingRay(savedHitPoint._position, (lights.front()->getOrigin() - savedHitPoint._position).normalized());
        for (auto &object : objects) {
            if (object == savedHitPoint.object)
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
        return hitColor;
    }

    static Math::Vector3D compute(const Ray &r, std::vector<std::shared_ptr<IObject>> &objects,
                                  std::vector<std::shared_ptr<ILight>> &lights,
                                    std::shared_ptr<Ambient> &ambient, int recursive) {
        Math::Vector3D hitColor;

        PipeLine savedHitPoint = closestPoint(r, objects, lights, ambient);
        if (savedHitPoint.object == nullptr)
            return {0.3, 0.3, 1};
        else
            hitColor = savedHitPoint.object->getColor();

        if (savedHitPoint.object->getColor() == Math::Vector3D(1, 0, 1)) {
            Math::Vector3D reflect = r._direction - (savedHitPoint.object->normal(savedHitPoint) * r._direction.dot(savedHitPoint.object->normal(savedHitPoint)) * 2);
            Ray reflectedRay(savedHitPoint._position, reflect);
            PipeLine savedHitPoint2 = closestPoint(reflectedRay, objects, lights, ambient);
            if (savedHitPoint2.object == nullptr) {
                hitColor = Math::Vector3D(0.3, 0.3, 1);
            } else {
                if (recursive <= 0)
                    return {0.3, 0.3, 1};
                return compute(reflectedRay, objects, lights, ambient, recursive - 1);
            }
        }
        hitColor *= lambert(savedHitPoint, lights, ambient);
        hitColor = dropShadow(savedHitPoint, hitColor, objects, lights, ambient);
        return hitColor;
    }


    Math::Vector3D Camera::pointAt(double u, double v, std::vector<std::shared_ptr<IObject>> &objects, std::vector<std::shared_ptr<ILight>> &lights, std::shared_ptr<Ambient> &ambient) const {
        Ray r = ray(u, v);
        Math::Vector3D hitColor;

        hitColor = compute(r, objects, lights, ambient, 50);
        Math::Vector3D color = Math::Utils::toRGB(hitColor);
        return color;
    }

} // RayTracer