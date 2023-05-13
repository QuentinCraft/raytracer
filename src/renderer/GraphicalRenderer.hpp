/*
** EPITECH PROJECT, 2023
** GraphicalRenderer.hpp
** File description:
** GraphicalRenderer
*/

#ifndef GRAPHICALRENDERER_HPP_
#define GRAPHICALRENDERER_HPP_
#include "ARenderer.hpp"
#include "SFMLDisplayModule.hpp"
#include "utils/config/ConfigManager.hpp"
#include <memory>

namespace RayTracer {

    class GraphicalRenderer : public ARenderer {
        public:
            GraphicalRenderer(int width, int height, std::pair<std::string, std::string> currentConfig, bool *stop);
            ~GraphicalRenderer() override;
            void build(std::unique_ptr<RayTracer::Scene> &scene, bool fast) override;
        private:
            void eventHandler();
            std::unique_ptr<IDisplayModule> _displayModule;
            bool _isRunning;
            std::string _currentConfig;
            std::string _currentConfigPath;
            bool _reload = false;
            bool *_stopProgram;
    };

}

#endif /* !GRAPHICALRENDERER_HPP_ */
