/*
** EPITECH PROJECT, 2023
** B-OOP-400-STG-4-1-raytracer-quentin.erdinger
** File description:
** Cone
*/

#include "Cone.hpp"
#include "objects/PipeLine.hpp"

namespace RayTracer {
    Cone::Cone(int *globalId) : AObject(globalId) {
        _origin = Math::Vector3D();
        _radius = 0;
        _height = 0;
        _id = (*globalId)++;
    }

    Cone::Cone(int *globalId, const Math::Vector3D& center, double radius, double height, const std::shared_ptr<ITexture>& texture) : RayTracer::AObject(globalId) {
        _origin = center;
        _radius = radius;
        _height = height;
        _texture = texture;
        _id = (*globalId)++;
    }

    std::optional<PipeLine> Cone::hits(Ray const& ray) const {
        Math::Vector3D rayOrigin = ray._origin - _origin;
        PipeLine pipe;
        pipe._info = "ConeFront";

        double r2 = _radius * _radius;
        double h2 = _height * _height;

        double a = ray._direction._x * ray._direction._x + ray._direction._z * ray._direction._z - r2 / h2 * ray._direction._y * ray._direction._y;
        double b = 2 * (rayOrigin._x * ray._direction._x + rayOrigin._z * ray._direction._z - r2 / h2 * rayOrigin._y * ray._direction._y);
        double c = rayOrigin._x * rayOrigin._x + rayOrigin._z * rayOrigin._z - r2 / h2 * rayOrigin._y * rayOrigin._y;

        double discriminant = b * b - 4 * a * c;

        if (Math::Utils::inf(discriminant, 0))
            return std::nullopt;

        double t1 = (-b - sqrt(discriminant)) / (2 * a);

        double t = t1;

        if (t < 0)
            return std::nullopt;

        Math::Vector3D hitPoint = ray._origin + ray._direction * t;

        double t_top = (_origin._y + _height - ray._origin._y) / ray._direction._y;

        Math::Vector3D hitPoint_top = ray._origin + ray._direction * t_top;

        double dist_top = sqrt((hitPoint_top._x - _origin._x) * (hitPoint_top._x - _origin._x) + (hitPoint_top._z - _origin._z) * (hitPoint_top._z - _origin._z));

        pipe._position = hitPoint;
        if (Math::Utils::inf(dist_top, _radius) || Math::Utils::equal(dist_top, _radius)) {
            if (Math::Utils::inf(Math::Utils::distance(ray._origin, hitPoint_top), Math::Utils::distance(ray._origin, hitPoint))) {
                pipe._position = hitPoint_top;
                pipe._info = "TopCone";
            }
        } else if (Math::Utils::inf(hitPoint._y, _origin._y) || Math::Utils::sup(hitPoint._y, _origin._y + _height))
            return std::nullopt;
        pipe._object = std::make_shared<Cone>(*this);
        std::pair<std::shared_ptr<IMaterial>, Math::Vector3D> mat = _texture->getTexture(pipe._position);
        pipe._material = mat.first;
        pipe._color = mat.second;
        pipe._id = _id;
        return pipe;
    }

    Math::Vector3D Cone::normal(const PipeLine &pipe) const {
        if (pipe._info == "TopCone")
            return Math::Vector3D(0, -1, 0);
        else if (pipe._info == "Cone")
            return Math::Vector3D((_origin - pipe._position)._x, 0, (_origin - pipe._position)._z * -1);
        else if (pipe._info == "ConeFront")
            return Math::Vector3D((_origin - pipe._position)._x, 0, (_origin - pipe._position)._z);
        return Math::Vector3D();
    }

    bool Cone::operator==(const Cone &cone) const {
        return _origin == cone._origin && _radius == cone._radius;
    }

} // RayTracer
