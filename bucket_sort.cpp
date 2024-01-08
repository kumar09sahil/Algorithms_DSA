/* C++ program to sort n elements A[1], A[2], · · · , A[n] (A[1 · · · n] are uniformly distributed
over [0, 1)] using the “Bucket Sort” algorithm. In this program, you have to create n buckets
B[0], B[1], · · · , B[n − 1]. A bucket B[i] (0 ≤ i ≤ n − 1) holds the elements A[i1], A[i2], · · · , A[ik]
sharing the same index i by maintaining a separate linked list. */

#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    float info;
    struct Node* link;
};

// Function to perform insertion sort on a bucket
struct Node* Insertionsort(struct Node* list) {
    if (list == NULL || list->link == NULL) {
        return list;
    }

    struct Node* sorted = NULL;
    struct Node* current = list;

    while (current != NULL) {
        struct Node* next = current->link;

        if (sorted == NULL || current->info < sorted->info) {
            current->link = sorted;
            sorted = current;
        } else {
            struct Node* search = sorted;
            while (search->link != NULL && search->link->info < current->info) {
                search = search->link;
            }
            current->link = search->link;
            search->link = current;
        }

        current = next;
    }

    return sorted;
}

// Function to print elements of a bucket
void Printbuckets(struct Node* list) {
    struct Node* current = list;
    while (current != NULL) {
        printf("%.2f ", current->info);
        current = current->link;
    }
    printf("\n");
}

// Function to perform Bucket Sort
void Bucketsort(float A[], int n) {
    const int numBuckets = n;
    struct Node* buckets[numBuckets];

    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        int index = A[i] * numBuckets;
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->info = A[i];
        newNode->link = buckets[index];
        buckets[index] = newNode;
    }

    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        struct Node* sortedBucket = Insertionsort(buckets[i]);
        while (sortedBucket != NULL) {
            A[index++] = sortedBucket->info;
            struct Node* temp = sortedBucket;
            sortedBucket = sortedBucket->link;
            free(temp);
        }
    }
}

// Function to print the sorted array elements
void Printarray(float A[], int n) {
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", A[i]);
    }
    printf("\n");
}

int main() {
    int i, n;
    float A[20];

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter the %d array elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("A[%d] = ", i);
        scanf("%f", A + i);
    }

    Bucketsort(A, n);
    Printarray(A, n);

    return 0;
}