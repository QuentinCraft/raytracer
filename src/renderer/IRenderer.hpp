/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IRenderer.hpp
*/

#ifndef RAYTRACER_IRENDERER_HPP
#define RAYTRACER_IRENDERER_HPP

#include <iostream>
#include <memory>
#include "scenes/Scene.hpp"

namespace RayTracer {

    class IRenderer {
        public:
            virtual ~IRenderer() = default;
            virtual void build(std::unique_ptr<RayTracer::Scene> &scene, bool fast) = 0;
    };

} // RayTracer

#endif //RAYTRACER_IRENDERER_HPP
