/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Vector3D.hpp
*/

#ifndef BSRAYTRACER_VECTOR3D_HPP
#define BSRAYTRACER_VECTOR3D_HPP

#include <valarray>
#include <iostream>

namespace Math {
    class Vector3D {
        public:
            // Constructors
            Vector3D();
            Vector3D(double x, double y, double z);
            Vector3D(const Vector3D &vector);
            Vector3D(Vector3D &&vector) = default;
            Vector3D(const Vector3D &point1, const Vector3D &point2);

            // Destructor
            ~Vector3D() = default;

            // Operators
            Vector3D &operator=(const Vector3D &vector) = default;
            Vector3D &operator=(Vector3D &&vector) = default;

            Vector3D operator+(const Vector3D &vector) const;
            Vector3D &operator+=(const Vector3D &vector);
            Vector3D operator-(const Vector3D &vector) const;
            Vector3D &operator-=(const Vector3D &vector);
            Vector3D operator*(const Vector3D &vector) const;
            Vector3D &operator*=(const Vector3D &vector);
            Vector3D operator/(const Vector3D &vector) const;
            Vector3D &operator/=(const Vector3D &vector);

            Vector3D operator*(double value) const;
            Vector3D operator+(double value) const;
            Vector3D &operator*=(double value);
            Vector3D &operator+=(double value);
            Vector3D operator/(double value) const;
            Vector3D &operator/=(double value);

            bool operator==(const Vector3D &vector) const;

            [[nodiscard]] Vector3D normalized() const;

            // Methods
            [[nodiscard]] double dot(const Vector3D &vector) const;
            [[nodiscard]] double length() const;

            // Variables
            double _x;
            double _y;
            double _z;
    };
    std::ostream &operator<<(std::ostream& os, const Vector3D& v);
    } // Math

#endif //BSRAYTRACER_VECTOR3D_HPP
