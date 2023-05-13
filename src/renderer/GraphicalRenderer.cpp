/*
** EPITECH PROJECT, 2023
** GraphicalRenderer.cpp
** File description:
** GraphicalRenderer
*/

#include "GraphicalRenderer.hpp"

RayTracer::GraphicalRenderer::GraphicalRenderer(int width, int height) : ARenderer(width, height)
{
    _window.create(sf::VideoMode(width, height), "RayTracer");
    _window.setFramerateLimit(60);
    _window.setActive(true);
}

RayTracer::GraphicalRenderer::~GraphicalRenderer()
{
}

void RayTracer::GraphicalRenderer::eventHandler()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            _window.close();
    }
}

void RayTracer::GraphicalRenderer::build()
{
    while (_window.isOpen()) {
        eventHandler();
        //
        // ...
        //
        _window.display();
    }
}