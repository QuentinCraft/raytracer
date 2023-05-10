/*
** EPITECH PROJECT, 2023
** B-OOP-400-STG-4-1-raytracer-quentin.erdinger
** File description:
** Plane
*/

#include "Plane.hpp"
#include "objects/PipeLine.hpp"
#include "texture/ChessBoard.hpp"
#include <iostream>
#include <iomanip>

namespace RayTracer {
    Plane::Plane(int *globalId) : RayTracer::AObject(globalId) {
        _origin = Math::Vector3D();
        _normal = Math::Vector3D().normalized();
        _id = (*globalId)++;
    }

    Plane::Plane(int *globalId, const Math::Vector3D& point, const Math::Vector3D& normal) : RayTracer::AObject(globalId) {
        _origin = point;
        _normal = normal.normalized();
        _id = (*globalId)++;
    }

    std::optional<PipeLine> Plane::hits(Ray const &ray) const {
        Ray rayBis(ray._origin - _origin, ray._direction.normalized());

        double denominator = rayBis._direction.dot(_normal);
        if (denominator < 1e-6) {
            Math::Vector3D p0l0 = _origin - rayBis._origin;
            if (Math::Utils::equal(denominator, 0))
                denominator = 0.000000001;
            double D = p0l0.dot(_normal) / denominator;
            if (Math::Utils::sup(D, 0)) {
                PipeLine pipe;
                pipe._object = std::make_shared<Plane>(*this);
                pipe._position = ray._origin + ray._direction * D;
                std::pair<std::shared_ptr<IMaterial>, Math::Vector3D> mat = _texture->getTexture(pipe._position);
                pipe._material = mat.first;
                pipe._color = mat.second;
                pipe._id = _id;
                return pipe;
            }
        }
        return std::nullopt;
    }

    Math::Vector3D Plane::normal(const PipeLine &pipe) const {
        return _normal * -1;
    }

    bool Plane::operator==(const Plane &plane) const {
        return _origin == plane._origin && _normal == plane._normal;
    }

    Plane::Plane(int *globalId, const Math::Vector3D &point, const Math::Vector3D &normal, const std::shared_ptr<ITexture> &texture) : RayTracer::AObject(globalId) {
        _origin = point;
        _normal = normal.normalized();
        _id = (*globalId)++;
        _texture = texture;
    }


} // RayTracer