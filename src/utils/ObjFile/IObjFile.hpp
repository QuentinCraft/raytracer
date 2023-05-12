/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IObjFile.hpp
*/
#ifndef IOBJFILE_HPP_
#define IOBJFILE_HPP_
#include <iostream>

namespace RayTracer {

    class IObjFile {
    public:
        virtual ~IObjFile() = default;

        virtual void load(const std::string &path) = 0;
    };

}

#endif /*IOBJFILE_HPP_*/