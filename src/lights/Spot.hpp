/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Spot.hpp
*/

#ifndef RAYTRACER_SPOT_HPP
#define RAYTRACER_SPOT_HPP

#include "maths/Vector3D.hpp"
#include "ALight.hpp"

namespace RayTracer {

    class Spot : public ALight {
        public:
            Spot(const Math::Vector3D& origin, const Math::Vector3D& intensity) {
                _origin = origin;
                _intensity = intensity;
            }

    };

} // RayTracer

#endif //RAYTRACER_SPOT_HPP
