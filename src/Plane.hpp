/*
** EPITECH PROJECT, 2023
** B-OOP-400-STG-4-1-raytracer-quentin.erdinger
** File description:
** Plane
*/

#ifndef PLAN_HPP_
#define PLAN_HPP_

#include "Vector3D.hpp"
#include <iostream>
#include <optional>
#include <functional>
#include "Vector3D.hpp"
#include "Ray.hpp"
#include "MathUtils.hpp"

namespace RayTracer {

    class Plane {
        public:
            // Constructors
            Plane();
            Plane(const Math::Vector3D& point, const Math::Vector3D& normal);
            Plane(Plane const &Plane) = default;
            Plane(Plane &&Plane) = default;

            // Destructor
            ~Plane() = default;

            // Operators
            bool operator==(Plane const &plane) const;

            // Methods
            Plane &operator=(Plane const &plane) = default;
            Plane &operator=(Plane &&plane) = default;
            [[nodiscard]] std::optional<Math::Vector3D> hits(Ray const &ray) const;
            [[nodiscard]] Math::Vector3D normal(Math::Vector3D const &point) const;
            [[nodiscard]] void getCoefficients(double &a, double &b, double &c, double &d) const;

            // Variables
            Math::Vector3D _point;
            Math::Vector3D _normal;
            Math::Vector3D _color = {200, 0, 0};
        };

} // RayTracer
#endif /* !PLAN_HPP_ */