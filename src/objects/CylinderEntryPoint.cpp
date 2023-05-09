/*
** EPITECH PROJECT, 2023
** CylinderEntryPoint.cpp
** File description:
** CylinderEntryPoint
*/

#include "utils/builder/IBuilder.hpp"
#include "CylinderBuilder.hpp"

extern "C"
{
    RayTracer::IBuilder *entryPoint(void)
    {
        return new RayTracer::CylinderBuilder();
    }
}
