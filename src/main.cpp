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
    RayTracer::Camera cam;
    sphere._radius = 50;
    sphere._center._x = (1920.0 / 2);
    sphere._center._y = (1080.0 / 2);
    sphere._center._z = 0;

    file << "P3\n1920 1080\n255\n";

    for (int y = 0; y < 1080; y++) {
        for (int x = 0; x < 1920; x++) {
            RayTracer::Ray ray = cam.ray(x, y);
            if (sphere.hits(ray)) {
                file << "255 0 0" << std::endl;
            } else {
                file << "0 0 0" << std::endl;
            }
        }
    }
    file.close();
    return 0;
}