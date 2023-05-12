/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** TriangleEntryPoint.cpp
*/

#include "utils/builder/IBuilder.hpp"
#include "TriangleBuilder.hpp"

extern "C"
{
    RayTracer::IBuilder *entryPoint(void)
    {
        return new RayTracer::TriangleBuilder();
    }
}