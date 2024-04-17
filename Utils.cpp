//
// Created by Diogo on 30/12/2022.
//

#include "Utils.h"
#include "Food.h"

bool Utils::isNumber(const string &str) {
    for (int i = 0; i < str.size(); i++)
        if (!isdigit(str[i]))
            return false;

    return true;
}

