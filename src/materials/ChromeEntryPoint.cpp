/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ChromeEntryPoint.cpp
*/

#include "Chrome.hpp"

extern "C"
{
    RayTracer::AMaterial *entryPoint(void)
    {
        return new RayTracer::Chrome();
    }
}