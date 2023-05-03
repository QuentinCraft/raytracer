/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Cylinder.hpp
*/

#ifndef BSRAYTRACER_CYLINDER_HPP
#define BSRAYTRACER_CYLINDER_HPP

#include "maths/Vector3D.hpp"
#include "maths/Ray.hpp"
#include "maths/Utils.hpp"

#include "objects/AObject.hpp"

#include <iostream>
#include <optional>
#include <functional>

namespace RayTracer {

    class Cylinder : public AObject {
        public:
            // Constructors
            Cylinder();
            Cylinder(const Math::Vector3D& center, double radius, double length, const Math::Vector3D& color);
            Cylinder(Cylinder const &cylinder) = default;
            Cylinder(Cylinder &&cylinder) = default;

            // Destructor
            ~Cylinder() override = default;

            // Operators
            bool operator==(Cylinder const &cylinder) const;

            // Methods
            Cylinder &operator=(Cylinder const &cylinder) = default;
            Cylinder &operator=(Cylinder &&cylinder) = default;
            [[nodiscard]] std::optional<PipeLine> hits(Ray const &ray) const override;
            [[nodiscard]] Math::Vector3D normal(PipeLine const &pipe) const override;

            // Variables
            double _length;
            double _radius;
    };

} // RayTracer

#endif //BSRAYTRACER_CYLINDER_HPP
