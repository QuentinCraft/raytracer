/*
** EPITECH PROJECT, 2023
** UnlimitedCylinderBuilder.hpp
** File description:
** UnlimitedCylinderBuilder
*/

#ifndef UNLIMITEDCYLINDERBUILDER_HPP_
#define UNLIMITEDCYLINDERBUILDER_HPP_
#include "utils/builder/ABuilder.hpp"
#include "UnlimitedCylinder.hpp"
#include "UnlimitedCylinderData.hpp"

namespace RayTracer {

    class UnlimitedCylinderBuilder : public ABuilder {
        public:
            UnlimitedCylinderBuilder() : ABuilder("unlimitedCylinder") {};
            ~UnlimitedCylinderBuilder() {};

            std::shared_ptr<RayTracer::IObject> build(int *globalId) override
            {
                _object = std::make_shared<RayTracer::UnlimitedCylinder>(globalId, _center, _radius, _axe, _angle, _texture);
                return std::move(_object);
            }

            std::unique_ptr<RayTracer::Utils::IData> createData() override
            {
                return std::make_unique<RayTracer::UnlimitedCylinderData>();
            }
    };

}

#endif /* !UNLIMITEDCYLINDERBUILDER_HPP_ */
