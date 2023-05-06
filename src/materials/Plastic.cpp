/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** plastic.cpp
*/

#include "Plastic.hpp"

namespace RayTracer {
    Plastic::Plastic() {
        _diffuse = {0.5, 0, 0};
        _specular = {0.7, 0.6, 0.6};
        _shininess = 0.25 * 128;
    }
} // RayTracer