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
#include "texture/ITextureBuilder.hpp"

namespace RayTracer::Utils {

    class IObjectFactory {
        public:
            virtual ~IObjectFactory() = default;
            virtual std::shared_ptr<RayTracer::IBuilder> createObjectBuilder(const std::string &type) = 0;
            virtual std::shared_ptr<RayTracer::AMaterial> createMaterial(const std::string &type) = 0;
            virtual std::shared_ptr<RayTracer::ITextureBuilder> createTextureBuilder(const std::string &type) = 0;
    };

}

#endif /*IOBJECTFACTORY_HPP_*/