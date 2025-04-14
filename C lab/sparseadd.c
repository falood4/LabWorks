#include <stdio.h>

void sparse(int d[][100], int r, int c, int b[][3]) {
    int n = 0, m = 1, i, j, k;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (d[i][j] != 0) {
                b[m][0] = i;
                b[m][1] = j;
                b[m][2] = d[i][j];
                n++;
                m++;
            }
        }
    }
    b[0][0] = r;
    b[0][1] = c;
    b[0][2] = n;
}

void addsparse(int a[][3], int b[][3], int madd[][3]) {
    int s = 1, i = 1, j = 1;
    madd[0][0] = a[0][0];
    madd[0][1] = a[0][1];
    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] == b[j][0]) {
            if (a[i][1] == b[j][1]) {
                int temp = a[i][2] + b[j][2];
                if (temp != 0) {
                    madd[s][0] = a[i][0];
                    madd[s][1] = a[i][1];
                    madd[s][2] = temp;
                    s++;
                }
                i++;
                j++;
            } else if (a[i][1] < b[j][1]) {
                madd[s][0] = a[i][0];
                madd[s][1] = a[i][1];
                madd[s][2] = a[i][2];
                s++;
                i++;
            } else {
                madd[s][0] = b[j][0];
                madd[s][1] = b[j][1];
                madd[s][2] = b[j][2];
                s++;
                j++;
            }
        } else if (a[i][0] < b[j][0]) {
            madd[s][0] = a[i][0];
            madd[s][1] = a[i][1];
            madd[s][2] = a[i][2];
            s++;
            i++;
        } else {
            madd[s][0] = b[j][0];
            madd[s][1] = b[j][1];
            madd[s][2] = b[j][2];
            s++;
            j++;
        }
    }
    while (i <= a[0][2]) {
        madd[s][0] = a[i][0];
        madd[s][1] = a[i][1];
        madd[s][2] = a[i][2];
        s++;
        i++;
    }
    while (j <= b[0][2]) {
        madd[s][0] = b[j][0];
        madd[s][1] = b[j][1];
        madd[s][2] = b[j][2];
        s++;
        j++;
    }
    madd[0][2] = s - 1;
}

int main() {
    int a, b, c[100][100], i, j, s1[100][3], x, y, z[100][100], p, q, s2[100][3];

    printf("First matrix\n");
    printf("Enter the number of rows =");
    scanf("%d", &a);
    printf("Enter the number of columns =");
    scanf("%d", &b);
    printf("\nEnter the elements:\n");
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            scanf("%d", &c[i][j]);
        }
    }
    printf("\nFirst matrix=\n");
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            printf("   %d    ", c[i][j]);
        }
        printf("\n");
    }

    sparse(c, a, b, s1);
    printf("\n1st Sparse=\n");
    for (i = 0; i <= s1[0][2]; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", s1[i][j]);
        }
        printf("\n");
    }

    printf("Second matrix\n");
    printf("Enter the number of rows =");
    scanf("%d", &x);
    printf("Enter the number of columns =");
    scanf("%d", &y);
    printf("\nEnter the elements:\n");
    for (p = 0; p < x; p++) {
        for (q = 0; q < y; q++) {
            scanf("%d", &z[p][q]);
        }
    }

    printf("\nSecond matrix=\n");
    for (p = 0; p < x; p++) {
        for (q = 0; q < y; q++) {
            printf("   %d    ", z[p][q]);
        }
        printf("\n");
    }

    sparse(z, x, y, s2);

    printf("\n2nd sparse=\n");
    for (i = 0; i <= s2[0][2]; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", s2[i][j]);
        }
        printf("\n");
    }

    printf("\nsum of sparses\n");
    int sparsesum[100][3];
    addsparse(s1, s2, sparsesum);
    for (i = 0; i <= sparsesum[0][2]; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", sparsesum[i][j]);
        }
        printf("\n");
    }

    return 0;
}

