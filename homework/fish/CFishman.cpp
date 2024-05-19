#include "CFishman.h"
#include <iostream>

Fisherman::Fisherman() : fishCount(0), gotFishSum(0), releaseFishSum(0) {}

void Fisherman::fishing(Fish* fish) {
    if (fish->getWeight() >= 6) {
        this->fishArr[this->fishCount++] = fish;
        std::cout << "捕鱼成功: " << this->fishCount << ", 重量 = " << fish->getWeight() << std::endl;
        ++gotFishSum;

        if (this->fishCount == 5) {
            this->digest();
            std::cout << "消化完毕" << std::endl;
            this->fishCount = 0;
        }
    } else {
        ++releaseFishSum;
        std::cout << "重量不足，放归大海，重量 = " << fish->getWeight() << std::endl;
    }
}

void Fisherman::digest() {
    for (int i = 0; i < this->fishCount; ++i) {
        delete this->fishArr[i];
        this->fishArr[i] = NULL; // Make sure to reset the pointer
    }
}

int Fisherman::get_got_fish_sum() const {
    return gotFishSum;
}

int Fisherman::get_release_fish_sum() const {
    return releaseFishSum;
}
