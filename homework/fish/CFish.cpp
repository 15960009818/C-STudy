//
// Created by 1 on 2024/5/19.
//

#include "CFish.h"


Fish::Fish(int weight) : weight(weight) {}

int Fish::getWeight() const {
    return weight;
}

void Fish::grow() {
    weight += 1;  // 假设每次成长增加1单位重量
}
