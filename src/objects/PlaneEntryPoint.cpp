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
    RayTracer::IBuilder *entryPoint(void)
    {
        std::cout << "je  test" << std::endl;
        return new RayTracer::PlaneBuilder();
    }
}
