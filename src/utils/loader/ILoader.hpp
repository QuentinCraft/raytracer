/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ILoader.hpp
*/

#ifndef RAYTRACER_ILOADER_HPP
#define RAYTRACER_ILOADER_HPP
#include <iostream>

namespace RayTracer::Utils {

    class ILoader {
        public:
            // destructor
            virtual ~ILoader() = default;

            /* open (arg: path ./lib.so)
             * Return [false] = error
             */
            virtual bool open(std::string &path) = 0;

            // get function by name (ex: entryPoint)
            virtual void *getFunction(const std::string function) = 0;

            // delete linkage to library && free ptr && error
            virtual void close() = 0;
    };

}

#endif //RAYTRACER_ILOADER_HPP
