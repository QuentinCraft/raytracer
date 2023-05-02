/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IBuilder
*/

#ifndef IBUILDER_HPP_
#define IBUILDER_HPP_
#include <iostream>
#include <memory>

namespace RayTracer {

    class IBuilder {
        public:
            virtual ~IBuilder() = default;
            virtual IBuilder &setColor(Math::Vector3D const &color) = 0;
            virtual IBuilder &setCenter(Math::Vector3D const &center) = 0;
            virtual IBuilder &setPoint(Math::Vector3D const &point) = 0;
            virtual IBuilder &setRadius(double radius) = 0;
            virtual IBuilder &setNormal(Math::Vector3D const &normal) = 0;
            virtual std::unique_ptr<RayTracer::IObject> build() = 0;
    };

}

#endif /*IBUILDER_HPP_*/