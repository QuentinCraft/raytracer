/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ObjectFactory.hpp
*/

#ifndef OBJECTFACTORY_HPP_
#define OBJECTFACTORY_HPP_
#include "IObjectFactory.hpp"
#include "objects/SphereBuilder.hpp"
#include "objects/PlaneBuilder.hpp"
#include "utils/loader/PluginsManager.hpp"

namespace RayTracer::Utils {

    class ObjectFactory : public IObjectFactory {
        public:
            ObjectFactory(const std::string &path) {
                _manager = std::make_unique<PluginsManager>(path);
                _builders = _manager->loadPlugins();
            };
            ~ObjectFactory() override = default;
            RayTracer::IBuilder *createObjectBuilder(const std::string &type) override;
        private:
            std::unique_ptr<IPluginsManager> _manager;
            std::vector<std::unique_ptr<RayTracer::IBuilder>> _builders;
    };

}

#endif /*OBJECTFACTORY_HPP_*/