/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** SoloBuilder.cpp
*/

#include "ATextureBuilder.hpp"
#include "ATexture.hpp"

namespace RayTracer {
    class SoloBuilder : public ATextureBuilder {
        public:
            SoloBuilder() = default;
            ~SoloBuilder() = default;
            std::shared_ptr<ITexture> build(const AMaterial& matA, const Math::Vector3D& colorA)
            {
                std::shared_ptr<ITexture> texture = std::make_shared<RayTracer::ATexture>(matA, colorA);
                return texture;
            }
            std::string getName() const
            {
                return "solo";
            }
    };
}
