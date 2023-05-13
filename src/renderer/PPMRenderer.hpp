/*
** EPITECH PROJECT, 2023
** PPMRenderer.hpp
** File description:
** PPMRenderer
*/

#ifndef PPMRENDERER_HPP_
#define PPMRENDERER_HPP_
#include "ARenderer.hpp"

namespace RayTracer {

    class PPMRenderer : public ARenderer {
        public:
            PPMRenderer(int width, int height);
            ~PPMRenderer();
    };

}

#endif /* !PPMRENDERER_HPP_ */
