/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ATexture.cpp
*/

#include "ATexture.hpp"

namespace RayTracer {
    ATexture::ATexture() {
        _materials["default"] = std::make_shared<AMaterial>("basic");
        _colors["default"] = std::make_shared<Math::Vector3D>(Math::Vector3D(100, 100, 100));
    }

    ATexture::ATexture(const Math::Vector3D &color) {
        _materials["default"] = std::make_shared<AMaterial>("basic");
        _colors["default"] = std::make_shared<Math::Vector3D>(color);
    }

    ATexture::ATexture(const AMaterial &material) {
        _materials["default"] = std::make_shared<AMaterial>(material);
        _colors["default"] = std::make_shared<Math::Vector3D>(Math::Vector3D(100, 100, 100));
    }

    ATexture::ATexture(const AMaterial &material, const Math::Vector3D &color) {
        _materials["default"] = std::make_shared<AMaterial>(material);
        _colors["default"] = std::make_shared<Math::Vector3D>(color);
    }

    ATexture::ATexture(const Math::Vector3D &color, const AMaterial &material) {
        _materials["default"] = std::make_shared<AMaterial>(material);
        _colors["default"] = std::make_shared<Math::Vector3D>(color);
    }

    std::pair<std::shared_ptr<IMaterial>, Math::Vector3D> ATexture::getTexture(const Math::Vector3D &coordinate) const {
        return {_materials.at("default"), *_colors.at("default")};
    }

    const std::map<std::string, std::shared_ptr<AMaterial>> &ATexture::getMaterials() const {
        return _materials;
    }

    void ATexture::setMaterials(const std::map<std::string, std::shared_ptr<AMaterial>> &materials) {
        _materials = materials;
    }

    const std::map<std::string, std::shared_ptr<Math::Vector3D>> &ATexture::getColors() const {
        return _colors;
    }

    void ATexture::setColors(const std::map<std::string, std::shared_ptr<Math::Vector3D>> &colors) {
        _colors = colors;
    }

} // RayTracer