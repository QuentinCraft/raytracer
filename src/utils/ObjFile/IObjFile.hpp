/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IObjFile.hpp
*/
#ifndef IOBJFILE_HPP_
#define IOBJFILE_HPP_
#include <iostream>
#include <vector>
#include "maths/Vector3D.hpp"

namespace RayTracer {

    class IObjFile {
    public:
        virtual ~IObjFile() = default;

        virtual std::vector<std::array<std::pair<Math::Vector3D, Math::Vector3D>, 3>> load(const std::string &path) = 0;
    };

}

#endif /*IOBJFILE_HPP_*/