//
// Created by 1 on 2024/5/19.
//

#include "CFish.h"


Fish::Fish(int weight) : weight(weight) {}

int Fish::getWeight() const {
    return weight;
}

void Fish::grow() {
    weight += 1;  // ����ÿ�γɳ�����1��λ����
}
