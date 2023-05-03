/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IError.hpp
*/

#ifndef RAYTRACER_ERROR_HPP
#define RAYTRACER_ERROR_HPP
#include <iostream>
#include <exception>

namespace RayTracer::Utils {

    // Config Throw Error Class
    class Error : public std::exception {
        public:
            explicit Error(const std::string err) : _error(err) {};
            [[nodiscard]] const char *what() const noexcept override {
                return _error.c_str();
            }
            std::string _error;
    };

}

#endif //RAYTRACER_ERROR_HPP
