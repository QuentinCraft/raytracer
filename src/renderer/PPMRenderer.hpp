/*
** EPITECH PROJECT, 2023
** PPMRenderer.hpp
** File description:
** PPMRenderer
*/

#ifndef PPMRENDERER_HPP_
#define PPMRENDERER_HPP_

#include <vector>
#include <optional>

#include "ARenderer.hpp"
#include "maths/Vector3D.hpp"
#include "scenes/Scene.hpp"

namespace RayTracer {

    class PPMRenderer : public ARenderer {
        public:
            PPMRenderer(int width, int height);
            ~PPMRenderer() override;
            void build(std::unique_ptr<RayTracer::Scene> &scene, bool fast) override;
    };

}

#endif /* !PPMRENDERER_HPP_ */
