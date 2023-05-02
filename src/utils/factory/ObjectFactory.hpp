/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ObjectFactory.hpp
*/

#ifndef OBJECTFACTORY_HPP_
#define OBJECTFACTORY_HPP_
#include <iostream>
#include <memory>
#include "objects/IObject.hpp"

#include "objects/Sphere.hpp"
#include "objects/Plane.hpp"

namespace RayTracer::Utils {

    class ObjectFactory {
    public:
        ObjectFactory() {};
        ~ObjectFactory() {};
        std::unique_ptr<RayTracer::IObject> createObject(std::string &type);
    private:
        static std::unique_ptr<RayTracer::IObject> _createSphere();
        static std::unique_ptr<RayTracer::IObject> _createPlane();
    };

}

#endif /*OBJECTFACTORY_HPP_*/