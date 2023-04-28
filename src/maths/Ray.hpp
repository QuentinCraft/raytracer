/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Ray.hpp
*/

#ifndef BSRAYTRACER_RAY_HPP
#define BSRAYTRACER_RAY_HPP

#include "maths/Vector3D.hpp"
#include <memory>

namespace RayTracer {

    class Ray {
        public:
            // Constructors
            Ray();
            Ray(const Math::Vector3D &origin, const Math::Vector3D &direction);
            Ray(const Ray &ray);
            Ray(Ray &&ray) = default;

            // Destructor
            ~Ray() = default;

            // Operators
            Ray &operator=(const Ray &ray) = default;
            Ray &operator=(Ray &&ray) = default;

            // Variables
            Math::Vector3D _origin;
            Math::Vector3D _direction;
    };

} // RayTracer

#endif //BSRAYTRACER_RAY_HPP
