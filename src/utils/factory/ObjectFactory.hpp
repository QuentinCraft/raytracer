/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ObjectFactory.hpp
*/

#ifndef OBJECTFACTORY_HPP_
#define OBJECTFACTORY_HPP_
#include "IObjectFactory.hpp"
#include "objects/SphereBuilder.hpp"
#include "objects/PlaneBuilder.hpp"

namespace RayTracer::Utils {

    class ObjectFactory : public IObjectFactory {
        public:
            ObjectFactory() = default;
            ~ObjectFactory() override = default;
            std::unique_ptr<RayTracer::IBuilder> createObjectBuilder(std::string &type) override;
        private:
            static std::unique_ptr<RayTracer::IBuilder> _createSphere();
            static std::unique_ptr<RayTracer::IBuilder> _createPlane();
    };

}

#endif /*OBJECTFACTORY_HPP_*/