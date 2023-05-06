/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** plastic.cpp
*/

#include "Chrome.hpp"

namespace RayTracer {
    Chrome::Chrome() {
        _diffuse = {0.4, 0.4, 0.4};
        _specular = {0.774597, 0.774597, 0.774597};
        _shininess = 0.25 * 128;
    }
} // RayTracer