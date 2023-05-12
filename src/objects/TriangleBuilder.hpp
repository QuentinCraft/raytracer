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
                printf("building triangle : ((%f, %f, %f), (%f, %f, %f), (%f, %f, %f))\n", _v1._x, _v1._y, _v1._z, _v2._x, _v2._y, _v2._z, _v3._x, _v3._y, _v3._z);
                printf("building (NORMAL) triangle : ((%f, %f, %f), (%f, %f, %f), (%f, %f, %f))\n", _n1._x, _n1._y, _n1._z, _n2._x, _n2._y, _n2._z, _n3._x, _n3._y, _n3._z);
                _object = std::make_shared<RayTracer::Triangle>(globalId, _v1, _v2, _v3, _n1, _n2, _n3, _texture);
                return std::move(_object);
            }

            std::unique_ptr<RayTracer::Utils::IData> createData() override
            {
                return std::make_unique<RayTracer::TriangleData>();
            }
    };
}

#endif /*TRIANGLEBUILDER_HPP_*/