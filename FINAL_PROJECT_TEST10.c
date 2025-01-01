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
// ���a��J�P���ҼҲ�
    int get_guess(int guess[]) {
        printf("�п�J�T�ӤG��Ʀr�A�H�Ů���j�]�Ҧp�G32 78 99�^�G");
        int count = scanf("%d %d %d", &guess[0], &guess[1], &guess[2]);
        while (getchar() != '\n'); // �M����J�w�İ�
        if (count != NUM_COUNT) {
            printf("��J���~�G�п�J��n�T�ӤG��Ʀr�C\n");
            return 0;
        }
        for (int i = 0; i < NUM_COUNT; i++) {
            if (guess[i] < MIN_NUM || guess[i] > MAX_NUM) {
                printf("��J���~�G�Ҧ��Ʀr�����O�G��ơC\n");
                return 0;
            }
        }
        return 1;
    }
// ����޿�P��X�Ҳ�
void compare_numbers(int secret[], int guess[], int* A, int* B, int* C) {
    *A = *B = *C = 0;
    for (int i = 0; i < NUM_COUNT; i++) {
        if (guess[i] > secret[i]) {
            (*A)++;
        }
        else if (guess[i] < secret[i]) {
            (*B)++;
        }
        else {
            (*C)++;
        }
    }
}

int main() {
    int secret[NUM_COUNT];
    int guess[NUM_COUNT];
    int A, B, C;
    int attempts = 0;

    generate_numbers(secret);
    printf("�w��Ө�Ʀr�q���C���I\n");
    // �Y�n��ܵ��ץH�K���աA�Ш����U�@�����
    // printf("���K�Ʀr: %d %d %d\n", secret[0], secret[1], secret[2]);

    while (1) {
        if (!get_guess(guess)) {
            continue;
        }
        attempts++;
        compare_numbers(secret, guess, &A, &B, &C);
        if (C == NUM_COUNT) {
            printf("���ߧA�I�����q���I�`�@�q�F %d ���C\n", attempts);
            break;
        }
        else {
            printf("%dA%dB%dC\n", A, B, C);
        }
    }
    return 0;
}