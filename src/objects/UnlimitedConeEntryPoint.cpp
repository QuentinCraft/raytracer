/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ConeEntryPoint.cpp
*/

#include "utils/builder/IBuilder.hpp"
#include "UnlimitedConeBuilder.hpp"

extern "C"
{
    RayTracer::IBuilder *entryPoint(void)
    {
        return new RayTracer::UnlimitedConeBuilder();
    }
}