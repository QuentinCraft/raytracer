/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Triangle.hpp
*/

#ifndef BSRAYTRACER_TRIANGLE_HPP
#define BSRAYTRACER_TRIANGLE_HPP

#include "maths/Vector3D.hpp"
#include "maths/Ray.hpp"
#include "maths/Utils.hpp"

#include "objects/AObject.hpp"

#include <iostream>
#include <optional>
#include <functional>

namespace RayTracer {

    class Triangle : public AObject {
    public:
        // Constructors
        Triangle(int *globalId);
        Triangle(int *globalId, const Math::Vector3D& point, const Math::Vector3D& v1, const Math::Vector3D& v2, const Math::Vector3D& v3, const Math::Vector3D& n1, const Math::Vector3D& n2, const Math::Vector3D& n3, const std::shared_ptr<ITexture>& texture);
        Triangle(Triangle const &Triangle) = default;
        Triangle(Triangle &&Triangle) = default;

        // Destructor
        ~Triangle() override = default;

        // Operators
        bool operator==(Triangle const &Triangle) const;

        // Methods
        Triangle &operator=(Triangle const &Triangle) = default;
        Triangle &operator=(Triangle &&Triangle) = default;
        [[nodiscard]] std::optional<PipeLine> hits(Ray const &ray) const override;
        [[nodiscard]] Math::Vector3D normal(PipeLine const &pipe) const override;

        // Variables
        std::array<Math::Vector3D, 3> _vertices;
        std::array<Math::Vector3D, 3> _normals;
    };

} // RayTracer

#endif //BSRAYTRACER_TRIANGLE_HPP