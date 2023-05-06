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

namespace RayTracer {

    class PlaneBuilder : public ABuilder  {
        public:
            PlaneBuilder() : ABuilder("plane") {};
            ~PlaneBuilder() {};
            std::unique_ptr<RayTracer::IObject> build() override
            {
                _object = std::make_unique<RayTracer::Plane>(_point, _normal);
                return std::move(_object);
            }
    };

};

#endif /*PLANEBUILDER_HPP_*/