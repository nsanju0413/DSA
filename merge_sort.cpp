// Merge sort in C++
//Developed by: Sanjeevlu, Yashwanth, Upender, Bharath
//Date: 02 - 07 - 2024
//CSCI 3400

#include <iostream>
using namespace std;

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i]; //Task 6
            i++;
        }
        else {
            arr[k] = M[j]; //task 7
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {
        arr[k] = L[i]; //Task 8
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j]; //Task 9
        j++;
        k++;
    }
}

void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int left, int right) {
    if (right - left + 1 < 3) { //Task 1
        insertionSort(arr, left, right);
    }
    else {
        // mid is the point where the array is divided into two subarrays
        int mid = (right + left) / 2; //Task 2

        mergeSort(arr, left, mid); //Task 3: recursively call the function for the left half 
        mergeSort(arr, mid + 1, right); //Task 4: recursively call the function for the right half 

        // Merge the sorted subarrays   
        merge(arr, left, mid, right); //Task 5: merge the solutions of left and right sub arrays
    }
}

// Print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver program
int main() {
    int arr[] = { 16, 55, 12, -23, 94, 11, 45, 2, -64, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    printArray(arr, size);
    return 0;
}