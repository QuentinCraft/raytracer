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
    RayTracer::IBuilder *entryPoint(void)
    {
        RayTracer::SphereBuilder *newObject = new RayTracer::SphereBuilder();

        return newObject;
    }
}
