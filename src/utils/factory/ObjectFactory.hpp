/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ObjectFactory.hpp
*/

#ifndef OBJECTFACTORY_HPP_
#define OBJECTFACTORY_HPP_
#include <iostream>
#include <memory>
#include "utils/builder/IBuilder.hpp"
#include "objects/SphereBuilder.hpp"
#include "objects/PlaneBuilder.hpp"

namespace RayTracer::Utils {

    class ObjectFactory {
        public:
            ObjectFactory() {};
            ~ObjectFactory() {};
            static std::unique_ptr<RayTracer::IBuilder> createObjectBuilder(std::string &type);
        private:
            static std::unique_ptr<RayTracer::IBuilder> _createSphere();
            static std::unique_ptr<RayTracer::IBuilder> _createPlane();
    };

}

#endif /*OBJECTFACTORY_HPP_*/