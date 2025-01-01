#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_COUNT 3
#define MIN_NUM 10
#define MAX_NUM 99

// 隨機數生成模組
void generate_numbers(int secret[]) {
    srand(time(NULL));
    for (int i = 0; i < NUM_COUNT; ) {
        int num = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
        // 檢查是否重複
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
// 玩家輸入與驗證模組
    int get_guess(int guess[]) {
        printf("請輸入三個二位數字，以空格分隔（例如：32 78 99）：");
        int count = scanf("%d %d %d", &guess[0], &guess[1], &guess[2]);
        while (getchar() != '\n'); // 清除輸入緩衝區
        if (count != NUM_COUNT) {
            printf("輸入錯誤：請輸入恰好三個二位數字。\n");
            return 0;
        }
        for (int i = 0; i < NUM_COUNT; i++) {
            if (guess[i] < MIN_NUM || guess[i] > MAX_NUM) {
                printf("輸入錯誤：所有數字必須是二位數。\n");
                return 0;
            }
        }
        return 1;
    }
// 比較邏輯與輸出模組
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
    printf("歡迎來到數字猜謎遊戲！\n");
    // 若要顯示答案以便測試，請取消下一行註解
    // printf("秘密數字: %d %d %d\n", secret[0], secret[1], secret[2]);

    while (1) {
        if (!get_guess(guess)) {
            continue;
        }
        attempts++;
        compare_numbers(secret, guess, &A, &B, &C);
        if (C == NUM_COUNT) {
            printf("恭喜你！全部猜中！總共猜了 %d 次。\n", attempts);
            break;
        }
        else {
            printf("%dA%dB%dC\n", A, B, C);
        }
    }
    return 0;
}