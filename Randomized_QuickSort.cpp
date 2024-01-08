/* C++ program to implement the “Randomized Quick sort” algorithm (Divide-and-
conquer approach) using pointer. */

#include <iostream>
#include <cstdlib>  
#include <ctime>
using namespace std ;    

void swap(int *x , int *y ){
    int temp = *x ;
    *x = *y ;
    *y = temp ;
}

int randomizedPartition(int arr[], int lb, int ub) {
    int random = lb + rand() % (ub - lb + 1);
    swap(arr[random], arr[lb]);
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    int temp;

    while (start < end) {
        while (arr[start] <= pivot) {
            start++;
        }
        while (arr[end] > pivot) {
            end--;
        }
        if (start < end) {
            swap(&arr[start] , &arr[end]) ;
        }
    }

    swap(&arr[lb] , &arr[end]) ;

    return end;
}

void randomizedQuickSort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int j = randomizedPartition(arr, lb, ub);
        randomizedQuickSort(arr, lb, j - 1);
        randomizedQuickSort(arr, j + 1, ub);
    }
}

void printelement(int arr[] , int *start , int *end){
    for(int i= *start ; i<*end ; i++){
        cout<< arr[i] << "\t" ;
    }
}

int main() {
    int arr[50], n;
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "\nEnter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    randomizedQuickSort(arr, 0, n - 1);
    cout << "\nSorted Array:\n";
    int s = 0 ;
    printelement(arr,&s,&n) ;
    return 0;
}