/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** SFMLDisplayModule.hpp
*/
#ifndef SFMLDISPLAYMODULE_HPP_
#define SFMLDISPLAYMODULE_HPP_
#include "IDisplayModule.hpp"
#include <SFML/Graphics.hpp>

namespace RayTracer
{
    class SFMLDisplayModule : public IDisplayModule
    {
        public:
            SFMLDisplayModule(int width, int height) {
                _window.create(sf::VideoMode(width, height), "RayTracer");
                _window.setFramerateLimit(60);
                _window.setActive(true);
            };
            ~SFMLDisplayModule() = default;
            void draw(Math::Vector3D &pos, Math::Vector3D &color) override {
                sf::RectangleShape pixel(sf::Vector2f(1, 1));
                pixel.setPosition(static_cast<float>(pos._x), static_cast<float>(pos._y));
                pixel.setFillColor(sf::Color(static_cast<float>(color._x), static_cast<float>(color._y), static_cast<float>(color._z)));
                _window.draw(pixel);
            };
            void display() override {
                _window.display();
            };
            void clear() override {
                _window.clear();
            };
            bool isOpen() override {
                return _window.isOpen();
            };
            void close() override {
                _window.close();
            };
            void eventHandler() override {
                while (_window.pollEvent(_event)) {
                    if (_event.type == sf::Event::Closed)
                        _window.close();
                }
            };
        private:
            sf::RenderWindow _window;
            sf::Event _event;
    };
}

#endif /*SFMLDISPLAYMODULE_HPP_*/