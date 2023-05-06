/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** AMaterial.hpp
*/

#ifndef RAYTRACER_AMATERIAL_HPP
#define RAYTRACER_AMATERIAL_HPP

#include "IMaterial.hpp"

namespace RayTracer {

    class AMaterial : public IMaterial {
        public:
            AMaterial();
            ~AMaterial() override = default;

            double _diffuse;

            [[nodiscard]] double getDiffuse() const override;

            void setDiffuse(double diffuse) override;

            [[nodiscard]] double getSpecular() const override;

            void setSpecular(double specular) override;

            [[nodiscard]] double getShininess() const override;

            void setShininess(double shininess) override;

            double _specular;
            double _shininess;

    };

} // RayTracer

#endif //RAYTRACER_AMATERIAL_HPP
