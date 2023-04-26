/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Sphere.hpp
*/

#ifndef BSRAYTRACER_SPHERE_HPP
#define BSRAYTRACER_SPHERE_HPP

#include "Vector3D.hpp"
#include "Ray.hpp"
#include "MathUtils.hpp"

#include <iostream>
#include <optional>
#include <functional>

namespace RayTracer {

    class Sphere {
        public:
            // Constructors
            Sphere();
            Sphere(const Math::Vector3D& center, double radius, const Math::Vector3D& color);
            Sphere(Sphere const &sphere) = default;
            Sphere(Sphere &&sphere) = default;

            // Destructor
            ~Sphere() = default;

            // Operators
            bool operator==(Sphere const &sphere) const;

            // Methods
            Sphere &operator=(Sphere const &sphere) = default;
            Sphere &operator=(Sphere &&sphere) = default;
            [[nodiscard]] std::optional<Math::Vector3D> hits(Ray const &ray) const;
            [[nodiscard]] Math::Vector3D normal(Math::Vector3D const &point) const;

            // Variables
            Math::Vector3D _center;
            Math::Vector3D _color;
            double _radius;
    };

} // RayTracer

#endif //BSRAYTRACER_SPHERE_HPP
