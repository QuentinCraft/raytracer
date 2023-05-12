/*
** EPITECH PROJECT, 2023
** UnlimitedCylinderData
** File description:
** UnlimitedCylinderData
*/

#ifndef UNLIMITEDCYLINDERDATA_HPP_
#define UNLIMITEDCYLINDERDATA_HPP_
#include "utils/config/data/AData.hpp"

namespace RayTracer {

    class UnlimitedCylinderData : public Utils::AData {
        public:
            UnlimitedCylinderData() : Utils::AData() {_type = "unlimitedCylinder";};
            ~UnlimitedCylinderData() {};
    };

}

#endif /* !UNLIMITEDCYLINDERDATA_HPP_ */
