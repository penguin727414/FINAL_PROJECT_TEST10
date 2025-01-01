#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_COUNT 3
#define MIN_NUM 10
#define MAX_NUM 99

// �H���ƥͦ��Ҳ�
void generate_numbers(int secret[]) {
    srand(time(NULL));
    for (int i = 0; i < NUM_COUNT; ) {
        int num = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
        // �ˬd�O�_����
        int duplicate = 0;
        for (int j = 0; j < i; j++) {
            if (secret[j] == num) {
                duplicate = 1;
                break;
            }
        }
        if (!duplicate) {
            secret[i++] = num;
        }
    }
}