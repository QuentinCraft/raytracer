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
                _materials = _manager->loadMaterials();
                _textureBuilders = _manager->loadTextureBuilders();
            };
            ~ObjectFactory() {
                std::cout << "ObjectFactory destructor" << std::endl;
            };
            std::shared_ptr<RayTracer::IBuilder> createObjectBuilder(const std::string &type) override;
            std::shared_ptr<RayTracer::AMaterial> createMaterial(const std::string &type) override;
            std::shared_ptr<RayTracer::ITextureBuilder> createTextureBuilder(const std::string &type) override;
        private:
            std::unique_ptr<IPluginsManager> _manager;
            std::vector<std::shared_ptr<RayTracer::IBuilder>> _builders;
            std::vector<std::shared_ptr<RayTracer::AMaterial>> _materials;
            std::vector<std::shared_ptr<RayTracer::ITextureBuilder>> _textureBuilders;
    };

}

#endif /*OBJECTFACTORY_HPP_*/