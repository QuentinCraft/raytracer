/*
** EPITECH PROJECT, 2023
** B-OOP-400-STG-4-1-raytracer-quentin.erdinger
** File description:
** UnlimitedCone
*/

#include "UnlimitedCone.hpp"
#include "objects/PipeLine.hpp"

namespace RayTracer {
    UnlimitedCone::UnlimitedCone(int *globalId) : AObject(globalId) {
        _origin = Math::Vector3D();
        _radius = 0;
        _id = (*globalId)++;
    }

    UnlimitedCone::UnlimitedCone(int *globalId, const Math::Vector3D& center, double radius, const Math::Vector3D& rotationAxis, double rotationAngle, const std::shared_ptr<ITexture>& texture) : RayTracer::AObject(globalId) {
        _origin = center;
        _radius = radius;
        _texture = texture;
        _id = (*globalId)++;
        _rotationAngle = rotationAngle;
        _rotationAxis = rotationAxis;
    }

    std::optional<PipeLine> UnlimitedCone::hits(Ray const& ray) const {
        Math::Vector3D rotatedRayDirection = Math::Utils::rotateVector(ray._direction, _rotationAxis, _rotationAngle);
        Math::Vector3D rayOrigin = Math::Utils::rotateVector(ray._origin - _origin, _rotationAxis, _rotationAngle);

        PipeLine pipe;
        pipe._info = "UnlimitedConeFront";

        double r2 = _radius * _radius;

        double a = rotatedRayDirection._x * rotatedRayDirection._x + rotatedRayDirection._z * rotatedRayDirection._z - r2 * rotatedRayDirection._y * rotatedRayDirection._y;
        double b = 2 * (rayOrigin._x * rotatedRayDirection._x + rayOrigin._z * rotatedRayDirection._z - r2 * rayOrigin._y * rotatedRayDirection._y);
        double c = rayOrigin._x * rayOrigin._x + rayOrigin._z * rayOrigin._z - r2 * rayOrigin._y * rayOrigin._y;

        double discriminant = b * b - 4 * a * c;

        if (Math::Utils::inf(discriminant, 0))
            return std::nullopt;

        double t1 = (-b - sqrt(discriminant)) / (2 * a);

        double t = t1;

        if (t < 0)
            return std::nullopt;

        Math::Vector3D hitPoint = ray._origin + ray._direction * t;
        hitPoint = Math::Utils::rotateVector(hitPoint - _origin, _rotationAxis, _rotationAngle) + _origin;


        pipe._position = hitPoint;
        if (Math::Utils::inf(hitPoint._y, _origin._y))
            return std::nullopt;
        pipe._object = std::make_shared<UnlimitedCone>(*this);
        std::pair<std::shared_ptr<IMaterial>, Math::Vector3D> mat = _texture->getTexture(pipe._position);
        pipe._material = mat.first;
        pipe._color = mat.second;
        pipe._id = _id;
        return pipe;
    }

    Math::Vector3D UnlimitedCone::normal(const PipeLine &pipe) const {
        if (pipe._info == "TopUnlimitedCone")
            return Math::Vector3D(0, -1, 0);
        else if (pipe._info == "UnlimitedCone")
            return Math::Vector3D((_origin - pipe._position)._x, 0, (_origin - pipe._position)._z * -1);
        else if (pipe._info == "UnlimitedConeFront")
            return Math::Vector3D((_origin - pipe._position)._x, 0, (_origin - pipe._position)._z);
        return Math::Vector3D();
    }

    bool UnlimitedCone::operator==(const UnlimitedCone &cone) const {
        return _origin == cone._origin && _radius == cone._radius;
    }

} // RayTracer
