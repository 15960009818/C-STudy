#include <iostream>
#include "CFish.h"
#include "CPool.h"
#include "CFishman.h"
#include <cstdlib>  // �����
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
        cout << "�����������ڼ�ֻ��?��" << endl;
        cin >> i;

        Fish* fish = pool->get_fish(i - 1);  // ��ѡ����ĳ�����е�ĳֻ��
        if (fish == NULL) {
            cout << "�㲻����" << endl;
        } else {
            man->fishing(fish);  // �˲���������
            pool->update_fishCount();
        }

        int fishCount = pool->get_fishCount();
        if (fishCount == 0) break;

        pool->printFishInfo();
        pool->grow_fish();  // �������е��㶼��ɳ�
        Sleep(1000);
        cout << "�㳤����" << endl;
    }

    cout << "����û����" << endl;
    cout << "���һ������" << man->get_got_fish_sum() << "����" << endl;
    cout << "��������" << man->get_release_fish_sum() << "����" << endl;

    system("pause");
    return 0;
}
