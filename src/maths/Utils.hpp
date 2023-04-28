/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** MathUtils.hpp
*/

#ifndef BSRAYTRACER_MATHUTILS_HPP
#define BSRAYTRACER_MATHUTILS_HPP

#include "maths/Vector3D.hpp"

namespace Math {

    class Utils {
        public:
            static bool equal(double a, double b);
            static bool inf(double a, double b);
            static bool sup(double a, double b);
            static Vector3D toRGB(Vector3D x);
            [[nodiscard]] static double distance(const Math::Vector3D &aColor, const Math::Vector3D &bColor);
    };

} // Math

#endif //BSRAYTRACER_MATHUTILS_HPP
