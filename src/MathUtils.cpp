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
} // Math