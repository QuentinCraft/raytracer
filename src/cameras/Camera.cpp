/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Camera3D.cpp
*/
#include <iostream>
#include <random>
#include "Camera.hpp"

namespace RayTracer {


    static double randomDouble(double n) {
        static std::uniform_real_distribution<double> distribution(-n, n);
        static std::mt19937 generator;
        return distribution(generator);
    }

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
        savedHitPoint._object = nullptr;
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

    static Math::Vector3D getLitColor(const Math::Vector3D& viewDir, const Math::Vector3D& surfacePointPosition, const Math::Vector3D& objectColor, const std::shared_ptr<ILight>& pointLight, const Math::Vector3D& surfaceNormal, const Ambient &ambientLight, const std::shared_ptr<IMaterial> &material)
    {
        Math::Vector3D lightVector = surfacePointPosition - pointLight->getOrigin();
        Math::Vector3D lightDir = lightVector.normalized();

        Math::Vector3D lightIntensity = (pointLight->getIntensity() * 1000) * (0.01 / lightVector.dot(lightVector));

        double coeff = (lightDir * -1).dot(surfaceNormal);


        Math::Vector3D ambient = objectColor * ambientLight.getIntensity();

        Math::Vector3D diffuse = objectColor * material->getDiffuse() * std::max(coeff, 0.0) * lightIntensity;

        Math::Vector3D halfwayDir = (lightDir + viewDir).normalized();
        Math::Vector3D specular = objectColor * std::pow(std::max((surfaceNormal * -1).dot(halfwayDir), 0.0), (material->getShininess())) * material->getSpecular() * lightIntensity;

        Math::Vector3D color = ambient + (diffuse) + specular;

        return color / 255;
    }

    static Math::Vector3D phong(PipeLine &object, std::shared_ptr<ILight> &light, const Ray &r, const Ambient &ambient) {

        Math::Vector3D normal = object._object->normal(object).normalized();
        return getLitColor(r._direction, object._position, object._color, light, normal * -1, ambient, object._material);
    }

    static Math::Vector3D dropShadow(PipeLine &savedHitPoint,
                                     std::vector<std::shared_ptr<IObject>> &objects,
                                     std::vector<std::shared_ptr<ILight>> &lights,
                                     std::shared_ptr<ILight> &light,
                                     std::shared_ptr<Ambient> &ambient, int sampling) {

        Math::Vector3D finalColor = {0, 0, 0};
        double div = 1;
        bool status;
        int correct = 0;
        int count = 0;

        for (int s = 0; s < sampling; s++) {
            Math::Vector3D sampleVec = light->getOrigin() - savedHitPoint._position;
            double dist = Math::Utils::distance(light->getOrigin(), savedHitPoint._position);
            sampleVec._x += randomDouble(5);
            sampleVec._z += randomDouble(5);
            sampleVec._y += randomDouble(5);
            Ray bouncingRay(savedHitPoint._position, (sampleVec).normalized());
            status = true;
            correct = -1;
            count = 0;
            for (auto &object : objects) {
                count++;
                if (status) {
                    if (object != savedHitPoint._object) {
                        std::optional<PipeLine> pipe = object->hits(bouncingRay);
                        if (pipe.has_value()) {
                            if (Math::Utils::inf(Math::Utils::distance(pipe.value()._position, bouncingRay._origin), dist)) {
                                div++;
                                finalColor += ambient->getIntensity();
                                correct = count;
                                status = false;
                            }
                        } else {
                            if (correct == count) {
                                div++;
                                finalColor += 1;
                                status = false;
                            }
                        }
                    }
                }
            }
            if (correct == -1) {
                div++;
                finalColor += 1;
            }
        }
        return finalColor / div;
    }

    static Math::Vector3D compute(Ray &r, std::vector<std::shared_ptr<IObject>> &objects,
                                  std::vector<std::shared_ptr<ILight>> &lights,
                                  std::shared_ptr<Ambient> &ambient, int recursive, int sampling, double spread) {
        Math::Vector3D hitColor;
        Math::Vector3D finalColor;
        int div = 0;

        for (int s = 0; s < sampling; s++) {
            if (!Math::Utils::equal(spread, 0)) {
                r._direction._x += std::clamp(std::rand() % 100 / 100.0, -spread, spread);
                r._direction._y += std::clamp(std::rand() % 100 / 100.0, -spread, spread);
                r._direction._z += std::clamp(std::rand() % 100 / 100.0, -spread, spread);
            } else
                s = sampling;

            PipeLine savedHitPoint = closestPoint(r, objects, lights, ambient);
            if (savedHitPoint._object == nullptr)
                return {0.3, 0.3, 1};
            else
                hitColor = savedHitPoint._color;

            if (savedHitPoint._material->getReflection()) {
                Math::Vector3D reflect = r._direction - (savedHitPoint._object->normal(savedHitPoint) * r._direction.dot(savedHitPoint._object->normal(savedHitPoint)) * 2);
                Ray reflectedRay(savedHitPoint._position, reflect);
                PipeLine savedHitPoint2 = closestPoint(reflectedRay, objects, lights, ambient);
                if (savedHitPoint2._object == nullptr) {
                    savedHitPoint._color = {0.3, 0.3, 1};
                } else {
                    if (recursive <= 0)
                        savedHitPoint._color = {0, 0, 0};
                    savedHitPoint._color =
                            compute(reflectedRay, objects, lights, ambient, recursive - 1, (sampling /= 2), savedHitPoint._material->getSpread()) * savedHitPoint._color;
                }
            } else if (!Math::Utils::equal(savedHitPoint._material->getRefraction(), 0) && recursive > 0) {
                double ref = savedHitPoint._material->getRefraction();

                Math::Vector3D uv = r._direction.normalized();
                Math::Vector3D n = savedHitPoint._object->normal(
                        savedHitPoint).normalized();

                if (Math::Utils::sup(r._direction.dot(n), 0)) {
                    n = n * -1;
                    ref = 1.0 / ref;
                }

                auto cos_theta = fmin((uv * -1).dot(n), 1.0);
                Math::Vector3D r_out_perp = (uv + (n * cos_theta)) * ref;
                Math::Vector3D r_out_parallel = n * -sqrt(fabs(1.0 - r_out_perp.length()));
                Ray reflectedRay(savedHitPoint._position, (r_out_perp + r_out_parallel.normalized()).normalized());

                savedHitPoint._color =
                        compute(reflectedRay, objects, lights, ambient, recursive, (sampling /= 2), savedHitPoint._material->getSpread()) * savedHitPoint._color;
            }
            std::vector<Math::Vector3D> phongs;
            std::vector<Math::Vector3D> dropShadows;
            for (auto &light: lights) {
                phongs.push_back(phong(savedHitPoint, light, r, *ambient));
                dropShadows.push_back(dropShadow(savedHitPoint, objects, lights, light, ambient, sampling));
            }
            hitColor = {0, 0, 0};
            for (auto &phong: phongs) {
                hitColor += phong;
            }
            for (auto &dropShadow: dropShadows) {
                hitColor *= dropShadow;
            }
            finalColor += hitColor;
            div++;
        }
        return finalColor / div;
    }

    Math::Vector3D Camera::pointAt(double u, double v, std::vector<std::shared_ptr<IObject>> &objects, std::vector<std::shared_ptr<ILight>> &lights, std::shared_ptr<Ambient> &ambient) const {
        Ray r = ray(u, v);
        Math::Vector3D hitColor;

        hitColor = compute(r, objects, lights, ambient, 20, 128, 0);
        Math::Vector3D color = Math::Utils::toRGB(hitColor);
        return color;
    }

} // RayTracer
