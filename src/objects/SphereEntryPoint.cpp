/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** SphereEntryPoint.cpp
*/

#include "utils/builder/IBuilder.hpp"
#include "SphereBuilder.hpp"

extern "C"
{
    std::unique_ptr<RayTracer::IBuilder> entryPoint(void)
    {
        return std::make_unique<RayTracer::SphereBuilder>();
    }

    std::unique_ptr<RayTracer::Utils::IData> createData(void)
    {
        return std::make_unique<RayTracer::SphereData>();
    }
}
