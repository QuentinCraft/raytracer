/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Scene.hpp
*/

#ifndef RAYTRACER_SCENE_HPP
#define RAYTRACER_SCENE_HPP

#include "IScene.hpp"
#include "objects/IObject.hpp"
#include "lights/ILight.hpp"
#include "lights/Ambient.hpp"
#include "cameras/ICamera.hpp"
#include <iostream>
#include <memory>

namespace RayTracer {

    class Scene : public IScene {
        public:
            Scene();
            ~Scene() override {};

        void setObjects(const std::vector<std::shared_ptr<IObject>> &objects);

        std::unique_ptr<ICamera> _camera;
            std::vector<std::shared_ptr<IObject>> _objects;
            std::vector<std::shared_ptr<ILight>> _lights;
            std::shared_ptr<Ambient> _ambientLight;
    };

} // RayTracer

#endif //RAYTRACER_SCENE_HPP
