/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** UnlimitedConeBuilder.hpp
*/
#ifndef CONEBUILDER_HPP_
#define CONEBUILDER_HPP_
#include "utils/builder/ABuilder.hpp"
#include "UnlimitedCone.hpp"
#include "UnlimitedConeData.hpp"
#include <iostream>

namespace RayTracer {

    class UnlimitedConeBuilder : public ABuilder {
        public:
            UnlimitedConeBuilder() : ABuilder("unlimitedCone") {};
            ~UnlimitedConeBuilder() {};

            std::shared_ptr<RayTracer::IObject> build(int *globalId) override
            {
                _object = std::make_shared<RayTracer::UnlimitedCone>(globalId, _center, _radius, _axe, _angle, _texture);
                return std::move(_object);
            }

            std::unique_ptr<RayTracer::Utils::IData> createData() override
            {
                return std::make_unique<RayTracer::UnlimitedConeData>();
            }
    };

}

#endif /*CONEBUILDER_HPP_*/