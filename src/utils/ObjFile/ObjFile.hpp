/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ObjFile.hpp
*/
#ifndef OBJFILE_HPP_
#define OBJFILE_HPP_
#include "IObjFile.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include "maths/Vector3D.hpp"
#include "utils/string/StringUtils.hpp"

namespace RayTracer {

    class ObjFile : public IObjFile {
        public:
            ObjFile() = default;
            ~ObjFile() = default;
            void load(const std::string &path) {
                _vertex.clear();
                _texture.clear();
                _normal.clear();
                std::string content;
                std::cout << "ObjFile loading file ... [" << path << "]" << std::endl;
                std::ifstream file(path);

                while (std::getline(file, content)) {
                    _parseLine(content);
                }
            }
        private:
            void _parseLine(const std::string &line) {
                std::stringstream parsed(line);
                std::string type;
                parsed >> type;
                if (type == "v") {
                    _parseVertex(parsed);
                } else if (type == "vt") {
                    _parseTexture(parsed);
                } else if (type == "vn") {
                    _parseNormal(parsed);
                } else if (type == "f") {
                    _parseFace(parsed);
                }
            }
            void _parseVertex(std::stringstream &parsed) {
                float x;
                float y;
                float z;

                parsed >> x;
                parsed >> y;
                parsed >> z;
                _vertex.push_back(Math::Vector3D(x, y, z));
            }
            void _parseTexture(std::stringstream &parsed) {
                float x;
                float y;

                parsed >> x;
                parsed >> y;
                _texture.push_back(std::make_pair(x, y));
            }
            void _parseNormal(std::stringstream &parsed) {
                float x;
                float y;
                float z;

                parsed >> x;
                parsed >> y;
                parsed >> z;
                _normal.push_back(Math::Vector3D(x, y, z));
            }

            std::array<int, 3> _parseStringByCharToInt(std::string &parsed, const char delim) {
                std::string tmp;
                std::vector<std::string> tokens;
                std::array<int, 3> result;
                std::string token;
                int x = 0;
                const int moveto = 1;

                tmp = parsed;
                while ((x = tmp.find(delim)) != std::string::npos) {
                    token = tmp.substr(0, x);
                    tokens.push_back(token);
                    tmp.erase(0, x + moveto);
                }
                tokens.push_back(tmp);
                int i = 0;
                for (auto x : tokens) {
                    result[i++] = (std::stoi(x));
                }
                return result;
            }
            std::array<float, 3> _parseStringByCharToFloat(std::string &parsed, const char delim) {
                std::string tmp;
                std::vector<std::string> tokens;
                std::array<float, 3> result;
                std::string token;
                int x = 0;
                const int moveto = 1;

                tmp = parsed;
                while ((x = tmp.find(delim)) != std::string::npos) {
                    token = tmp.substr(0, x);
                    tokens.push_back(token);
                    tmp.erase(0, x + moveto);
                }
                tokens.push_back(tmp);
                int i = 0;
                for (auto x : tokens)
                    result[i++] = (std::stof(x));
                return result;
            }
            void _parseFace(std::stringstream &parsed) {
                std::string vertex;
                std::string texture;
                std::string normal;
                Math::Vector3D newPos[3];
                Math::Vector3D newNormal[3];
                int cursor = 0;

                parsed >> vertex;
                parsed >> texture;
                parsed >> normal;
                std::cout << "Face: " << vertex << " " << texture << " " << normal << std::endl;
                auto pos = _parseStringByCharToInt(vertex, '/');
                auto norm = _parseStringByCharToFloat(normal, '/');
                newPos[0] = getPosFromVertex(pos[0]); newPos[1] = getPosFromVertex(pos[1]); newPos[2] = getPosFromVertex(pos[2]);
                newNormal[0] = getNormalFromNormalList(norm[0]); newNormal[1] = getNormalFromNormalList(norm[1]); newNormal[2] = getNormalFromNormalList(norm[2]);

                std::cout << "generating with pos : " << newPos[0] << "," << newPos[1] << ", " << newPos[2] << std::endl;
                std::cout << "generating with normal : " << newNormal[0] << "," << newNormal[1] << ", " << newNormal[2] << std::endl;

            }
            Math::Vector3D getPosFromVertex(const int nb) {
                int i = 1;
                for (auto x : _vertex) {
                    if (i == nb)
                        return x;
                    i++;
                }
                return Math::Vector3D(0, 0, 0);
            }
            Math::Vector3D getNormalFromNormalList(const int nb) {
                int i = 1;
                for (auto x : _normal) {
                    if (i == nb)
                        return x;
                    i++;
                }
                return Math::Vector3D(0, 0, 0);
            }
            std::vector<Math::Vector3D> _vertex;
            std::vector<std::pair<double, double>> _texture;
            std::vector<Math::Vector3D> _normal;
    };

}

#endif /*OBJFILE_HPP_*/