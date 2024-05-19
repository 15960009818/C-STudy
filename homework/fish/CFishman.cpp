#include "CFishman.h"
#include <iostream>

Fisherman::Fisherman() : fishCount(0), gotFishSum(0), releaseFishSum(0) {}

void Fisherman::fishing(Fish* fish) {
    if (fish->getWeight() >= 6) {
        this->fishArr[this->fishCount++] = fish;
        std::cout << "����ɹ�: " << this->fishCount << ", ���� = " << fish->getWeight() << std::endl;
        ++gotFishSum;

        if (this->fishCount == 5) {
            this->digest();
            std::cout << "�������" << std::endl;
            this->fishCount = 0;
        }
    } else {
        ++releaseFishSum;
        std::cout << "�������㣬�Ź�󺣣����� = " << fish->getWeight() << std::endl;
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
