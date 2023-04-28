/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Camera3D.hpp
*/

#ifndef BSRAYTRACER_CAMERA_HPP
#define BSRAYTRACER_CAMERA_HPP

#include "maths/Vector3D.hpp"
#include "maths/Utils.hpp"
#include "lights/Spot.hpp"
#include "objects/IObject.hpp"
#include "objects/PipeLine.hpp"
#include "ICamera.hpp"

#include <memory>
#include <vector>

namespace RayTracer {

    class Camera : public ICamera {
        public:
            // Constructors
            Camera();
            Camera(const Math::Vector3D& origin, double height, double width, double fov);

            // Methods
            [[nodiscard]] Ray ray(double u, double v) const override;
            [[nodiscard]] Math::Vector3D pointAt(double u, double v,
                                                 std::vector<std::shared_ptr<IObject>> &objects,
                                                 std::vector<std::shared_ptr<ILight>> &lights) const override;

            [[nodiscard]] const Math::Vector3D &getOrigin() const override { return _origin; };
            void setOrigin(const Math::Vector3D &origin) override { _origin = origin; };

            [[nodiscard]] double getFov() const override { return _fov; };
            void setFov(double fov) override { _fov = fov; };

            [[nodiscard]] double getHeight() const override { return _height; };
            void setHeight(double height) override { _height = height; };

            [[nodiscard]] double getWidth() const override { return _width; };
            void setWidth(double width) override { _width = width; };

            [[nodiscard]] const Math::Vector3D &getRotation() const override { return _rotation; };
            void setRotation(const Math::Vector3D &rotation) override { _rotation = rotation; };

        protected:
            Math::Vector3D _origin;
            double _fov;
            double _height;
            double _width;
            Math::Vector3D _rotation;
    };

} // RayTracer

#endif //BSRAYTRACER_CAMERA_HPP
