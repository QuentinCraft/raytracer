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
        Math::Vector3D hitColor(object._color);
        hitColor *= (ambient->getIntensity() + dot);
        return hitColor;
    }

    static Math::Vector3D getLitColor(const Math::Vector3D& viewDir, const Math::Vector3D& surfacePointPosition, const Math::Vector3D& objectColor, const std::shared_ptr<ILight>& pointLight, const Math::Vector3D& surfaceNormal)
    {
        Math::Vector3D lightVector = surfacePointPosition - pointLight->getOrigin();
        Math::Vector3D lightDir = lightVector.normalized();

        double lightIntensity = (pow(0.1, 2.0) / pow(lightVector.length(), 2.0)) * pointLight->getIntensity()._x;

        double coeff = (lightDir * -1).dot(surfaceNormal);

        double material_diffuse = 0.514;
        double material_specular = 0.19;
        double material_shininess = 76.8;
        double material_ambience = 0.0;

        Math::Vector3D ambient = objectColor * material_ambience;

        Math::Vector3D diffuse = objectColor * material_diffuse * std::max(coeff, 0.0) * lightIntensity;

        Math::Vector3D halfwayDir = (lightDir + viewDir).normalized();
        Math::Vector3D specular = objectColor * std::pow(std::max((surfaceNormal * -1).dot(halfwayDir), 0.0), material_shininess) * material_specular * lightIntensity;

//        if (objectColor != Math::Vector3D(0.23, 0.23, 0.23) && objectColor != Math::Vector3D(0.67, 0.67, 0.67))
//            std::cout << objectColor << " | " << ambient << " + " << diffuse << " + " << specular << std::endl;
        Math::Vector3D color = ambient + (diffuse * 1000) + specular;

        return color;
    }

    static Math::Vector3D phong(PipeLine &object, std::vector<std::shared_ptr<ILight>> &lights, const Ray &r) {

        Math::Vector3D normal = object.object->normal(object).normalized();

        return getLitColor(r._direction, object._position, object._color, lights.front(), normal * -1);
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
            hitColor = savedHitPoint._color;

        if (savedHitPoint._color == Math::Vector3D(1, 0, 1)) {
            Math::Vector3D reflect = r._direction - (savedHitPoint.object->normal(savedHitPoint) * r._direction.dot(savedHitPoint.object->normal(savedHitPoint)) * 2);
            Ray reflectedRay(savedHitPoint._position, reflect);
            PipeLine savedHitPoint2 = closestPoint(reflectedRay, objects, lights, ambient);
            if (savedHitPoint2.object == nullptr) {
                savedHitPoint._color = {0.3, 0.3, 1};
            } else {
                if (recursive <= 0)
                    savedHitPoint._color = {0, 0, 0};
                savedHitPoint._color = compute(reflectedRay, objects, lights, ambient, recursive - 1) * 0.9;
            }
        }
        if (savedHitPoint._color == Math::Vector3D(0, 1, 0) && recursive > 0) {
            double etai_over_etat = 1.7;

            Math::Vector3D uv = r._direction.normalized();
            Math::Vector3D n = savedHitPoint.object->normal(
                    savedHitPoint).normalized();

            if (Math::Utils::sup(r._direction.dot(n), 0)) {
                n = n * -1;
                etai_over_etat = 1.0 / etai_over_etat;
            }

            auto cos_theta = fmin((uv * -1).dot(n), 1.0);
            Math::Vector3D r_out_perp = (uv + (n * cos_theta)) * etai_over_etat;
            Math::Vector3D r_out_parallel = n * -sqrt(fabs(1.0 - r_out_perp.length()));
            Ray reflectedRay(savedHitPoint._position, (r_out_perp + r_out_parallel.normalized()).normalized());
            double sin_theta = sqrt(1.0 - cos_theta*cos_theta);

            savedHitPoint._color = compute(reflectedRay, objects, lights, ambient, recursive);
        }
        hitColor = phong(savedHitPoint, lights, r);
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