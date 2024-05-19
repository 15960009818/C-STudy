#include "CPool.h"
#include <iostream>

Pool::Pool(int size) : fishCount(size) {
    for (int i = 0; i < size; ++i) {
        fishes.push_back(new Fish(rand() % 10 + 1));  // �������������1��10֮�����
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
    std::cout << "\n��������\n";
    for (std::vector<Fish*>::const_iterator it = fishes.begin(); it != fishes.end(); ++it) {
        if (*it != NULL) {
            std::cout << "�� " << (it - fishes.begin()) + 1<< "\n";
        } else {
            std::cout << "�� " << (it - fishes.begin()) + 1 << ": �ѱ�����\n";
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
