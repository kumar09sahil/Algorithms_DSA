/* execution of Matrix Multiplication (i) Divide-and-conquer 
(ii) Volker Strassen’s approaches. 
*/

#include <stdio.h>
#include<stdbool.h>

void strassen(int n,int A[n][n],int B[n][n],int C[n][n]) {
    if (n <= 2) {  
        int a = A[0][0], b = A[0][1], c = A[1][0], d = A[1][1];
        int e = B[0][0], f = B[0][1], g = B[1][0], h = B[1][1];

        int p1 = a * (f - h);
        int p2 = (a + b) * h;
        int p3 = (c + d) * e;
        int p4 = d * (g - e);
        int p5 = (a + d) * (e + h);
        int p6 = (b - d) * (g + h);
        int p7 = (a - c) * (e + f);

        C[0][0] = p5 + p4 - p2 + p6;
        C[0][1] = p1 + p2;
        C[1][0] = p3 + p4;
        C[1][1] = p1 + p5 - p3 - p7;
    }  else{
        int newSize = n / 2;
        int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
        int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
        int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
        int P1[newSize][newSize], P2[newSize][newSize], P3[newSize][newSize], P4[newSize][newSize];
        int P5[newSize][newSize], P6[newSize][newSize], P7[newSize][newSize];
        for (int i = 0; i < newSize; i++) {
            for (int j = 0; j < newSize; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + newSize];
                A21[i][j] = A[i + newSize][j];
                A22[i][j] = A[i + newSize][j + newSize];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + newSize];
                B21[i][j] = B[i + newSize][j];
                B22[i][j] = B[i + newSize][j + newSize];
            }
        }

        strassen(newSize, A11, B11, P1);
        strassen(newSize, A12, B21, P2);
        strassen(newSize, A11, B12, P3);
        strassen(newSize, A12, B22, P4);
        strassen(newSize, A21, B11, P5);
        strassen(newSize, A22, B21, P6);
        strassen(newSize, A21, B12, P7);

        for (int i = 0; i < newSize; i++) {
            for (int j = 0; j < newSize; j++) {
                C11[i][j] = P5[i][j] + P4[i][j] - P2[i][j] + P6[i][j];
                C12[i][j] = P1[i][j] + P2[i][j];
                C21[i][j] = P3[i][j] + P4[i][j];
                C22[i][j] = P1[i][j] + P5[i][j] - P3[i][j] - P7[i][j];
            }
        }
        for (int i = 0; i < newSize; i++) {
            for (int j = 0; j < newSize; j++) {
                C[i][j] = C11[i][j];
                C[i][j + newSize] = C12[i][j];
                C[i + newSize][j] = C21[i][j];
                C[i + newSize][j + newSize] = C22[i][j];
            }
        }
    }
}


int main() {
    int n; 
    printf("Enter the size of the square matrices : ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];

    printf("Enter matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter matrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    strassen(n, A, B, C);

    printf("Result matrix C:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}