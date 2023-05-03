/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** AData.hpp
*/
#ifndef ADATA_HPP_
#define ADATA_HPP_
#include "IData.hpp"

namespace RayTracer::Utils {

    class AData : public IData {
        public:
            AData() {};
            ~AData() {};

            void setType(std::string type) override { _type = type; };
            void setColor(Math::Vector3D color) override { _color = color; };
            void setCenter(Math::Vector3D center) override { _center = center; };
            void setPoint(Math::Vector3D point) override { _point = point; };
            void setNormal(Math::Vector3D normal) override { _normal = normal; };
            void setRadius(double radius) override { _radius = radius; };
            void setAxis(const std::string &axis) override { _axis = axis;};
            std::string &getType() override { return _type; };
            Math::Vector3D &getColor() override { return _color; };
            Math::Vector3D &getCenter() override { return _center; };
            Math::Vector3D &getPoint() override { return _point; };
            Math::Vector3D &getNormal() override { return _normal; };
            double &getRadius() override { return _radius; };
            std::string &getAxis() override { return _axis; };

        protected:
            std::string _type;
            Math::Vector3D _color;
            Math::Vector3D _center;
            Math::Vector3D _point;
            Math::Vector3D _normal;
            double _radius;
            std::string _axis;
    };

}

#endif /*ADATA_HPP_*/