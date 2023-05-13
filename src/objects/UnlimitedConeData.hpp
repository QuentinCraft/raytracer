/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** UnlimitedConeData.hpp
*/
#ifndef CONEDATA_HPP_
#define CONEDATA_HPP_
#include "utils/config/data/AData.hpp"

namespace RayTracer {
    class UnlimitedConeData : public Utils::AData {
        public:
            UnlimitedConeData() : Utils::AData() {_type = "cone";};
            ~UnlimitedConeData() {};
    };
}

#endif /*CONEDATA_HPP_*/
