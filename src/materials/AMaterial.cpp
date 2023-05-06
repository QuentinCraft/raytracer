/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** AMaterial.cpp
*/

#include "AMaterial.hpp"

namespace RayTracer {
    AMaterial::AMaterial() {
        _diffuse = {0.4, 0.4, 0.4};
        _specular = {0.28, 0.28, 0.28};
        _shininess = 74.3;
        _refraction = 0;
        _reflection = false;
    }

    Math::Vector3D AMaterial::getDiffuse() const {
        return _diffuse;
    }

    void AMaterial::setDiffuse(Math::Vector3D diffuse) {
        _diffuse = diffuse;
    }

    Math::Vector3D AMaterial::getSpecular() const {
        return _specular;
    }

    void AMaterial::setSpecular(Math::Vector3D specular) {
        _specular = specular;
    }

    double AMaterial::getShininess() const {
        return _shininess;
    }

    void AMaterial::setShininess(double shininess) {
        _shininess = shininess;
    }

    double AMaterial::getRefraction() const {
        return _refraction;
    }

    void AMaterial::setRefraction(double refraction) {
        _reflection = refraction;
    }

    bool AMaterial::getReflection() const {
        return _reflection;
    }

    void AMaterial::setReflection(bool reflection) {
        _reflection = reflection;
    }

    AMaterial::AMaterial(Math::Vector3D diffuse, Math::Vector3D specular, double shininess, double refraction,
                         bool reflection) {
        _diffuse = diffuse;
        _specular = specular;
        _shininess = shininess;

        _refraction = refraction;
        _reflection = reflection;
    }
} // RayTracer