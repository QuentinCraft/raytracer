/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** SphereBuilder.hpp
*/

#ifndef SPHEREBUILDER_HPP_
#define SPHEREBUILDER_HPP_
#include "ABuilder.hpp"
#include "Sphere.hpp"

namespace RayTracer {

    class SphereBuilder : public ABuilder {
        public:
            SphereBuilder() : ABuilder() {};
            ~SphereBuilder() {};
            std::unique_ptr<RayTracer::IObject> build()
            {
                _object = std::make_unique<RayTracer::Sphere>(_center, _radius, _color);
                return std::move(_object);
            }
    };

}

#endif /*SPHEREBUILDER_HPP_*/