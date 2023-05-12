/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** TriangleData.hpp
*/
#ifndef TRIANGLEDATA_HPP_
#define TRIANGLEDATA_HPP_
#include "utils/config/data/AData.hpp"

namespace RayTracer {
    class TriangleData : public Utils::AData {
        public:
            TriangleData() : Utils::AData() {_type = "triangle";};
            ~TriangleData() {};
    };
}

#endif /*TRIANGLEDATA_HPP_*/