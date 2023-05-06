/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ABuilder.hpp
*/

#ifndef ABUILDER_HPP_
#define ABUILDER_HPP_
#include "IBuilder.hpp"
#include "objects/IObject.hpp"
#include "maths/Vector3D.hpp"
#include "texture/ATexture.hpp"

namespace RayTracer {

    class ABuilder : public IBuilder {
        public:
            ABuilder(const std::string &name) {_builderName = name;};
            ~ABuilder() {};

            IBuilder &setTexture(std::shared_ptr<ITexture> const &texture) override
            {
                _texture = texture;
                return *this;
            }
            IBuilder &setCenter(Math::Vector3D const &center) override
            {
                _center = center;
                return *this;
            }
            IBuilder &setPoint(Math::Vector3D const &point) override
            {
                _point = point;
                return *this;
            }
            IBuilder &setRadius(double radius) override
            {
                _radius = radius;
                return *this;
            }
            IBuilder &setNormal(Math::Vector3D const &normal) override
            {
                _normal = normal;
                return *this;
            }
            std::unique_ptr<RayTracer::IObject> build() override
            {
                return std::move(_object);
            }
            std::string &getBuilderName() override
            {
                return _builderName;
            }
            void reset() override
            {
                _texture = std::make_shared<ATexture>();
                _center = Math::Vector3D(0, 0, 0);
                _radius = 0;
                _normal = Math::Vector3D(0, 0, 0);
            }
            IBuilder &applyData(std::unique_ptr<Utils::IData> &data) override
            {
                _texture = data->getTexture();
                _center = data->getCenter();
                _point = data->getPoint();
                _radius = data->getRadius();
                _normal = data->getNormal();
                return *this;
            }
        protected:
            std::shared_ptr<ITexture> _texture;
            Math::Vector3D _center;
            Math::Vector3D _point;
            Math::Vector3D _normal;
            double _radius;
            std::string _builderName;
            std::unique_ptr<RayTracer::IObject> _object;
    };

}

#endif /*ABUILDER_HPP_*/