/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** SphereBuilder.hpp
*/

#ifndef SPHEREBUILDER_HPP_
#define SPHEREBUILDER_HPP_
#include "utils/builder/ABuilder.hpp"
#include "Sphere.hpp"
#include "SphereData.hpp"

namespace RayTracer {

    class SphereBuilder : public ABuilder {
        public:
            SphereBuilder() : ABuilder("sphere") {};
            ~SphereBuilder() {};
            std::shared_ptr<RayTracer::IObject> build() override
            {
                _object = std::make_shared<RayTracer::Sphere>(_center, _radius, _color);
                return std::move(_object);
            }

            std::unique_ptr<RayTracer::Utils::IData> createData() override
            {
                return std::make_unique<RayTracer::SphereData>();
            }
    };

}

#endif /*SPHEREBUILDER_HPP_*/