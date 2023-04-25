/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Sphere.hpp
*/

#ifndef BSRAYTRACER_SPHERE_HPP
#define BSRAYTRACER_SPHERE_HPP

#include "Point3D.hpp"
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
            Sphere(const Math::Point3D& center, double radius);
            Sphere(Sphere const &sphere) = default;
            Sphere(Sphere &&sphere) = default;

            // Destructor
            ~Sphere() = default;

            // Methods
            [[nodiscard]] std::optional<Math::Point3D> hits(Ray const &ray) const;
            [[nodiscard]] Math::Vector3D normal(Math::Point3D const &point) const;

            // Variables
            Math::Point3D _center;
            double _radius;
    };

} // RayTracer

#endif //BSRAYTRACER_SPHERE_HPP
