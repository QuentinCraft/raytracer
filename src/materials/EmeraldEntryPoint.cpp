/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** EmeraldEntryPoint.cpp
*/

#include "Emerald.hpp"

extern "C"
{
RayTracer::AMaterial *entryPoint(void)
{
    return new RayTracer::Emerald();
}
}