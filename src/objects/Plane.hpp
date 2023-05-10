/*
** EPITECH PROJECT, 2023
** B-OOP-400-STG-4-1-raytracer-quentin.erdinger
** File description:
** Plane
*/

#ifndef PLAN_HPP_
#define PLAN_HPP_

#include <iostream>
#include <optional>
#include <functional>
#include "maths/Vector3D.hpp"
#include "maths/Ray.hpp"
#include "maths/Utils.hpp"
#include "AObject.hpp"

namespace RayTracer {

    class Plane : public AObject {
        public:
            // Constructors
            Plane(int *globalId);
            Plane(int *globalId, const Math::Vector3D& point, const Math::Vector3D& normal);
            Plane(int *globalId, const Math::Vector3D& point, const Math::Vector3D& normal, const std::shared_ptr<ITexture>& texture);
            Plane(Plane const &Plane) = default;
            Plane(Plane &&Plane) = default;

            // Destructor
            ~Plane() override = default;

            // Operators
            bool operator==(Plane const &plane) const;

            // Methods
            Plane &operator=(Plane const &plane) = default;
            Plane &operator=(Plane &&plane) = default;
            [[nodiscard]] std::optional<PipeLine> hits(Ray const &ray) const override;
            [[nodiscard]] Math::Vector3D normal(PipeLine const &pipe) const override;

            // Variables
            Math::Vector3D _normal;
        };

} // RayTracer
#endif /* !PLAN_HPP_ */