/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Point3D.hpp
*/

#ifndef BSRAYTRACER_POINT3D_HPP
#define BSRAYTRACER_POINT3D_HPP

#include "Vector3D.hpp"

namespace Math {

    class Point3D {
        public:
            // Constructors
            Point3D();
            Point3D(double x, double y, double z);
            Point3D(const Point3D &point3D);
            Point3D(Point3D &&point3D) = default;

            // Destructor
            ~Point3D() = default;

            // Operators
            Point3D &operator=(const Point3D &point3D) = default;
            Point3D &operator=(Point3D &&point3D) = default;
            Point3D operator+(const Vector3D &vector3D) const;
            Point3D operator+(const Point3D &point) const;
            Point3D operator-(const Point3D &point) const;

            double dot(const Vector3D &vector) const;
            double dot(const Point3D &point) const;

            // Variables
            double _x;
            double _y;
            double _z;
    };

} // Math

#endif //BSRAYTRACER_POINT3D_HPP
