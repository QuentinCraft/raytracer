/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PluginsManager.hpp
*/

#ifndef PLUGINSMANAGER_HPP_
#define PLUGINSMANAGER_HPP_
#include <iostream>
#include <vector>
#include <filesystem>
#include <string>
#include "utils/builder/IBuilder.hpp"
#include "utils/Error.hpp"
#include "LibraryLoader.hpp"
#include "IPluginsManager.hpp"

namespace RayTracer::Utils {

    class PluginsManager : public IPluginsManager {
        public:
            PluginsManager(const std::string &path) : _path(path) {_loader = std::make_unique<LibraryLoader>();};
            ~PluginsManager() override = default;
            std::vector<std::shared_ptr<IBuilder>> loadPlugins() override {
                std::vector<std::shared_ptr<IBuilder>> builders;

                for (const auto &entry : std::filesystem::directory_iterator(_path)) {
                    if (entry.path().extension() == ".so") {
                        std::cout << "Loading... " << entry.path();
                        auto lib = _loader->loadLib<IBuilder *>(entry.path());
                        std::cout << " name : " << lib->getBuilderName();
                        builders.push_back(std::shared_ptr<IBuilder>(lib));
                        std::cout << " [OK]" << std::endl;
                    }
                }

                return builders;
            };
        private:
            std::string _path;
            std::unique_ptr<RayTracer::Utils::LibraryLoader> _loader;

    };

}

#endif /*PLUGINSMANAGER_HPP_*/