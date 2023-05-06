/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ATexture.hpp
*/

#ifndef RAYTRACER_ATEXTURE_HPP
#define RAYTRACER_ATEXTURE_HPP

#include "ITexture.hpp"

#include <unordered_map>
#include <iostream>
#include <memory>

namespace RayTracer {

    class ATexture : public ITexture {
        public:
            ~ATexture() override = default;
            ATexture();

            std::pair<std::shared_ptr<IMaterial>, Math::Vector3D> getTexture(const Math::Vector3D &coordinate) const override;

            const std::unordered_map<std::string, std::shared_ptr<AMaterial>> &getMaterials() const override;

            void setMaterials(const std::unordered_map<std::string, std::shared_ptr<AMaterial>> &materials) override;

            const std::unordered_map<std::string, std::shared_ptr<Math::Vector3D>> &getColors() const override;

            void setColors(const std::unordered_map<std::string, std::shared_ptr<Math::Vector3D>> &colors) override;

            std::unordered_map<std::string, std::shared_ptr<Math::Vector3D>> _colors;

            std::unordered_map<std::string, std::shared_ptr<AMaterial>> _materials;
    };

} // RayTracer

#endif //RAYTRACER_ATEXTURE_HPP
