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
            void setTexture(std::shared_ptr<ITexture> texture) override { _texture = texture; };
            void setCenter(Math::Vector3D center) override { _center = center; };
            void setPoint(Math::Vector3D point) override { _point = point; };
            void setNormal(Math::Vector3D normal) override { _normal = normal; };
            void setRadius(double radius) override { _radius = radius; };
            void setLength(double length) override { _length = length; };
            void setV1(Math::Vector3D v1) override { _v1 = v1; };
            void setV2(Math::Vector3D v2) override { _v2 = v2; };
            void setV3(Math::Vector3D v3) override { _v3 = v3; };
            void setN1(Math::Vector3D n1) override { _n1 = n1; };
            void setN2(Math::Vector3D n2) override { _n2 = n2; };
            void setN3(Math::Vector3D n3) override { _n3 = n3; };
            void setAxe(const Math::Vector3D axe) override { _axe = axe; };
            void setAngle(double angle) override { _angle = angle; };

            std::string &getType() override { return _type; };
            std::shared_ptr<ITexture> &getTexture() override { return _texture; };
            Math::Vector3D &getCenter() override { return _center; };
            Math::Vector3D &getPoint() override { return _point; };
            Math::Vector3D &getNormal() override { return _normal; };
            double &getRadius() override { return _radius; };
            Math::Vector3D &getIntensity() override { return _intensity; };
            void setIntensity(const Math::Vector3D intensity) override { _intensity = intensity; };
            double &getLength() override { return _length; };
            Math::Vector3D &getV1() override { return _v1; };
            Math::Vector3D &getV2() override { return _v2; };
            Math::Vector3D &getV3() override { return _v3; };
            Math::Vector3D &getN1() override { return _n1; };
            Math::Vector3D &getN2() override { return _n2; };
            Math::Vector3D &getN3() override { return _n3; };
            Math::Vector3D &getAxe() override { return _axe; };
            double &getAngle() override { return _angle; };

        protected:
            std::string _type;
            std::shared_ptr<ITexture> _texture;
            Math::Vector3D _center;
            Math::Vector3D _point;
            Math::Vector3D _normal;
            double _radius;
            double _length;
            Math::Vector3D _intensity;
            Math::Vector3D _v1;
            Math::Vector3D _v2;
            Math::Vector3D _v3;
            Math::Vector3D _n1;
            Math::Vector3D _n2;
            Math::Vector3D _n3;
            Math::Vector3D _axe;
            double _angle;
    };

}

#endif /*ADATA_HPP_*/