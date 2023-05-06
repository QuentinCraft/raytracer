/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ChessBoard.cpp
*/

#include "ChessBoard.hpp"
#include "maths/Utils.hpp"

namespace RayTracer {
    ChessBoard::ChessBoard(const AMaterial& matA, const AMaterial& matB, const Math::Vector3D& colorA, const Math::Vector3D& colorB) {
        _colors["colorA"] = std::make_shared<Math::Vector3D>(colorA);
        _colors["colorB"] = std::make_shared<Math::Vector3D>(colorB);
        _materials["materialA"] = std::make_shared<AMaterial>(matA);
        _materials["materialB"] = std::make_shared<AMaterial>(matB);
    }

    std::pair<std::shared_ptr<IMaterial>, Math::Vector3D> ChessBoard::getTexture(const Math::Vector3D &coordinate) const {
        Math::Vector3D color;
        std::shared_ptr<IMaterial> material;

        double scale = 0.2;
        char ax;
        char ay;
        char az;
        if (Math::Utils::inf(coordinate._x, 0))
            ax = fmodf(std::abs(coordinate._x) * scale, 1) < 0.5;
        else
            ax = fmodf(std::abs(coordinate._x) * scale, 1) > 0.5;
        if (Math::Utils::inf(coordinate._y, 0))
            ay = fmodf(std::abs(coordinate._y) * scale, 1) < 0.5;
        else
            ay = fmodf(std::abs(coordinate._y) * scale, 1) > 0.5;
        if (Math::Utils::inf(coordinate._z, 0))
            az = fmodf(std::abs(coordinate._z) * scale, 1) < 0.5;
        else
            az = fmodf(std::abs(coordinate._z) * scale, 1) > 0.5;


        float pattern = (ax) ^ (ay) ^ (az);
        if (pattern) {
            color = *_colors.at("colorA").get();
            material = _materials.at("materialA");
        }
        else {
            color = *_colors.at("colorB").get();
            material = _materials.at("materialB");
        }
        return {material, color};
    }

    const std::unordered_map<std::string, std::shared_ptr<AMaterial>> &ChessBoard::getMaterials() const {
        return _materials;
    }

    void ChessBoard::setMaterials(const std::unordered_map<std::string, std::shared_ptr<AMaterial>> &materials) {
        _materials = materials;
    }

    const std::unordered_map<std::string, std::shared_ptr<Math::Vector3D>> &ChessBoard::getColors() const {
        return _colors;
    }

    void ChessBoard::setColors(const std::unordered_map<std::string, std::shared_ptr<Math::Vector3D>> &colors) {
        _colors = colors;
    }
} // RayTracer