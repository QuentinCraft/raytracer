/*
** EPITECH PROJECT, 2023
** CylinderData.hpp
** File description:
** CylinderData
*/

#ifndef CYLINDERDATA_HPP_
#define CYLINDERDATA_HPP_
#include "utils/config/data/AData.hpp"

namespace RayTracer {

    class CylinderData : public Utils::AData {
        public:
            CylinderData() : Utils::AData() {_type = "12345";};
            ~CylinderData() {};
    };

}

#endif /* !CYLINDERDATA_HPP_ */
