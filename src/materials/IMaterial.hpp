/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IMaterial.hpp
*/

#ifndef RAYTRACER_IMATERIAL_HPP
#define RAYTRACER_IMATERIAL_HPP

#include "maths/Vector3D.hpp"

namespace RayTracer {

    class IMaterial {
        public:
            virtual ~IMaterial() = default;

            [[nodiscard]] virtual Math::Vector3D getDiffuse() const = 0;
            virtual void setDiffuse(Math::Vector3D diffuse) = 0;

            [[nodiscard]] virtual Math::Vector3D getSpecular() const = 0;
            virtual void setSpecular(Math::Vector3D specular) = 0;

            [[nodiscard]] virtual double getShininess() const = 0;
            virtual void setShininess(double shininess) = 0;

            [[nodiscard]] virtual double getRefraction() const = 0;
            virtual void setRefraction(double refraction) = 0;

            [[nodiscard]] virtual bool getReflection() const = 0;
            virtual void setReflection(bool reflection) = 0;
    };

};

#endif //RAYTRACER_IMATERIAL_HPP
