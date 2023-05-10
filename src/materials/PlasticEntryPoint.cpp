/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlasticEntryPoint.cpp
*/

#include "Plastic.hpp"

extern "C"
{
RayTracer::AMaterial *entryPoint(void)
{
    return new RayTracer::Plastic();
}
}