/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IRenderer.hpp
*/

#ifndef RAYTRACER_IRENDERER_HPP
#define RAYTRACER_IRENDERER_HPP

namespace RayTracer {

    class IRenderer {
        public:
            virtual ~IRenderer() = default;
            virtual void build() = 0;
    };

} // RayTracer

#endif //RAYTRACER_IRENDERER_HPP
