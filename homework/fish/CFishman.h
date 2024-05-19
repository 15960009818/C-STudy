#ifndef CFISHERMAN_H
#define CFISHERMAN_H

#include "CFish.h"

class Fisherman {
public:
    Fisherman();
    void fishing(Fish* fish);
    void digest();
    int get_got_fish_sum() const;
    int get_release_fish_sum() const;

private:
    Fish* fishArr[5];
    int fishCount;
    int gotFishSum;
    int releaseFishSum;
};

#endif // CFISHERMAN_H

