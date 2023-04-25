/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** MathUtils.cpp
*/

#include "MathUtils.hpp"

namespace Math {
    bool MathUtils::equal(double a, double b) {
        return (a - b) < 0.0001 && (a - b) > -0.0001;
    }

    bool MathUtils::inf(double a, double b) {
        return (a - b) < 0.0001;
    }

    bool MathUtils::sup(double a, double b) {
        return (a - b) > 0.0001;
    }

    Point3D MathUtils::toRGB(Point3D x) {
        x._x = std::clamp(x._x, 0.0, 1.0);
        x._y = std::clamp(x._y, 0.0, 1.0);
        x._z = std::clamp(x._z, 0.0, 1.0);
        return {std::round(x._x * 255), std::round(x._y * 255), std::round(x._z * 255)};
    }
} // Math