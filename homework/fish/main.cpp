#include <iostream>
#include "CFish.h"
#include "CPool.h"
#include "CFishman.h"
#include <cstdlib>  // 随机数
#include <ctime>
#include <windows.h>

using namespace std;

int random(int a, int b) {
    int num = 0;
    num = rand() % (b - a) + a;
    return num;
}

int main() {
    int i;
    srand(time(NULL));
    Pool* pool = new Pool(7);
    Fisherman* man = new Fisherman();

    while (true) {
        pool->printFishInfo();
        cout << "你想让渔夫钓第几只鱼?：" << endl;
        cin >> i;

        Fish* fish = pool->get_fish(i - 1);  // 人选中了某池塘中的某只鱼
        if (fish == NULL) {
            cout << "鱼不存在" << endl;
        } else {
            man->fishing(fish);  // 人捕了这条鱼
            pool->update_fishCount();
        }

        int fishCount = pool->get_fishCount();
        if (fishCount == 0) break;

        pool->printFishInfo();
        pool->grow_fish();  // 池塘所有的鱼都会成长
        Sleep(1000);
        cout << "鱼长大了" << endl;
    }

    cout << "池塘没鱼了" << endl;
    cout << "渔夫一共捕了" << man->get_got_fish_sum() << "条鱼" << endl;
    cout << "渔夫放生了" << man->get_release_fish_sum() << "条鱼" << endl;

    system("pause");
    return 0;
}
