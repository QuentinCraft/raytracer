/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** AObject.hpp
*/

#ifndef AOBJECT_HPP_
#define AOBJECT_HPP_

#include "IObject.hpp"
#include "lights/Spot.hpp"

namespace RayTracer {
    class AObject : public IObject {
        public:

            // Constructors
            AObject() {
                _id = 0;
                _origin = Math::Vector3D();
                _color = Math::Vector3D();
                _rotation = Math::Vector3D();
                _scale = Math::Vector3D();
            }

            AObject(double id, const Math::Vector3D& origin, const Math::Vector3D& color, const Math::Vector3D& rotation, const Math::Vector3D& scale) {
                _id = id;
                _origin = origin;
                _color = color;
                _rotation = rotation;
                _scale = scale;
            }

            // Destructors
            ~AObject() override = default;

            // Getters / Setters
            [[nodiscard]] double getId() const override { return _id; }
            void setId(double id) override { _id =  id; }

            [[nodiscard]] const Math::Vector3D &getOrigin() const override { return _origin; }
            void setOrigin(const Math::Vector3D &origin) override { _origin =  origin; }

            [[nodiscard]] const Math::Vector3D &getColor() const override { return _color; }
            void setColor(const Math::Vector3D &color) override { _color =  color; }

            [[nodiscard]] const Math::Vector3D &getRotation() const override { return _rotation; }
            void setRotation(const Math::Vector3D &rotation) override { _rotation =  rotation; }

            [[nodiscard]] const Math::Vector3D &getScale() const override { return _scale; }
            void setScale(const Math::Vector3D &scale) override { _scale =  scale; }

            bool operator==(const AObject &other) const {
                return _id == other._id && _origin == other._origin && _color == other._color && _rotation == other._rotation && _scale == other._scale;
            }

        protected:
            double _id;
            Math::Vector3D _origin;
            Math::Vector3D _color;
            Math::Vector3D _rotation;
            Math::Vector3D _scale;
    };
}

#endif /*AOBJECT_HPP_*/
