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
    std::unique_ptr<RayTracer::IBuilder> entryPoint(void)
    {
        return std::make_unique<RayTracer::CylinderBuilder>();
    }
}
