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
#include "Loader.hpp"

namespace RayTracer::Utils {

    class PluginsManager {
        public:
            PluginsManager(const std::string &path) : _path(path) {_loader = std::make_unique<Loader>();};
            ~PluginsManager() {};
            std::vector<IBuilder *> load() {
                std::vector<IBuilder *> builders;

                for (const auto &entry : std::filesystem::directory_iterator(_path)) {
                    if (entry.path().extension() == ".so") {
                        std::cout << entry.path() << std::endl;
                    }
                }

                return builders;
            };
        private:
            std::string _path;
            std::unique_ptr<RayTracer::Utils::ILoader> _loader;

    };

}

#endif /*PLUGINSMANAGER_HPP_*/