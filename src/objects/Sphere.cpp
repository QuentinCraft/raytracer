/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Sphere.cpp
*/

#include "Sphere.hpp"
#include "objects/PipeLine.hpp"

namespace RayTracer {
    Sphere::Sphere() {
        _id = 0;
        _origin = Math::Vector3D();
        _rotation = Math::Vector3D();
        _scale = Math::Vector3D();
        _radius = 0;
    }

    std::optional<PipeLine> Sphere::hits(Ray const &ray) const {
        Ray rayBis(ray._origin - _origin, ray._direction.normalized());
        double a = rayBis._direction.dot(rayBis._direction);
        double b = 2 * rayBis._origin.dot(rayBis._direction);
        double c = rayBis._origin.dot(rayBis._origin) - (_radius * _radius);

        double discriminant = b * b - 4.0 * a * c;

        if (Math::Utils::inf(discriminant, 0))
            return std::nullopt;
        double D = (-b - sqrt(discriminant)) / (2 * a);
        if (Math::Utils::inf(D, 0))
            return std::nullopt;
        PipeLine pipe;
        pipe._position = ray._origin + rayBis._direction * D;
        pipe._id = _id;
        std::pair<std::shared_ptr<IMaterial>, Math::Vector3D> mat = _texture->getTexture(pipe._position);
        pipe._material = mat.first;
        pipe._color = mat.second;
        pipe._object = std::make_shared<Sphere>(*this);
        return pipe;
    }

    Math::Vector3D Sphere::normal(const PipeLine &pipe) const {
        return Math::Vector3D(_origin - pipe._position).normalized();
    }

    bool Sphere::operator==(const Sphere &sphere) const {
        return _origin == sphere._origin && _radius == sphere._radius;
    }

    Sphere::Sphere(const Math::Vector3D &center, double radius,
                   const std::shared_ptr<ITexture> &texture) {
        _id = 0;
        _origin = center;
        _radius = radius;
        _rotation = Math::Vector3D();
        _scale = Math::Vector3D();
        _texture = texture;

    }

    Sphere::Sphere(const Math::Vector3D &center, double radius) {
        _origin = center;
        _radius = radius;
        _texture = std::make_shared<ATexture>();
    }

} // RayTracer
