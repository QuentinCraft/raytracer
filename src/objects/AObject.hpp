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
#include "texture/ATexture.hpp"

extern int globalId;

namespace RayTracer {
    class AObject : public IObject {
        public:

            // Constructors
            AObject() {
                _id = globalId++;
                _origin = Math::Vector3D();
                _rotation = Math::Vector3D();
                _scale = Math::Vector3D();
            }

            AObject(double id, const Math::Vector3D& origin, const Math::Vector3D& color, const Math::Vector3D& rotation, const Math::Vector3D& scale) {
                _id = globalId++;
                _origin = origin;
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

            [[nodiscard]] const Math::Vector3D &getRotation() const override { return _rotation; }
            void setRotation(const Math::Vector3D &rotation) override { _rotation =  rotation; }

            [[nodiscard]] const Math::Vector3D &getScale() const override { return _scale; }
            void setScale(const Math::Vector3D &scale) override { _scale =  scale; }

            [[nodiscard]] const std::shared_ptr<ITexture> &getTexture() const { return _texture; }

            void setTexture(const std::shared_ptr<ITexture> &texture) { _texture = texture; }
    protected:
        double _id;
        Math::Vector3D _origin;
        Math::Vector3D _rotation;
        Math::Vector3D _scale;
        std::shared_ptr<ITexture> _texture;
    };
}

#endif /*AOBJECT_HPP_*/
