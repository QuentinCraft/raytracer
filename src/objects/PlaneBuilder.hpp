/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneBuilder.hpp
*/
#ifndef PLANEBUILDER_HPP_
#define PLANEBUILDER_HPP_
#include "utils/builder/ABuilder.hpp"
#include "Plane.hpp"
#include "PlaneData.hpp"

namespace RayTracer {

    class PlaneBuilder : public ABuilder  {
        public:
            PlaneBuilder() : ABuilder("plane") {};
            ~PlaneBuilder() {};
            std::shared_ptr<RayTracer::IObject> build() override
            {
                _object = std::make_unique<RayTracer::Plane>(_point, _normal);
                return std::move(_object);
            }

            std::unique_ptr<RayTracer::Utils::IData> createData() override
            {
                return std::make_unique<RayTracer::PlaneData>();
            }
    };

};

#endif /*PLANEBUILDER_HPP_*/