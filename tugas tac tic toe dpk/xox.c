
#include <stdio.h>

char papan[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void tampilkanPapan(void) {
    printf("\n");
    printf(" %c | %c | %c\n", papan[0][0], papan[0][1], papan[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", papan[1][0], papan[1][1], papan[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", papan[2][0], papan[2][1], papan[2][2]);
}

int cekMenang(void) {
    int i;

    for (i = 0; i < 3; i++) {
        if (papan[i][0] == papan[i][1] &&
            papan[i][1] == papan[i][2])
            return 1;

        if (papan[0][i] == papan[1][i] &&
            papan[1][i] == papan[2][i])
            return 1;
    }

    if (papan[0][0] == papan[1][1] &&
        papan[1][1] == papan[2][2])
        return 1;

    if (papan[0][2] == papan[1][1] &&
        papan[1][1] == papan[2][0])
        return 1;

    return 0;
}

int papanPenuh(void) {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (papan[i][j] != 'X' &&
                papan[i][j] != 'O')
                return 0;
        }
    }

    return 1;
}

int main(void) {
    char pemain = 'X';
    int posisi, baris, kolom;

    printf("=== TIC TAC TOE ===\n");

    while (1) {
        tampilkanPapan();

        printf("\nGiliran pemain %c\n", pemain);
        printf("Pilih posisi (1-9): ");

        if (scanf("%d", &posisi) != 1) {
            printf("Masukkan angka yang valid!\n");

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
            }
            continue;
        }

        if (posisi < 1 || posisi > 9) {
            printf("Pilih angka 1 sampai 9!\n");
            continue;
        }

        baris = (posisi - 1) / 3;
        kolom = (posisi - 1) % 3;

        if (papan[baris][kolom] == 'X' ||
            papan[baris][kolom] == 'O') {
            printf("Kotak sudah terisi!\n");
            continue;
        }

        papan[baris][kolom] = pemain;

        if (cekMenang()) {
            tampilkanPapan();
            printf("\nPemain %c MENANG!\n", pemain);
            break;
        }

        if (papanPenuh()) {
            tampilkanPapan();
            printf("\nPermainan SERI!\n");
            break;
        }

        pemain = (pemain == 'X') ? 'O' : 'X';
    }

    return 0;
}
