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
#include "Spot.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>

int main() {
    std::ofstream file("render.ppm");

    RayTracer::Sphere sphere;
    RayTracer::Camera cam(Math::Point3D(0, 0, -2), 800, 800, 90);
    RayTracer::Spot spot(Math::Point3D(1, -2, -3), 1);
    std::optional<Math::Point3D> hitPoint;
    sphere._radius = 0.5;
    sphere._center._x = 0;  // Left   -1 |  Right    1
    sphere._center._y = 0;  // Down   -1 |  Up       1
    sphere._center._z = 0; // Behind -1 |  Forward  1

    file << "P3\n" << cam._width << " " << cam._height << "\n255\n";

    for (int y = 0; y < cam._width; y++) {
        for (int x = 0; x < cam._height; x++) {
            double u = ((x / cam._width) * 2) - 1;
            double v = ((y / cam._height) * 2) - 1;
            RayTracer::Ray ray = cam.ray(u, v);
            hitPoint = sphere.hits(ray);
            if (hitPoint.has_value()) {
                Math::Point3D val = hitPoint.value();

                Math::Vector3D normal = sphere.normal(val);

                Math::Vector3D lightDir(spot._origin, val);

                Math::Vector3D incidentLight(lightDir._x, lightDir._y, lightDir._z);

                double iNorm = std::sqrt((incidentLight._x * incidentLight._x) + (incidentLight._y * incidentLight._y) + (incidentLight._z * incidentLight._z));

                Math::Vector3D iNormalized(incidentLight._x / iNorm, incidentLight._y / iNorm, incidentLight._z / iNorm);

                double dot = std::max(normal.dot(iNormalized), 0.0);

                Math::Vector3D sphereColor(1, 0, 1);

                sphereColor *= dot;

                Math::Point3D color = Math::MathUtils::toRGB(sphereColor.toPoint());

                file << color._x << " " << color._y << " " << color._z << std::endl;
            } else {
                file << "15 15 15" << std::endl;
            }
        }
    }
    file.close();
    return 0;
}