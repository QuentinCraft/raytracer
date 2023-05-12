/*
** EPITECH PROJECT, 2023
** bsraytracer
** File description:
** Triangle.cpp
*/

#include "Triangle.hpp"
#include "PipeLine.hpp"

namespace RayTracer {
    Triangle::Triangle(int *globalId) : AObject(globalId) {
        _vertices = { Math::Vector3D(), Math::Vector3D(), Math::Vector3D() };
        _id = (*globalId)++;
//        _color = Math::Vector3D();
    }

    Triangle::Triangle(int *globalId, const Math::Vector3D& v1, const Math::Vector3D& v2, const Math::Vector3D& v3, const Math::Vector3D &n1, const Math::Vector3D &n2, const Math::Vector3D &n3, const std::shared_ptr<ITexture>& texture) : AObject(globalId) {
        _vertices = {v1, v2, v3};
        _normals = {n1, n2, n3};
        _texture = texture;
        _id = (*globalId)++;
//        _color = color;
    }


    std::optional<PipeLine> Triangle::hits(Ray const &ray) const {
        Math::Vector3D v0 = _vertices[0];
        Math::Vector3D v1 = _vertices[1];
        Math::Vector3D v2 = _vertices[2];

        Math::Vector3D edge1 = v1 - v0;
        Math::Vector3D edge2 = v2 - v0;
        Math::Vector3D h = ray._direction.cross(edge2);
        double a = edge1.dot(h);

        Math::Vector3D s = ray._origin - v0;
        double f = 1.0 / a;
        double u = f * s.dot(h);

        if (Math::Utils::inf(u, 0.0) || Math::Utils::sup(u, 1.0))
            return std::nullopt;

        Math::Vector3D q = s.cross(edge1);
        double v = f * ray._direction.dot(q);

        if (Math::Utils::inf(v, 0.0) || Math::Utils::sup(u + v, 1.0))
            return std::nullopt;

        double t = f * edge2.dot(q);

        if (Math::Utils::inf(t, 0))
            return std::nullopt;

        PipeLine pipe;
        pipe._position = ray._origin + ray._direction * t;
        pipe._id = _id;
        std::pair<std::shared_ptr<IMaterial>, Math::Vector3D> mat = _texture->getTexture(pipe._position);
        pipe._material = mat.first;
        pipe._color = mat.second;
        pipe._object = std::make_shared<Triangle>(*this);
        return pipe;
    }

    Math::Vector3D Triangle::normal(const PipeLine &pipe) const {
        Math::Vector3D v0 = _vertices[0];
        Math::Vector3D v1 = _vertices[1];
        Math::Vector3D v2 = _vertices[2];

        Math::Vector3D edge1 = v1 - v0;
        Math::Vector3D edge2 = v2 - v0;

        return edge1.cross(edge2).normalized();
    }

    bool Triangle::operator==(const Triangle &triangle) const {
        return _vertices == triangle._vertices && _texture == triangle._texture;
    }

    } // RayTracer