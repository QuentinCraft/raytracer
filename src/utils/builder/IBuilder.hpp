/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IBuilder
*/

#ifndef IBUILDER_HPP_
#define IBUILDER_HPP_
#include <iostream>
#include <memory>
#include "maths/Vector3D.hpp"
#include "objects/IObject.hpp"
#include "utils/config/data/IData.hpp"

namespace RayTracer {

    class IBuilder {
        public:
            virtual ~IBuilder() = default;
            virtual IBuilder &setTexture(std::shared_ptr<ITexture> const &texture) = 0;
            virtual IBuilder &setCenter(Math::Vector3D const &center) = 0;
            virtual IBuilder &setPoint(Math::Vector3D const &point) = 0;
            virtual IBuilder &setRadius(double radius) = 0;
            virtual IBuilder &setNormal(Math::Vector3D const &normal) = 0;
            virtual std::shared_ptr<RayTracer::IObject> build(int *globalId) = 0;
            virtual std::string &getBuilderName() = 0;
            virtual void reset() = 0;
            virtual std::unique_ptr<Utils::IData> createData() = 0;

            virtual IBuilder &applyData(std::unique_ptr<Utils::IData> &data) = 0;
    };

}

#endif /*IBUILDER_HPP_*/