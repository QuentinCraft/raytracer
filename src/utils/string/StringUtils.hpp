/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** StringUtils.hpp
*/
#ifndef STRINGUTILS_HPP_
#define STRINGUTILS_HPP_
#include <iostream>
#include <sstream>
#include <vector>

namespace RayTracer::Utils {
    //
    class StringUtils {
        public:
            static std::vector<std::string> split(const std::string& str, const std::string& delim) {
                std::vector<std::string> tokens;
                std::string token;
                size_t at = 0;
                std::string tmp = str;

                while ((at = tmp.find(delim)) != std::string::npos) {
                    token = tmp.substr(0, at);
                    tokens.push_back(token);
                    tmp.erase(0, at + delim.length());
                }

                return tokens;
            }
    };
    //
}

#endif /*STRINGUTILS_HPP_*/