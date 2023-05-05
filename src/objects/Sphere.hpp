/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Sphere.hpp
*/

#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "maths/Vector3D.hpp"
#include "maths/Ray.hpp"
#include "maths/Utils.hpp"
#include "AObject.hpp"
#include "PipeLine.hpp"

#include <iostream>
#include <optional>
#include <functional>

namespace RayTracer {

    class Sphere : public AObject {
        public:
            // Constructors
            Sphere();
            Sphere(const Math::Vector3D& center, double radius, const Math::Vector3D& color);
            Sphere(Sphere const &sphere) = default;
            Sphere(Sphere &&sphere) = default;

            // Destructor
            ~Sphere() override {};

            // Operators
            bool operator==(Sphere const &sphere) const;

            // Methods
            Sphere &operator=(Sphere const &sphere) = default;
            Sphere &operator=(Sphere &&sphere) = default;
            [[nodiscard]] std::optional<PipeLine> hits(Ray const &ray) const override;
            [[nodiscard]] Math::Vector3D normal(PipeLine const &pipe) const override;

            // Variables
            double _radius;
    };

} // RayTracer

#endif //SPHERE_HPP
