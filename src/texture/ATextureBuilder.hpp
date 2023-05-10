/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ATextureBuilder.hpp
*/
#ifndef ATEXTUREBUILDER_HPP_
#define ATEXTUREBUILDER_HPP_
#include "ITextureBuilder.hpp"

namespace RayTracer {

    class ATextureBuilder : public ITextureBuilder {
        public:
            ATextureBuilder() {};
            ~ATextureBuilder() {};
            std::shared_ptr<ITexture> build(const AMaterial& matA, const AMaterial& matB, const Math::Vector3D& colorA, const Math::Vector3D &colorB) {
                return nullptr;
            };
            std::shared_ptr<ITexture> build(const AMaterial& matA, const Math::Vector3D& colorA) {
                return nullptr;
            };
            std::string getName() const {
                return "";
            };
        protected:
    };

}

#endif /*ATEXTUREBUILDER_HPP_*/