/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IObject.hpp
*/

#ifndef IOBJECT_HPP_
#define IOBJECT_HPP_

#include "maths/Vector3D.hpp"
#include "maths/Ray.hpp"

#include <optional>
#include <functional>

namespace RayTracer {
    struct PipeLine;

    class IObject {
        public:
            virtual ~IObject() = default;

            [[nodiscard]] virtual std::optional<PipeLine> hits(Ray const &ray) const = 0;
            [[nodiscard]] virtual Math::Vector3D normal(PipeLine const &pipe) const = 0;


            [[nodiscard]] virtual double getId() const = 0;
            virtual void setId(double id) = 0;

            [[nodiscard]] virtual const Math::Vector3D &getOrigin() const = 0;
            virtual void setOrigin(const Math::Vector3D &origin) = 0;

            [[nodiscard]] virtual const Math::Vector3D &getColor() const = 0;
            virtual void setColor(const Math::Vector3D &color) = 0;

            [[nodiscard]] virtual const Math::Vector3D &getRotation() const = 0;
            virtual void setRotation(const Math::Vector3D &rotation) = 0;

            [[nodiscard]] virtual const Math::Vector3D &getScale() const = 0;
            virtual void setScale(const Math::Vector3D &scale) = 0;

    }; // RayTracer

}

#endif //IOBJECT_HPP_
