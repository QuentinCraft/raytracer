/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** AMaterial.cpp
*/

#include "AMaterial.hpp"

namespace RayTracer {
    AMaterial::AMaterial() {
        _diffuse = 0.4;
        _specular = 0.28;
        _shininess = 74.3;
    }

    double AMaterial::getDiffuse() const {
        return _diffuse;
    }

    void AMaterial::setDiffuse(double diffuse) {
        _diffuse = diffuse;
    }

    double AMaterial::getSpecular() const {
        return _specular;
    }

    void AMaterial::setSpecular(double specular) {
        _specular = specular;
    }

    double AMaterial::getShininess() const {
        return _shininess;
    }

    void AMaterial::setShininess(double shininess) {
        _shininess = shininess;
    }
} // RayTracer