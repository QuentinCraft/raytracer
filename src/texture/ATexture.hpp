/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ATexture.hpp
*/

#ifndef RAYTRACER_ATEXTURE_HPP
#define RAYTRACER_ATEXTURE_HPP

#include "ITexture.hpp"

#include <iostream>
#include <memory>

namespace RayTracer {

    class ATexture : public ITexture {
        public:
            ATexture();
            ATexture(const Math::Vector3D &color);
            ATexture(const AMaterial &material);
            ATexture(const AMaterial &material, const Math::Vector3D &color);
            ATexture(const Math::Vector3D &color, const AMaterial &material);

            ~ATexture() override = default;

            [[nodiscard]] std::pair<std::shared_ptr<IMaterial>, Math::Vector3D> getTexture(const Math::Vector3D &coordinate) const override;

            [[nodiscard]] const std::map<std::string, std::shared_ptr<AMaterial>> &getMaterials() const override;

            void setMaterials(const std::map<std::string, std::shared_ptr<AMaterial>> &materials) override;

            [[nodiscard]] const std::map<std::string, std::shared_ptr<Math::Vector3D>> &getColors() const override;

            void setColors(const std::map<std::string, std::shared_ptr<Math::Vector3D>> &colors) override;

            std::map<std::string, std::shared_ptr<Math::Vector3D>> _colors;

            std::map<std::string, std::shared_ptr<AMaterial>> _materials;
    };

} // RayTracer

#endif //RAYTRACER_ATEXTURE_HPP
