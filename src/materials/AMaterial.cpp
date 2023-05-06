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
} // RayTracer