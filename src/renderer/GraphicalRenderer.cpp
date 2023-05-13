/*
** EPITECH PROJECT, 2023
** GraphicalRenderer.cpp
** File description:
** GraphicalRenderer
*/

#include "GraphicalRenderer.hpp"

RayTracer::GraphicalRenderer::GraphicalRenderer(int width, int height) : ARenderer(width, height)
{
    _displayModule = std::make_unique<SFMLDisplayModule>(width, height);
}

RayTracer::GraphicalRenderer::~GraphicalRenderer()
{
}

void RayTracer::GraphicalRenderer::eventHandler()
{
    _displayModule->eventHandler();
}

void RayTracer::GraphicalRenderer::build()
{
    while (_displayModule->isOpen()) {
        eventHandler();
        //
        //
        //
        _displayModule->display();
    }
}