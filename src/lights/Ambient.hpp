/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Ambient.hpp
*/

#ifndef RAYTRACER_AMBIENT_HPP
#define RAYTRACER_AMBIENT_HPP

#include "ALight.hpp"

namespace RayTracer {

    class Ambient : public ALight {
        public:
            Ambient(const Math::Vector3D& intensity) {
                _intensity = intensity;
                _origin = {0, 0, 0};
            }
    };

} // RayTracer

#endif //RAYTRACER_AMBIENT_HPP
