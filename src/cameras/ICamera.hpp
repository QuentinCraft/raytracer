/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ICamera.hpp
*/

#ifndef RAYTRACER_ICAMERA_HPP
#define RAYTRACER_ICAMERA_HPP

#include "lights/Ambient.hpp"

namespace RayTracer {

    class ICamera {
        public:
            virtual ~ICamera() = default;

            [[nodiscard]] virtual const Math::Vector3D &getOrigin() const = 0;
            virtual void setOrigin(const Math::Vector3D &origin) = 0;

            [[nodiscard]] virtual double getFov() const = 0;
            virtual void setFov(double fov) = 0;

            [[nodiscard]] virtual double getHeight() const = 0;
            virtual void setHeight(double height) = 0;

            [[nodiscard]] virtual double getWidth() const = 0;
            virtual void setWidth(double width) = 0;

            [[nodiscard]] virtual const Math::Vector3D &getRotation() const = 0;
            virtual void setRotation(const Math::Vector3D &rotation) = 0;

            [[nodiscard]] virtual Ray ray(double u, double v) const = 0;
            [[nodiscard]] virtual Math::Vector3D pointAt(double u, double v,
                                                 std::vector<std::shared_ptr<IObject>> &objects,
                                                 std::vector<std::shared_ptr<ILight>> &lights,
                                                 std::shared_ptr<Ambient> &ambient) const = 0;
    };

} // RayTracer

#endif //RAYTRACER_ICAMERA_HPP
