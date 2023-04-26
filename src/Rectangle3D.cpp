/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Rectangle3D.cpp
*/

#include "Rectangle3D.hpp"

namespace RayTracer {
    Rectangle3D::Rectangle3D() {
        _origin = Math::Vector3D();
        _bottomSide = Math::Vector3D();
        _leftSide = Math::Vector3D();
    }
    Rectangle3D::Rectangle3D(const Math::Vector3D& origin, const Math::Vector3D& bottomSide, const Math::Vector3D& leftSide) {
        _origin = origin;
        _bottomSide = bottomSide;
        _leftSide = leftSide;
    }

    Math::Vector3D Rectangle3D::pointAt(double u, double v) const {
        return {_origin._x + u, _origin._y + v, _origin._z};
    }
} // RayTracer