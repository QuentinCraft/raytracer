/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** UnlimitedCylinder.cpp
*/

#include "UnlimitedCylinder.hpp"
#include "objects/PipeLine.hpp"

namespace RayTracer {
    UnlimitedCylinder::UnlimitedCylinder(int *globalId) : RayTracer::AObject(globalId) {
        _origin = Math::Vector3D();
        _radius = 0;
        _id = (*globalId)++;
    }

    UnlimitedCylinder::UnlimitedCylinder(int *globalId, const Math::Vector3D& center, double radius, const Math::Vector3D& rotationAxis, double rotationAngle, const std::shared_ptr<ITexture>& texture) : RayTracer::AObject(globalId) {
        _origin = center;
        _radius = radius;
        _texture = texture;
        _rotationAxis = rotationAxis;
        _rotationAngle = rotationAngle;
        _id = (*globalId)++;
    }

    std::optional<PipeLine> UnlimitedCylinder::hits(Ray const& ray) const {
        Math::Vector3D rayOrigin = Math::Utils::rotateVector(ray._origin - _origin, _rotationAxis, _rotationAngle);
        Math::Vector3D rotatedRayDirection = Math::Utils::rotateVector(ray._direction, _rotationAxis, _rotationAngle);

        double a = rotatedRayDirection._x * rotatedRayDirection._x + rotatedRayDirection._z * rotatedRayDirection._z;
        double b = 2 * (rayOrigin._x * rotatedRayDirection._x + rayOrigin._z * rotatedRayDirection._z);
        double c = rayOrigin._x * rayOrigin._x + rayOrigin._z * rayOrigin._z - (_radius * _radius);

        double discriminant = b * b - 4.0 * a * c;

        double d1 = (-b - sqrt(discriminant)) / (2 * a);
        double t = d1;

        Math::Vector3D hitPoint = (ray._origin + ray._direction * t) + _origin;
        hitPoint = Math::Utils::rotateVector(hitPoint - _origin, _rotationAxis, _rotationAngle);

        if (Math::Utils::inf(discriminant, 0))
            return std::nullopt;
        if (Math::Utils::inf(t, 0))
            return std::nullopt;
        PipeLine pipe;
        pipe._position = hitPoint;
        pipe._object = std::make_shared<UnlimitedCylinder>(*this);
        pipe._id = _id;
        std::pair<std::shared_ptr<IMaterial>, Math::Vector3D> mat = _texture->getTexture(pipe._position);
        pipe._material = mat.first;
        pipe._color = mat.second;
        pipe._info = "UnlimitedCylinder";
        return pipe;
    }

    Math::Vector3D UnlimitedCylinder::normal(const PipeLine &pipe) const {
    if (pipe._info == "UnlimitedCylinder") {
            return {(_origin - pipe._position)._x, 0, (_origin - pipe._position)._z};
        }
        return Math::Vector3D();
    }

    bool UnlimitedCylinder::operator==(const UnlimitedCylinder &UnlimitedCylinder) const {
        return _origin == UnlimitedCylinder._origin && _radius == UnlimitedCylinder._radius;
    }

} // RayTracer
