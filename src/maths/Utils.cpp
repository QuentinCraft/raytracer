/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** MathUtils.cpp
*/

#include "Utils.hpp"

namespace Math {
    bool Utils::equal(double a, double b) {
        return (a - b) < 0.0000000001 && (a - b) > -0.0000000001;
    }

    bool Utils::inf(double a, double b) {
        return (a - b) < 0.0000000001;
    }

    bool Utils::sup(double a, double b) {
        return (a - b) > 0.0000000001;
    }

    Vector3D Utils::toRGB(Vector3D x) {
        x._x = std::clamp(x._x , 0.0, 1.0);
        x._y = std::clamp(x._y , 0.0, 1.0);
        x._z = std::clamp(x._z , 0.0, 1.0);
        return {std::round(x._x * 255), std::round(x._y * 255), std::round(x._z * 255)};
    }

    double Utils::distance(const Math::Vector3D& aColor, const Math::Vector3D& bColor) {
        return sqrt(pow(aColor._x - bColor._x, 2) + pow(aColor._y - bColor._y, 2) + pow(aColor._z - bColor._z, 2));
    }

} // Math