/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** SphereData.hpp
*/

#ifndef SPHEREDATA_HPP_
#define SPHEREDATA_HPP_
#include "utils/config/data/AData.hpp"

namespace RayTracer {

    class SphereData : public Utils::AData {
        public:
            SphereData() : Utils::AData() {_type = "sphere";};
            ~SphereData() {};
    };
}

#endif /*SPHEREDATA_HPP_*/
