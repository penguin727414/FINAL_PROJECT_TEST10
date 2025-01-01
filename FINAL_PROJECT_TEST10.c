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