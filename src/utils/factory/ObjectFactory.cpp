/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ObjectFactory.cpp
*/

#include "ObjectFactory.hpp"

std::unique_ptr<RayTracer::IObject> RayTracer::Utils::ObjectFactory::createObject(std::string &type)
{
    if (type == "sphere")
        return _createSphere();
    if (type == "plane")
        return _createPlane();
    return nullptr;
}

std::unique_ptr<RayTracer::IObject> RayTracer::Utils::ObjectFactory::_createSphere()
{
    return std::make_unique<RayTracer::Sphere>();
}

std::unique_ptr<RayTracer::IObject> RayTracer::Utils::ObjectFactory::_createPlane()
{
    return std::make_unique<RayTracer::Plane>();
}
