#include <iostream>
using namespace std;

int partitionMiddle(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    swap(arr[low], arr[mid]);   
    int pivot = arr[low];

    int i = low + 1;
    int j = high;

    while (true) {
        while (i <= high && arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;

        if (i < j)
            swap(arr[i], arr[j]);
        else
            break;
    }

    swap(arr[low], arr[j]);
    return j;
}

void quickSortMiddle(int arr[], int low, int high) {
    if (low < high) {
        int p = partitionMiddle(arr, low, high);
        quickSortMiddle(arr, low, p - 1);
        quickSortMiddle(arr, p + 1, high);
    }
}
