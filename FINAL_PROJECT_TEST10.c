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