/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ITexture.hpp
*/

#ifndef RAYTRACER_ITEXTURE_HPP
#define RAYTRACER_ITEXTURE_HPP

#include "materials/AMaterial.hpp"
#include "maths/Vector3D.hpp"

#include <iostream>
#include <memory>

namespace RayTracer {

    class ITexture {
        public:
            virtual ~ITexture() = default;
            [[nodiscard]] virtual std::pair<std::shared_ptr<IMaterial>, Math::Vector3D> getTexture(const Math::Vector3D &coordinate) const = 0;

            [[nodiscard]] virtual const std::unordered_map<std::string, std::shared_ptr<AMaterial>> &getMaterials() const = 0;

            virtual void setMaterials(const std::unordered_map<std::string, std::shared_ptr<AMaterial>> &materials) = 0;

            [[nodiscard]] virtual const std::unordered_map<std::string, std::shared_ptr<Math::Vector3D>> &getColors() const = 0;

            virtual void setColors(const std::unordered_map<std::string, std::shared_ptr<Math::Vector3D>> &colors) = 0;

    };

} // RayTracer

#endif //RAYTRACER_ITEXTURE_HPP
