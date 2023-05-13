/*
** EPITECH PROJECT, 2023
** ARenderer.hpp
** File description:
** ARenderer
*/

#ifndef ARENDERER_HPP_
#define ARENDERER_HPP_
#include "IRenderer.hpp"

#include <iostream>
#include <memory>

namespace RayTracer {

    class ARenderer : public IRenderer {
        public:
            ARenderer(int width, int height) {
                _width = width;
                _height = height;
            };
            ~ARenderer() {};
            void build() {};
        protected:
            int _width;
            int _height;
    };

}

#endif /* !ARENDERER_HPP_ */
