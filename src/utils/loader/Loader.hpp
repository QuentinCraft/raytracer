/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** loader.hpp
*/

#ifndef RAYTRACER_LOADER_HPP
#define RAYTRACER_LOADER_HPP
#include <iostream>
#include <dlfcn.h>
#include <stddef.h>
#include "ILoader.hpp"

namespace RayTracer::Utils {

    class Loader : public ILoader {
        public:
            Loader() {
                _handle = nullptr;
                _error = nullptr;
            }
            ~Loader() override {
                if (_handle)
                    dlclose(_handle);
                if (_error)
                    free(_error);
                _handle = nullptr;
                _error = nullptr;
            }
            bool open(const std::string &path) override {
//                if (_handle) close();
                _handle = dlopen(path.c_str(), RTLD_NOW);

                if (_handle)
                    return true;
                std::cout << "before" << std::endl;

                _error = dlerror();
                std::cout << "after" << std::endl;

                return false;
            }
            void *getFunction(const std::string function) override {
                std::cout << "2.1" << std::endl;

                void *tmp = dlsym(_handle, function.c_str());
                std::cout << "2.2 " << tmp << std::endl;
//                std::cout << dlerror() << std::endl;
                return tmp;
            }
            std::string getError() { return (!_error) ? std::string(_error) : ""; };
            void close() override {
                if (!_handle)
                    return;
                dlclose(_handle);
                _handle = nullptr;
            }
        private:
            void *_handle;
            char *_error;
    };
}

#endif //RAYTRACER_LOADER_HPP
