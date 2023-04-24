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

namespace RayTracer {

    class Camera {
        public:
            // Constructors
            Camera();
            ~Camera() = default;

            // Methods
            Ray ray(double x, double y) const;


            // Variables
            Rectangle3D _screen;
            Math::Point3D _origin;
    };

} // RayTracer

#endif //BSRAYTRACER_CAMERA_HPP
