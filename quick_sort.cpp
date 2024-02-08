// Ramdomize quicksort sort in C++
//Developed by: Sanjeevlu, Yashwanth, Upender, Bharath
//Date: 02 - 07 - 2024
//CSCI 3400
#include<iostream>
using namespace std;

int partition(int arr[], int left, int right) {

    int randPivotIndex = rand() % right + 1;
    swap(arr[randPivotIndex], arr[right]);

    int pivot = arr[right];; //Task 3: consider the last element of the array as a pivot
    int pIndex = left; //pIndex represents the actual index of the pivot in the sorted list
    //set pIndex to the left index initailly

    for (int i = left; i < right; i++) { //Task 4
        if (arr[i] <= pivot) { //Task 5
            swap(arr[i], arr[pIndex]); //Task 6: swap when an element <= pivot 
            pIndex = pIndex + 1; //Task 7
        }
    }
    swap(arr[pIndex], arr[right]); //swap arr[end], i.e., the pivot, with the element at pIndex
    // The previous line helps to place the pivot in its proper place in the sorted array 
    return pIndex; //Task 8
}

void quick_sort(int arr[], int left, int right) {
    if (left < right) {
        int pIndex = partition(arr, left, right);
        quick_sort(arr, left, pIndex - 1); //Task 1: recursively call the function for the left subarray of the pivot
        quick_sort(arr, pIndex + 1, right); //Task 2: recursively call the function for the right subarray of the pivot
    }
}

// Function to swap 2 numbers 
void swap(int& num1, int& num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
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

    quick_sort(arr, 0, size - 1);

    cout << "Sorted array: ";
    printArray(arr, size);
    return 0;
}