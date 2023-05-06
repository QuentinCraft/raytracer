/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IMaterial.hpp
*/

#ifndef RAYTRACER_IMATERIAL_HPP
#define RAYTRACER_IMATERIAL_HPP

namespace RayTracer {

    class IMaterial {
        public:
            virtual ~IMaterial() = default;

            [[nodiscard]] virtual double getDiffuse() const = 0;

            virtual void setDiffuse(double diffuse) = 0;

            [[maybe_unused]] virtual double getSpecular() const = 0;

            virtual void setSpecular(double specular) = 0;

            [[nodiscard]] virtual double getShininess() const = 0;

            virtual void setShininess(double shininess) = 0;
    };

};

#endif //RAYTRACER_IMATERIAL_HPP
