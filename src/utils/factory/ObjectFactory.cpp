/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ObjectFactory.cpp
*/

#include "ObjectFactory.hpp"

std::unique_ptr<RayTracer::IBuilder> RayTracer::Utils::ObjectFactory::createObjectBuilder(const std::string &type)
{
    if (type == "sphere")
        return _createSphere();
    if (type == "plane")
        return _createPlane();
    return nullptr;
}

std::unique_ptr<RayTracer::IBuilder> RayTracer::Utils::ObjectFactory::_createSphere()
{
    return std::make_unique<RayTracer::SphereBuilder>();
}

std::unique_ptr<RayTracer::IBuilder> RayTracer::Utils::ObjectFactory::_createPlane()
{
    return std::make_unique<RayTracer::PlaneBuilder>();
}
