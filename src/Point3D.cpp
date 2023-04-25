/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Point3D.cpp
*/

#include "Point3D.hpp"
#include "Vector3D.hpp"

namespace Math {
    Point3D::Point3D() {
        _x = 0;
        _y = 0;
        _z = 0;
    }

    Point3D::Point3D(double x, double y, double z) {
        _x = x;
        _y = y;
        _z = z;

    }

    Point3D::Point3D(const Point3D &point3D) {
        _x = point3D._x;
        _y = point3D._y;
        _z = point3D._z;
    }

    Point3D Point3D::operator+(const Vector3D &vector3D) const {
        Point3D result(_x + vector3D._x, _y + vector3D._y, _z + vector3D._z);
        return result;
    }

    double Point3D::dot(const Vector3D &vector) const {
        return (_x * vector._x) + (_y * vector._y) + (_z * vector._z);
    }

    double Point3D::dot(const Point3D &point) const {
        return (_x * point._x) + (_y * point._y) + (_z * point._z);
    }

    Point3D Point3D::operator+(const Point3D &point) const {
        Point3D result(_x + point._x, _y + point._y, _z + point._z);
        return result;
    }

    Point3D Point3D::operator-(const Point3D &point) const {
        Point3D result(_x - point._x, _y - point._y, _z - point._z);
        return result;
    }

    Vector3D Point3D::toVector() const {
        return {_x, _y, _z};
    }

} // Math