/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ChessBoardEntryPoint.cpp
*/

#include "ITextureBuilder.hpp"
#include "ChessBoardBuilder.hpp"
#include <memory>

extern "C"
{
    RayTracer::ITextureBuilder *entryPoint(void)
    {
        return new RayTracer::ChessBoardBuilder();
    }
}
