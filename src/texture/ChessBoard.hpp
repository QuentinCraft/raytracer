/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ChessBoard.hpp
*/

#ifndef RAYTRACER_CHESSBOARD_HPP
#define RAYTRACER_CHESSBOARD_HPP

#include "ITexture.hpp"

namespace RayTracer {

    class ChessBoard : public ITexture {
        public:
            ChessBoard(const AMaterial& matA, const AMaterial& matB, const Math::Vector3D& colorA, const Math::Vector3D& colorB);
            ~ChessBoard() override = default;

            [[nodiscard]] std::pair<std::shared_ptr<IMaterial>, Math::Vector3D> getTexture(const Math::Vector3D &coordinate) const override;

            const std::map<std::string, std::shared_ptr<AMaterial>> &getMaterials() const override;

            void setMaterials(const std::map<std::string, std::shared_ptr<AMaterial>> &materials) override;

            const std::map<std::string, std::shared_ptr<Math::Vector3D>> &getColors() const override;

            void setColors(const std::map<std::string, std::shared_ptr<Math::Vector3D>> &colors) override;

            std::map<std::string, std::shared_ptr<AMaterial>> _materials;
            std::map<std::string, std::shared_ptr<Math::Vector3D>> _colors;
    };

} // RayTracer

#endif //RAYTRACER_CHESSBOARD_HPP
