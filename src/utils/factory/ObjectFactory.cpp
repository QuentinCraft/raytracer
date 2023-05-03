/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ObjectFactory.cpp
*/

#include "ObjectFactory.hpp"

RayTracer::IBuilder *RayTracer::Utils::ObjectFactory::createObjectBuilder(const std::string &type)
{
    for (auto &plugin : _builders) {
        if (plugin->getBuilderName() == type) {
            return plugin.get();
        }
    }
    return nullptr;
}
