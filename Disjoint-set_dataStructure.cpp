/* C program to implement “MAKE-SET”, “FIND-SET”, and “UNION” oper-
ations for Disjoint-Set Data Structure based on Union-by-rank with Path compression
techniques.*/

#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int parent;
    int rank;
} Node;

Node *arr;


void makeset(int v) {
    arr[v].parent = v;
    arr[v].rank = 0;
}


int findset(int v) {
    if (v != arr[v].parent) {
        arr[v].parent = findset(arr[v].parent);
    }
    return arr[v].parent;
}

void munion(int u, int v) {
    int rootU = findset(u);
    int rootV = findset(v);

    if (rootU != rootV) {
        if (arr[rootU].rank < arr[rootV].rank) {
            arr[rootU].parent = rootV;
        } else if (arr[rootU].rank > arr[rootV].rank) {
            arr[rootV].parent = rootU;
        } else {
            arr[rootV].parent = rootU;
            arr[rootU].rank++;
        }
    }
}

int main() {
    int n, t = 0, i, j, flag, count = 0;

    printf("How many disjoint set you want to create?");
    scanf("%d", &n);
    arr = (Node *)malloc((n + 1) * sizeof(Node));
    for (i = 0; i < n; i++) {
        makeset(i);
    }
    printf("%d number of makeset operations are executed\n", n);
    printf("To stop Union operation, press -1\n");
    while (t != -1) {
        printf("Enter the value of t: ");
        scanf("%d", &t);
        if (t != -1) {
            printf("Enter i and j to perform Union(i,j) operation\n");
            printf("I = ");
            scanf("%d", &i);
            printf("J = ");
            scanf("%d", &j);
            munion(i, j);
            printf("UNION(%d,%d) is finished\n", i, j);
        }
    }
    printf("Do you want to find the connected components?\n");
    printf("Press '1' for YES or, '0' for NO: ");
    scanf("%d", &flag);
    if (flag == 1) {
        for (i = 0; i < n; i++) {
            if (findset(i) == i) {
                count++;
            }
        }
        printf("The number of connected component is %d\n", count);
    } else {
        printf("We do not want to find the connected components\n");
    }
    free(arr);
    return 0;
}