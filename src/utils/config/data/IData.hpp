/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IData.hpp
*/

#ifndef IDATA_HPP_
#define IDATA_HPP_
#include <iostream>
#include "maths/Vector3D.hpp"

namespace RayTracer::Utils {

    class IData {
        public:
            virtual ~IData() = default;

            virtual void setType(std::string type) = 0;
            virtual void setColor(Math::Vector3D color) = 0;
            virtual void setCenter(Math::Vector3D center) = 0;
            virtual void setPoint(Math::Vector3D point) = 0;
            virtual void setNormal(Math::Vector3D normal) = 0;
            virtual void setRadius(double radius) = 0;
            virtual void setAxis(const std::string &axis) = 0;

            virtual std::string &getType() = 0;
            virtual Math::Vector3D &getColor() = 0;
            virtual Math::Vector3D &getCenter() = 0;
            virtual Math::Vector3D &getPoint() = 0;
            virtual Math::Vector3D &getNormal() = 0;
            virtual double &getRadius() = 0;
            virtual std::string &getAxis() = 0;
    };

}

#endif /*IDATA_HPP_*/