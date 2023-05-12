/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** TriangleBuilder.hpp
*/
#ifndef TRIANGLEBUILDER_HPP_
#define TRIANGLEBUILDER_HPP_
#include "utils/builder/ABuilder.hpp"
#include "Triangle.hpp"
#include "TriangleData.hpp"
#include <iostream>

namespace RayTracer {
    class TriangleBuilder : public ABuilder {
        public:
            TriangleBuilder() : ABuilder("triangle") {};
            ~TriangleBuilder() {};

            std::shared_ptr<RayTracer::IObject> build(int *globalId) override
            {
                _object = std::make_shared<RayTracer::Triangle>(globalId, _point, _v1, _v2, _v3, _n1, _n2, _n3, _texture);
                return std::move(_object);
            }

            std::unique_ptr<RayTracer::Utils::IData> createData() override
            {
                return std::make_unique<RayTracer::TriangleData>();
            }
    };
}

#endif /*TRIANGLEBUILDER_HPP_*/