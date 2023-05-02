/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ABuilder.hpp
*/

#ifndef ABUILDER_HPP_
#define ABUILDER_HPP_
#include "IBuilder.hpp"
#include "objects/IObject.hpp"
#include "maths/Vector3D.hpp"

namespace RayTracer {

    class ABuilder : public IBuilder {
        public:
            ABuilder() {};
            ~ABuilder() {};

            IBuilder &setColor(Math::Vector3D const &color) override
            {
                _color = color;
                return *this;
            }
            IBuilder &setCenter(Math::Vector3D const &center) override
            {
                _center = center;
                return *this;
            }
            IBuilder &setPoint(Math::Vector3D const &point) override
            {
                _point = point;
                return *this;
            }
            IBuilder &setRadius(double radius) override
            {
                _radius = radius;
                return *this;
            }
            IBuilder &setNormal(Math::Vector3D const &normal) override
            {
                _normal = normal;
                return *this;
            }
            std::unique_ptr<RayTracer::IObject> build() override
            {
                return std::move(_object);
            }
        protected:
            Math::Vector3D _color;
            Math::Vector3D _center;
            Math::Vector3D _point;
            Math::Vector3D _normal;
            double _radius;
            std::unique_ptr<RayTracer::IObject> _object;
    };

}

#endif /*ABUILDER_HPP_*/