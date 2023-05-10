/*
** EPITECH PROJECT, 2023
** B-OOP-400-STG-4-1-raytracer-quentin.erdinger
** File description:
** Cone
*/

#pragma once

#include "maths/Vector3D.hpp"
#include "maths/Ray.hpp"
#include "maths/Utils.hpp"

#include "objects/AObject.hpp"

#include <iostream>
#include <optional>
#include <functional>

namespace RayTracer {

    class Cone : public AObject {
        public:
            // Constructors
            Cone(int *globalId);
            Cone(int *globalId, const Math::Vector3D& center, double radius, double height);
            Cone(Cone const &cone) = default;
            Cone(Cone &&cone) = default;

            // Destructor
            ~Cone() override = default;

            // Operators
            bool operator==(Cone const &cone) const;

            // Methods
            Cone &operator=(Cone const &cone) = default;
            Cone &operator=(Cone &&cone) = default;
            [[nodiscard]] std::optional<PipeLine> hits(Ray const &ray) const override;
            [[nodiscard]] Math::Vector3D normal(PipeLine const &pipe) const override;

            // Variables
            double _height;
            double _radius;
    };

} // RayTracer