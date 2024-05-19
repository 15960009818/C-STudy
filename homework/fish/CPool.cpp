#include "CPool.h"
#include <iostream>

Pool::Pool(int size) : fishCount(size) {
    for (int i = 0; i < size; ++i) {
        fishes.push_back(new Fish(rand() % 10 + 1));  // 随机生成重量在1到10之间的鱼
    }
}

Pool::~Pool() {
    for (std::vector<Fish*>::iterator it = fishes.begin(); it != fishes.end(); ++it) {
        delete *it;
    }
}

Fish* Pool::get_fish(int index) {
    if (index < 0 || index >= fishCount || fishes[index] == NULL) {
        return NULL;
    }
    return fishes[index];
}

void Pool::printFishInfo() const {
    std::cout << "\n鱼的情况：\n";
    for (std::vector<Fish*>::const_iterator it = fishes.begin(); it != fishes.end(); ++it) {
        if (*it != NULL) {
            std::cout << "鱼 " << (it - fishes.begin()) + 1<< "\n";
        } else {
            std::cout << "鱼 " << (it - fishes.begin()) + 1 << ": 已被捕捞\n";
        }
    }
}

void Pool::update_fishCount() {
    fishCount = 0;
    for (std::vector<Fish*>::iterator it = fishes.begin(); it != fishes.end(); ++it) {
        if (*it != NULL) {
            ++fishCount;
        }
    }
}

int Pool::get_fishCount() const {
    return fishCount;
}

void Pool::grow_fish() {
    for (std::vector<Fish*>::iterator it = fishes.begin(); it != fishes.end(); ++it) {
        if (*it != NULL) {
            (*it)->grow();
        }
    }
}
