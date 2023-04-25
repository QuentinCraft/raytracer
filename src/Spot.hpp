/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Spot.hpp
*/

#ifndef RAYTRACER_SPOT_HPP
#define RAYTRACER_SPOT_HPP

#include "Point3D.hpp"

namespace RayTracer {

    class Spot {
        public:
            // Constructors
            Spot();
            Spot(const Math::Point3D& origin, double intensity);

            // Destructor
            ~Spot() = default;

            // Variables
            Math::Point3D _origin;
            double _intensity;
    };

} // RayTracer

#endif //RAYTRACER_SPOT_HPP
