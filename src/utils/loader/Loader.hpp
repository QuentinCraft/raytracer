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
#include <vector>

namespace RayTracer::Utils {

    class Loader : public ILoader {
        public:
            Loader() {
                _handle = nullptr;
                _error = nullptr;
            }
            ~Loader() override {
                for (auto &x : _tofree) {
                    if (x != nullptr)
                        dlclose(x);
                }
                if (_error)
                    free(_error);
                _handle = nullptr;
                _error = nullptr;
            }
            bool open(const std::string &path) override {
                _handle = dlopen(path.c_str(), RTLD_NOW);
                _tofree.push_back(_handle);

                if (_handle)
                    return true;
                _error = dlerror();
                std::cerr << "\n Library Loader error : " << _error << std::endl;

                return false;
            }
            void *getFunction(const std::string function) override {
                void *tmp = dlsym(_handle, function.c_str());
                return tmp;
            }
            std::string getError() { return (!_error) ? std::string(_error) : ""; };
            void close() override {
                if (_handle != nullptr) {
                    dlclose(_handle);
                    _handle = nullptr;
                }
            }
        private:
            void *_handle;
            char *_error;
            std::vector<void *> _tofree;
    };
}

#endif //RAYTRACER_LOADER_HPP
