/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IPluginsManager.hpp
*/

#ifndef IPLUGINSMANAGER_HPP_
	#define IPLUGINSMANAGER_HPP_

#include "utils/builder/IBuilder.hpp"
#include "texture/ITextureBuilder.hpp"

namespace RayTracer::Utils {

    class IPluginsManager {
        public:
            virtual ~IPluginsManager() = default;

            virtual std::vector<std::shared_ptr<IBuilder>> loadPlugins() = 0;
            virtual std::vector<std::shared_ptr<AMaterial>> loadMaterials() = 0;
            virtual std::vector<std::shared_ptr<ITextureBuilder>> loadTextureBuilders() = 0;
    };

}

#endif /*IPLUGINSMANAGER_HPP_*/