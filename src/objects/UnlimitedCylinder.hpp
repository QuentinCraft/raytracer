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

    class UnlimitedCylinder : public AObject {
        public:
            // Constructors
            UnlimitedCylinder(int *globalId);
            UnlimitedCylinder(int *globalId, const Math::Vector3D& center, double radius, const Math::Vector3D& rotationAxis, double rotationAngle, const std::shared_ptr<ITexture>& texture);
            UnlimitedCylinder(const Math::Vector3D& center, double radius, const Math::Vector3D& rotationAxis, double rotationAngle, const Math::Vector3D& color);

            UnlimitedCylinder(UnlimitedCylinder const &cylinder) = default;
            UnlimitedCylinder(UnlimitedCylinder &&cylinder) = default;

            // Destructor
            ~UnlimitedCylinder() override = default;

            // Operators
            bool operator==(UnlimitedCylinder const &cylinder) const;

            // Methods
            UnlimitedCylinder &operator=(UnlimitedCylinder const &cylinder) = default;
            UnlimitedCylinder &operator=(UnlimitedCylinder &&cylinder) = default;
            [[nodiscard]] std::optional<PipeLine> hits(Ray const &ray) const override;
            [[nodiscard]] Math::Vector3D normal(PipeLine const &pipe) const override;

            // Variables
            double _length;
            double _radius;
            Math::Vector3D _rotationAxis;
            double _rotationAngle;
    };

} // RayTracer

#endif //BSRAYTRACER_CYLINDER_HPP
