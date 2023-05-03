/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneData.hpp
*/

#ifndef PLANEDATA_HPP_
#define PLANEDATA_HPP_
#include "utils/config/data/AData.hpp"

namespace RayTracer {

    class PlaneData : public Utils::AData {
        public:
            PlaneData() : Utils::AData() {_type = "plane";};
            ~PlaneData() {};
    };

}

#endif /*PLANEDATA_HPP_*/
