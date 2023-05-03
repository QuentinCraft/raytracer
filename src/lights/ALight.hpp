/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** AObject.hpp
*/

#ifndef RAYTRACER_ALIGHT_HPP
#define RAYTRACER_ALIGHT_HPP

#include "ILight.hpp"
#include "maths/Vector3D.hpp"

namespace RayTracer {
    class ALight : public ILight {
        public:

            // Constructors
            ALight() {
                _origin = Math::Vector3D();
                _intensity = Math::Vector3D();
            }

            ALight(const Math::Vector3D& origin, const Math::Vector3D& intensity) {
                _origin = origin;
                _intensity = intensity;
            }

            ~ALight() override = default;

            [[nodiscard]] const Math::Vector3D &getOrigin() const override { return _origin; }
            void setOrigin(const Math::Vector3D &origin) override { _origin = origin; }

            [[nodiscard]] const Math::Vector3D &getIntensity() const override { return _intensity; }
            void setIntensity(const Math::Vector3D &intensity) override { _intensity = intensity; }

        protected:
            Math::Vector3D _origin;
            Math::Vector3D _intensity;
    };
}

#endif //RAYTRACER_ALIGHT_HPP
