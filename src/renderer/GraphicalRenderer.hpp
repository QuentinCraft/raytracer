/*
** EPITECH PROJECT, 2023
** GraphicalRenderer.hpp
** File description:
** GraphicalRenderer
*/

#ifndef GRAPHICALRENDERER_HPP_
#define GRAPHICALRENDERER_HPP_
#include "ARenderer.hpp"
#include "SFMLDisplayModule.hpp"

namespace RayTracer {

    class GraphicalRenderer : public ARenderer {
        public:
            GraphicalRenderer(int width, int height);
            ~GraphicalRenderer() override;
            void build(std::unique_ptr<RayTracer::Scene> &scene, bool fast) override;
        private:
            void eventHandler();
            std::unique_ptr<IDisplayModule> _displayModule;
            bool _isRunning;
    };

}

#endif /* !GRAPHICALRENDERER_HPP_ */
