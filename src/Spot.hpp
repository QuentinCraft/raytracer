/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Spot.hpp
*/

#ifndef RAYTRACER_SPOT_HPP
#define RAYTRACER_SPOT_HPP

#include "Vector3D.hpp"

namespace RayTracer {

    class Spot {
        public:
            // Constructors
            Spot();
            Spot(const Math::Vector3D& origin, const Math::Vector3D& intensity);

            // Destructor
            ~Spot() = default;

            // Variables
            Math::Vector3D _origin;
            Math::Vector3D _intensity;
    };

} // RayTracer

#endif //RAYTRACER_SPOT_HPP
