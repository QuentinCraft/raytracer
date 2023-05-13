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
                _image.create(width, height, sf::Color::Black);
            };
            ~SFMLDisplayModule() override = default;
            void draw(const Math::Vector3D &pos, const Math::Vector3D &color) override {
                _image.setPixel(pos._x, pos._y, sf::Color(color._x, color._y, color._z));
            };
            void display() override {
                sf::Texture texture;
                texture.loadFromImage(_image);
                sf::Sprite sprite(texture);
                _window.draw(sprite);
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
            EventType eventHandler() override {
                while (_window.pollEvent(_event)) {
                    if (_event.type == sf::Event::Closed) {
                        return EventType::CLOSE;
                    }
                }
                return EventType::NONE;
            };
        private:
            sf::RenderWindow _window;
            sf::Event _event;
            sf::Image _image;
    };
}

#endif /*SFMLDISPLAYMODULE_HPP_*/