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
            AMaterial(std::string name);
            AMaterial(AMaterial const &material) = default;
            AMaterial(AMaterial &&material) = default;
            AMaterial(std::string name, Math::Vector3D ambient, Math::Vector3D diffuse, Math::Vector3D specular, double shininess, double refraction, bool reflection, double spread);
            ~AMaterial() override = default;

            [[nodiscard]] Math::Vector3D getDiffuse() const override;
            void setDiffuse(Math::Vector3D diffuse) override;

            [[nodiscard]] Math::Vector3D getSpecular() const override;
            void setSpecular(Math::Vector3D specular) override;

            [[nodiscard]] double getShininess() const override;
            void setShininess(double shininess) override;

            [[nodiscard]] double getRefraction() const override;
            void setRefraction(double refraction) override;

            [[nodiscard]] bool getReflection() const override;
            void setReflection(bool reflection) override;

            [[nodiscard]] double getSpread() const override;
            void setSpread(double spread) override;

            [[nodiscard]] Math::Vector3D getAmbient() const override;
            void setAmbient(Math::Vector3D ambient) override;

            [[nodiscard]] std::string getName() const override {
                return _name;
            }

            double _refraction;
            double _spread;
            bool _reflection;
            Math::Vector3D _ambient;
            Math::Vector3D _diffuse;
            Math::Vector3D _specular;
            double _shininess;
            std::string _name;

    };

} // RayTracer

#endif //RAYTRACER_AMATERIAL_HPP
