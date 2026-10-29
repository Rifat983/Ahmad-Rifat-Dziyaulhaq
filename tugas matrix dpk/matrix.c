
#include <stdio.h>

int main() {
    int A[4][4], B[4], C[4];
    int i, j;

    // Input matriks 4x4
    printf("Masukkan elemen matriks A (4x4):\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // Input vektor 4x1
    printf("\nMasukkan elemen vektor B (4x1):\n");
    for (i = 0; i < 4; i++) {
        printf("B[%d] = ", i);
        scanf("%d", &B[i]);
    }

    // Perkalian matriks dengan vektor
    for (i = 0; i < 4; i++) {
        C[i] = 0;
        for (j = 0; j < 4; j++) {
            C[i] += A[i][j] * B[j];
        }
    }

    // Menampilkan hasil
    printf("\nHasil perkalian A x B:\n");
    for (i = 0; i < 4; i++) {
        printf("%d\n", C[i]);
    }

    return 0;
}
