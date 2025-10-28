#include <stdio.h>

#define MAX 10

void readMatrix(int a[MAX][MAX], int r, int c) {
    printf("Enter elements:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
}

void displayMatrix(int a[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void addMatrix(int a[MAX][MAX], int b[MAX][MAX], int r, int c) {
    int sum[MAX][MAX];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            sum[i][j] = a[i][j] + b[i][j];

    printf("Matrix Addition:\n");
    displayMatrix(sum, r, c);
}

void multiplyMatrix(int a[MAX][MAX], int b[MAX][MAX], int r1, int c1, int r2, int c2) {
    if (c1 != r2) {
        printf("Matrix multiplication not possible!\n");
        return;
    }

    int mul[MAX][MAX] = {0};

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                mul[i][j] += a[i][k] * b[k][j];

    printf("Matrix Multiplication:\n");
    displayMatrix(mul, r1, c2);
}

void transposeMatrix(int a[MAX][MAX], int r, int c) {
    int t[MAX][MAX];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            t[j][i] = a[i][j];

    printf("Transpose of Matrix:\n");
    displayMatrix(t, c, r);
}

int main() {
    int a[MAX][MAX], b[MAX][MAX];
    int r1, c1, r2, c2;
    int choice;

    printf("Matrix Operations Menu:\n");
    printf("1. Addition\n2. Multiplication\n3. Transpose\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter rows and cols for matrices: ");
            scanf("%d %d", &r1, &c1);
            printf("Enter Matrix A:\n");
            readMatrix(a, r1, c1);
            printf("Enter Matrix B:\n");
            readMatrix(b, r1, c1);
            addMatrix(a, b, r1, c1);
            break;

        case 2:
            printf("Enter rows and cols for Matrix A: ");
            scanf("%d %d", &r1, &c1);
            printf("Enter rows and cols for Matrix B: ");
            scanf("%d %d", &r2, &c2);
            printf("Enter Matrix A:\n");
            readMatrix(a, r1, c1);
            printf("Enter Matrix B:\n");
            readMatrix(b, r2, c2);
            multiplyMatrix(a, b, r1, c1, r2, c2);
            break;

        case 3:
            printf("Enter rows and cols for Matrix: ");
            scanf("%d %d", &r1, &c1);
            printf("Enter Matrix:\n");
            readMatrix(a, r1, c1);
            transposeMatrix(a, r1, c1);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}