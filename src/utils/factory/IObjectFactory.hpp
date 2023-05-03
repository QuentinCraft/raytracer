/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IObjectFactory.hpp
*/
#ifndef IOBJECTFACTORY_HPP_
#define IOBJECTFACTORY_HPP_
#include <iostream>
#include <memory>
#include "utils/builder/IBuilder.hpp"

namespace RayTracer::Utils {

    class IObjectFactory {
        public:
            virtual ~IObjectFactory() = default;
            virtual std::unique_ptr<RayTracer::IBuilder> createObjectBuilder(const std::string &type) = 0;
    };

}

#endif /*IOBJECTFACTORY_HPP_*/