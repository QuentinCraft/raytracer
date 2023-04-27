/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** main.cpp
*/

#include "Sphere.hpp"
#include "Vector3D.hpp"
#include "Ray.hpp"
#include "MathUtils.hpp"
#include "Camera.hpp"
#include "Spot.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>

    int main() {
        std::ofstream file("render.ppm");

        RayTracer::Sphere sphere;
        RayTracer::Sphere sphere2(Math::Vector3D(0, 0, 0), 0.5, Math::Vector3D(1, 0, 0));
        RayTracer::Plane plane(Math::Vector3D(0, 0, 0), Math::Vector3D(0, 1, 0));
        // RayTracer::Plane plane2(Math::Vector3D(0, 0, 0), Math::Vector3D(0, 1, 0));
        RayTracer::Camera cam(Math::Vector3D(0, 0, -2), 800, 800, 90);
        RayTracer::Spot spot(Math::Vector3D(0, 2, -3), Math::Vector3D(2, 2, 2));
        std::optional<Math::Vector3D> hitPoint;
        sphere._color = Math::Vector3D(0.4, 0.4, 1);
        sphere._radius = 0.2;
        sphere._center._x = 0.1;  // Left   -1 |  Right    1
        sphere._center._y = 0.5;  // Down   -1 |  Up       1
        sphere._center._z = -0.5; // Behind -1 |  Forward  1

        file << "P3\n" << cam._width << " " << cam._height << "\n255\n";

        std::vector<RayTracer::Sphere> spheres = {sphere, sphere2};
        std::vector<RayTracer::Plane> planes = {plane};

        for (int y = 0; y < cam._width; y++) {
            for (int x = 0; x < cam._height; x++) {
                double u = ((x / cam._width) * 2) - 1;
                double v = ((y / cam._height) * 2) - 1;
                Math::Vector3D color = cam.pointAt(u, v, planes, spot);
                file << color._x << " " << color._y << " " << color._z << std::endl;
            }
        }
        file.close();
        return 0;
    }