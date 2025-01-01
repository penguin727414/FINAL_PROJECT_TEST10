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