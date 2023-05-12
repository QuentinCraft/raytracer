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
#include "texture/ATexture.hpp"

namespace RayTracer::Utils {

    class IData {
        public:
            virtual ~IData() = default;

            virtual void setType(std::string type) = 0;
            virtual void setTexture(std::shared_ptr<ITexture> texture) = 0;
            virtual void setCenter(Math::Vector3D center) = 0;
            virtual void setPoint(Math::Vector3D point) = 0;
            virtual void setNormal(Math::Vector3D normal) = 0;
            virtual void setRadius(double radius) = 0;
            virtual void setIntensity(const Math::Vector3D intensity) = 0;
            virtual void setLength(double length) = 0;
            virtual void setV1(Math::Vector3D v1) = 0;
            virtual void setV2(Math::Vector3D v2) = 0;
            virtual void setV3(Math::Vector3D v3) = 0;
            virtual void setN1(Math::Vector3D n1) = 0;
            virtual void setN2(Math::Vector3D n2) = 0;
            virtual void setN3(Math::Vector3D n3) = 0;
            virtual void setAxe(const Math::Vector3D axe) = 0;
            virtual void setAngle(double angle) = 0;

            virtual std::string &getType() = 0;
            virtual std::shared_ptr<ITexture> &getTexture() = 0;
            virtual Math::Vector3D &getCenter() = 0;
            virtual Math::Vector3D &getPoint() = 0;
            virtual Math::Vector3D &getNormal() = 0;
            virtual double &getRadius() = 0;
            virtual Math::Vector3D &getIntensity() = 0;
            virtual double &getLength() = 0;
            virtual Math::Vector3D &getV1() = 0;
            virtual Math::Vector3D &getV2() = 0;
            virtual Math::Vector3D &getV3() = 0;
            virtual Math::Vector3D &getN1() = 0;
            virtual Math::Vector3D &getN2() = 0;
            virtual Math::Vector3D &getN3() = 0;
            virtual Math::Vector3D &getAxe() = 0;
            virtual double &getAngle() = 0;
    };

}

#endif /*IDATA_HPP_*/