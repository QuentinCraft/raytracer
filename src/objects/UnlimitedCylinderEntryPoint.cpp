/*
** EPITECH PROJECT, 2023
** UnlimitedCylinderEntryPoint.cpp
** File description:
** UnlimitedCylinderEntryPoint
*/

#include "utils/builder/IBuilder.hpp"
#include "UnlimitedCylinderBuilder.hpp"

extern "C"
{
    RayTracer::IBuilder *entryPoint(void)
    {
        return new RayTracer::UnlimitedCylinderBuilder();
    }
}
