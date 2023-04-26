/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Rectangle3D.hpp
*/

#ifndef BSRAYTRACER_RECTANGLE3D_HPP
#define BSRAYTRACER_RECTANGLE3D_HPP

#include "Vector3D.hpp"
#include "Ray.hpp"
#include "MathUtils.hpp"

namespace RayTracer {

    class Rectangle3D {
        public:
            // Constructors
            Rectangle3D();
            Rectangle3D(const Math::Vector3D& origin, const Math::Vector3D& bottomSide, const Math::Vector3D& leftSide);

            // Destructor
            ~Rectangle3D() = default;

            // Methods
            Math::Vector3D pointAt(double u, double v) const;

            // Variables
            Math::Vector3D _origin;
            Math::Vector3D _bottomSide;
            Math::Vector3D _leftSide;
    };

} // RayTracer

#endif //BSRAYTRACER_RECTANGLE3D_HPP
