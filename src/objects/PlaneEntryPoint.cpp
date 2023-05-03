/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneEntryPoint.cpp
*/

#include "utils/builder/IBuilder.hpp"
#include "PlaneBuilder.hpp"

extern "C"
{
    RayTracer::IBuilder *entryPoint(void)
    {
        RayTracer::PlaneBuilder *newObject = new RayTracer::PlaneBuilder();

        return newObject;
    }
}
