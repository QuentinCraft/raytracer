/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Scene.cpp
*/

#include "Scene.hpp"

namespace RayTracer {
    Scene::Scene() {

    }

    void Scene::setObjects(const std::vector<std::shared_ptr<IObject>> &objects) {
        _objects = objects;
    }
} // RayTracer