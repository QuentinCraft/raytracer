/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneEntryPoint.cpp
*/

#include "utils/builder/IBuilder.hpp"
#include "PlaneBuilder.hpp"
#include <memory>

extern "C"
{
    std::unique_ptr<RayTracer::IBuilder> entryPoint(void)
    {
         return std::make_unique<RayTracer::PlaneBuilder>();
    }
}
