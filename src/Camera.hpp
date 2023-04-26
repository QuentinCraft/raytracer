/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Camera3D.hpp
*/

#ifndef BSRAYTRACER_CAMERA_HPP
#define BSRAYTRACER_CAMERA_HPP

#include "Point3D.hpp"
#include "Rectangle3D.hpp"
#include "Sphere.hpp"
#include "Spot.hpp"
#include <vector>

namespace RayTracer {

    class Camera {
        public:
            // Constructors
            Camera();
            Camera(const Math::Point3D& origin, double height, double width, double fov);
            ~Camera() = default;

            // Methods
            [[nodiscard]] Ray ray(double u, double v) const;
            [[nodiscard]] Math::Vector3D pointAt(double u, double v, std::vector<RayTracer::Sphere> &sphere, const RayTracer::Spot &spot) const;

            // Variables
            double _fov;
            double _height;
            double _width;
            Math::Vector3D _origin;
    };

} // RayTracer

#endif //BSRAYTRACER_CAMERA_HPP
