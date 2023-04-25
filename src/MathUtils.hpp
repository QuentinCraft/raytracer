/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** MathUtils.hpp
*/

#ifndef BSRAYTRACER_MATHUTILS_HPP
#define BSRAYTRACER_MATHUTILS_HPP

#include "Vector3D.hpp"
#include "Point3D.hpp"

namespace Math {

    class MathUtils {
        public:
            static bool equal(double a, double b);
            static bool inf(double a, double b);
            static bool sup(double a, double b);
            static Point3D toRGB(Point3D x);
    };

} // Math

#endif //BSRAYTRACER_MATHUTILS_HPP
