/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ChessBoardBuilder.cpp
*/

#include "ITextureBuilder.hpp"
#include "ChessBoard.hpp"

namespace RayTracer {
    class ChessBoardBuilder : public ITextureBuilder {
        public:
            ChessBoardBuilder() = default;
            ~ChessBoardBuilder() = default;
            std::shared_ptr<ITexture> build(const AMaterial& matA, const AMaterial& matB, const Math::Vector3D& colorA, const Math::Vector3D &colorB) override
            {
                std::shared_ptr<ITexture> texture = std::make_shared<RayTracer::ChessBoard>(matA, matB, colorA, colorB);
                return texture;
            }
            std::string getName() const override
            {
                return "chessBoard";
            }
    };
}