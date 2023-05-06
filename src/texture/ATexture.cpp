/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ATexture.cpp
*/

#include "ATexture.hpp"

namespace RayTracer {
    ATexture::ATexture() = default;

    std::pair<std::shared_ptr<IMaterial>, Math::Vector3D> ATexture::getTexture(const Math::Vector3D &coordinate) const {
        _materials;
        return {std::make_shared<AMaterial>(), Math::Vector3D(255, 0, 255)};
    }

    const std::unordered_map<std::string, std::shared_ptr<AMaterial>> &ATexture::getMaterials() const {
        return _materials;
    }

    void ATexture::setMaterials(const std::unordered_map<std::string, std::shared_ptr<AMaterial>> &materials) {
        _materials = materials;
    }

    const std::unordered_map<std::string, std::shared_ptr<Math::Vector3D>> &ATexture::getColors() const {
        return _colors;
    }

    void ATexture::setColors(const std::unordered_map<std::string, std::shared_ptr<Math::Vector3D>> &colors) {
        _colors = colors;
    }
} // RayTracer