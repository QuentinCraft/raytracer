/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** chrome.h
*/

#ifndef RAYTRACER_CHROME_HPP
#define RAYTRACER_CHROME_HPP

#include "AMaterial.hpp"

namespace RayTracer {

    class Chrome : public AMaterial {
        public:
            Chrome() : AMaterial(
                 {0.4, 0.4, 0.4},
                 {0.774597, 0.774597, 0.774597},
                 0.25 * 128,
                 0,
                 true
            ) {};
    };

} // RayTracer

#endif //RAYTRACER_CHROME_HPP
