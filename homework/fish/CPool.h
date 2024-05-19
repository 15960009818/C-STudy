#ifndef CPOOL_H
#define CPOOL_H

#include "CFish.h"
#include <vector>

class Pool {
public:
    Pool(int size);
    ~Pool();
    Fish* get_fish(int index);
    void printFishInfo() const;
    void update_fishCount();
    int get_fishCount() const;
    void grow_fish();

private:
    std::vector<Fish*> fishes;
    int fishCount;
};

#endif // CPOOL_H

