/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** SoloEntryPoint.cpp
*/

#include "ITextureBuilder.hpp"
#include "SoloBuilder.hpp"
#include <memory>

extern "C"
{
    RayTracer::ITextureBuilder *entryPoint(void)
    {
        return new RayTracer::SoloBuilder();
    }
}
