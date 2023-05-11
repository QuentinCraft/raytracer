/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ConeData.hpp
*/
#ifndef CONEDATA_HPP_
#define CONEDATA_HPP_
#include "utils/config/data/AData.hpp"

namespace RayTracer {
    class ConeData : public Utils::AData {
        public:
            ConeData() : Utils::AData() {_type = "cone";};
            ~ConeData() {};
    };
}

#endif /*CONEDATA_HPP_*/
