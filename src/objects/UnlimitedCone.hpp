/*
** EPITECH PROJECT, 2023
** B-OOP-400-STG-4-1-raytracer-quentin.erdinger
** File description:
** UnlimitedCone
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

    class UnlimitedCone : public AObject {
        public:
            // Constructors
            UnlimitedCone(int *globalId);
            UnlimitedCone(int *globalId, const Math::Vector3D& center, double radius, const Math::Vector3D& rotationAxis, double rotationAngle, const std::shared_ptr<ITexture>& texture);
            UnlimitedCone(UnlimitedCone const &cone) = default;
            UnlimitedCone(UnlimitedCone &&cone) = default;

            // Destructor
            ~UnlimitedCone() override = default;

            // Operators
            bool operator==(UnlimitedCone const &cone) const;

            // Methods
            UnlimitedCone &operator=(UnlimitedCone const &cone) = default;
            UnlimitedCone &operator=(UnlimitedCone &&cone) = default;
            [[nodiscard]] std::optional<PipeLine> hits(Ray const &ray) const override;
            [[nodiscard]] Math::Vector3D normal(PipeLine const &pipe) const override;

            // Variables
            double _radius;
            Math::Vector3D _rotationAxis;
            double _rotationAngle;
    };

} // RayTracer