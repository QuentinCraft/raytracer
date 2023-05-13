/*
** EPITECH PROJECT, 2023
** GraphicalRenderer.hpp
** File description:
** GraphicalRenderer
*/

#ifndef GRAPHICALRENDERER_HPP_
#define GRAPHICALRENDERER_HPP_
#include "ARenderer.hpp"

#include <SFML/Graphics.hpp>

namespace RayTracer {

    class GraphicalRenderer : public ARenderer {
        public:
            GraphicalRenderer(int width, int height);
            ~GraphicalRenderer();
            void build() override;
        private:
            void eventHandler();
            sf::RenderWindow _window;
            sf::Event _event{};
    };

}

#endif /* !GRAPHICALRENDERER_HPP_ */
