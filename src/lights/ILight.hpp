/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ILights.hpp
*/

#ifndef RAYTRACER_ILIGHT_HPP
#define RAYTRACER_ILIGHT_HPP

namespace RayTracer {

    class ILight {
        public:
            virtual ~ILight() = default;

            [[nodiscard]] virtual const Math::Vector3D &getOrigin() const = 0;
            virtual void setOrigin(const Math::Vector3D &origin) = 0;

            [[nodiscard]] virtual const Math::Vector3D &getIntensity() const = 0;
            virtual void setIntensity(const Math::Vector3D &intensity) = 0;


    };

} // RayTracer

#endif //RAYTRACER_ILIGHT_HPP
