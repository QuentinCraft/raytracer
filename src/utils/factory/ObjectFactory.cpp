/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ObjectFactory.cpp
*/

#include "ObjectFactory.hpp"

std::shared_ptr<RayTracer::IBuilder> RayTracer::Utils::ObjectFactory::createObjectBuilder(const std::string &type)
{
    for (auto &p : _builders) {
        std::cout << "builder : " << p->getBuilderName() << " addr : " << p.get() << std::endl;
    }
    for (auto &plugin : _builders) {
        if (plugin->getBuilderName() == type) {
            std::cout << "builder selected : " << plugin->getBuilderName() << " [" << plugin.get() << "]" << std::endl;
            return plugin;
        }
    }
    return nullptr;
}
