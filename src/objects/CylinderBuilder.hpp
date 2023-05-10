/*
** EPITECH PROJECT, 2023
** CylinderBuilder.hpp
** File description:
** CylinderBuilder
*/

#ifndef CYLINDERBUILDER_HPP_
#define CYLINDERBUILDER_HPP_
#include "utils/builder/ABuilder.hpp"
#include "Cylinder.hpp"
#include "CylinderData.hpp"
#include <iostream>

namespace RayTracer {

    class CylinderBuilder : public ABuilder {
        public:
            CylinderBuilder() : ABuilder("cylinder") {_builderName = "cylinder";};
            ~CylinderBuilder() {};

            std::shared_ptr<RayTracer::IObject> build(int *globalId) override
            {
                _object = std::make_shared<RayTracer::Cylinder>(globalId, _center, _radius, _length, _texture);
                return std::move(_object);
            }

            std::unique_ptr<RayTracer::Utils::IData> createData() override
            {
                return std::make_unique<RayTracer::CylinderData>();
            }
    };

}
#endif /* !CYLINDERBUILDER_HPP_ */
