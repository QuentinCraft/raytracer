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
            ~GraphicalRenderer();
            void build() override;
        private:
            void eventHandler();
            std::unique_ptr<IDisplayModule> _displayModule;
    };

}

#endif /* !GRAPHICALRENDERER_HPP_ */
