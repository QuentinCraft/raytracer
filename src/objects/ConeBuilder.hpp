/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ConeBuilder.hpp
*/
#ifndef CONEBUILDER_HPP_
#define CONEBUILDER_HPP_
#include "utils/builder/ABuilder.hpp"
#include "Cone.hpp"
#include "ConeData.hpp"
#include <iostream>

namespace RayTracer {

    class ConeBuilder : public ABuilder {
        public:
            ConeBuilder() : ABuilder("cone") {};
            ~ConeBuilder() {};

            std::shared_ptr<RayTracer::IObject> build(int *globalId) override
            {
                _object = std::make_shared<RayTracer::Cone>(globalId, _center, _radius, _length, _texture);
                return std::move(_object);
            }

            std::unique_ptr<RayTracer::Utils::IData> createData() override
            {
                return std::make_unique<RayTracer::ConeData>();
            }
    };

}

#endif /*CONEBUILDER_HPP_*/