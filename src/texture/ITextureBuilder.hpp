/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ITextureBuilder.h
*/
#ifndef ITEXTUREBUILDER_H_
	#define ITEXTUREBUILDER_H_
#include <iostream>
#include "ITexture.hpp"

namespace RayTracer {
    class ITextureBuilder {
        public:
            virtual ~ITextureBuilder() = default;
            virtual std::shared_ptr<ITexture> build(const AMaterial& matA, const AMaterial& matB, const Math::Vector3D& colorA, const Math::Vector3D &colorB) = 0;
            virtual std::string getName() const = 0;
    };
}

#endif /*ITEXTUREBUILDER_H_*/