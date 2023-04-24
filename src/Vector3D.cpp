/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Vector3D.cpp
*/

#include "Vector3D.hpp"
#include "Point3D.hpp"

namespace Math {
    Vector3D::Vector3D() {
        _x = 0;
        _y = 0;
        _z = 0;
    }

    Vector3D::Vector3D(double x, double y, double z) {
        _x = x;
        _y = y; 
        _z = z;
    }

    Vector3D::Vector3D(const Vector3D &vector) {
        _x = vector._x;
        _y = vector._y;
        _z = vector._z;
    }

    float Vector3D::length() const {
        return std::sqrt((float) (_x * _x) + (float) (_y * _y) + (float) (_z * _z));
    }

    Vector3D Vector3D::operator+(const Vector3D &vector) const {
        Vector3D result;

        result._x = _x + vector._x;
        result._y = _y + vector._y;
        result._z = _z + vector._z;
        return result;
    }

    Vector3D &Vector3D::operator+=(const Vector3D &vector) {
        _x += vector._x;
        _y += vector._y;
        _z += vector._z;
        return *this;
    }

    Vector3D Vector3D::operator-(const Vector3D &vector) const {
        Vector3D result;

        result._x = _x - vector._x;
        result._y = _y - vector._y;
        result._z = _z - vector._z;
        return result;
    }

    Vector3D &Vector3D::operator-=(const Vector3D &vector) {
        _x -= vector._x;
        _y -= vector._y;
        _z -= vector._z;
        return *this;
    }

    Vector3D Vector3D::operator*(const Vector3D &vector) const {
        Vector3D result;

        result._x = _x * vector._x;
        result._y = _y * vector._y;
        result._z = _z * vector._z;
        return result;
    }

    Vector3D &Vector3D::operator*=(const Vector3D &vector) {
        _x *= vector._x;
        _y *= vector._y;
        _z *= vector._z;
        return *this;
    }

    Vector3D Vector3D::operator/(const Vector3D &vector) const {
        Vector3D result;

        result._x = _x / vector._x;
        result._y = _y / vector._y;
        result._z = _z / vector._z;
        return result;
    }

    Vector3D &Vector3D::operator/=(const Vector3D &vector) {
        _x /= vector._x;
        _y /= vector._y;
        _z /= vector._z;
        return *this;
    }

    Vector3D Vector3D::operator*(double value) const {
        Vector3D result;

        result._x = _x * value;
        result._y = _y * value;
        result._z = _z * value;
        return result;
    }

    Vector3D &Vector3D::operator*=(double value) {
        _x *= value;
        _y *= value;
        _z *= value;
        return *this;
    }

    Vector3D Vector3D::operator/(double value) const {
        Vector3D result;

        result._x = _x / value;
        result._y = _y / value;
        result._z = _z / value;
        return result;
    }

    Vector3D &Vector3D::operator/=(double value) {
        _x /= value;
        _y /= value;
        _z /= value;
        return *this;
    }

    double Vector3D::dot(const Vector3D &vector) const {
        return (_x * vector._x) + (_y * vector._y) + (_z * vector._z);
    }

    double Vector3D::dot(const Math::Point3D &point) const {
        return (_x * point._x) + (_y * point._y) + (_z * point._z);
    }

} // Math