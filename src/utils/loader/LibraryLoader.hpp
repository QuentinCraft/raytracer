/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** LibraryLoader.hpp
*/

#ifndef RAYTRACER_LIBRARYLOADER_HPP
#define RAYTRACER_LIBRARYLOADER_HPP

#include <iostream>
#include <memory>

#include "Loader.hpp"
#include "utils/Error.hpp"

namespace RayTracer::Utils {

    class LibraryLoader {
        public:
            // constructor
            LibraryLoader() {
                _loader = std::make_unique<Loader>();
            }
            // destructor
            ~LibraryLoader() = default;

            // Load library
            template<typename T>
            T loadLib(std::string &lib) {
                if (!_loader->open(lib))
                    throw RayTracer::Utils::Error(std::string("Error Cannot load [" + lib + "]"));
                T (*c_fct)() = (T (*)())(_loader->getFunction("entryPoint"));
                T newFunction = c_fct();

                return newFunction;
            }
        private:
            std::unique_ptr<ILoader> _loader;
    };

} // Utils

#endif //RAYTRACER_LIBRARYLOADER_HPP
