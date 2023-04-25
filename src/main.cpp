/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** main.cpp
*/

#include "Sphere.hpp"
#include "Point3D.hpp"
#include "Vector3D.hpp"
#include "Ray.hpp"
#include "MathUtils.hpp"
#include "Camera.hpp"

#include <iostream>
#include <fstream>

int main()
{
    std::ofstream file("test.ppm");

    RayTracer::Sphere sphere;
    RayTracer::Camera cam(Math::Point3D(0, 0, 0), 800, 800, 120);
    sphere._radius = 2;
    sphere._center._x = 0;
    sphere._center._y = 0;
    sphere._center._z = 10;

    file << "P3\n800 800\n255\n";

    for (int y = 0; y < cam._height; y++) {
        for (int x = 0; x < cam._width; x++) {
            double u = (x / cam._width) * 2 - 1;
            double v = (y / cam._height) * 2 - 1;
            RayTracer::Ray ray = cam.ray(u, v);
            if (sphere.hits(ray)) {
                file << "255 0 0" << std::endl;
            } else {
                file << "15 15 15" << std::endl;
            }
        }
    }
    file.close();
    return 0;
}