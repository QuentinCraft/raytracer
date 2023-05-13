/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** AMaterial.cpp
*/

#include "AMaterial.hpp"

namespace RayTracer {
    AMaterial::AMaterial(std::string name) {
        _diffuse = {0.4, 0.4, 0.4};
        _specular = {0.28, 0.28, 0.28};
        _shininess = 74.3;
        _refraction = 0;
        _reflection = false;
        _spread = 0.0001;
        _name = std::move(name);
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

    AMaterial::AMaterial(std::string name, Math::Vector3D ambient, Math::Vector3D diffuse, Math::Vector3D specular, double shininess, double refraction,
                         bool reflection, double spread) {
        _ambient = ambient;
        _diffuse = diffuse;
        _specular = specular;
        _shininess = shininess;

        _refraction = refraction;
        _reflection = reflection;
        _spread = spread;
        _name = std::move(name);
    }

    void AMaterial::setSpread(double spread) {
        _spread = spread;
    }

    double AMaterial::getSpread() const {
        return _spread;
    }

    void AMaterial::setAmbient(Math::Vector3D ambient) {
        _ambient = ambient;
    }

    Math::Vector3D AMaterial::getAmbient() const {
        return _ambient;
    }
} // RayTracer