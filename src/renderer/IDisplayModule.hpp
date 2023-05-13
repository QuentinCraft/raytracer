/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IDisplayModule.hpp
*/
#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_
#include <iostream>
#include "maths/Vector3D.hpp"

namespace RayTracer
{
    class IDisplayModule
    {
        public:
            virtual ~IDisplayModule() = default;
            virtual void draw(Math::Vector3D &pos, Math::Vector3D &color) = 0;
            virtual void display() = 0;
            virtual void clear() = 0;
            virtual bool isOpen() = 0;
            virtual void close() = 0;
            virtual void eventHandler() = 0;
    };
}

#endif /*IDISPLAYMODULE_HPP_*/