/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** plastic.cpp
*/

#include "Chrome.hpp"

namespace RayTracer {
    Chrome::Chrome() {
        _diffuse = 0.5;
        _specular = 0.3;
        _shininess = 0.25 * 128;
    }
} // RayTracer