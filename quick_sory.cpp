#include<iostream>

using namespace std;

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int swapIndex = left;
    for(int i = left; i<right; i++)
        if(arr[i] < pivot && i!=swapIndex) {
            swap(arr[i], arr[swapIndex]);
            swapIndex++;
        }
    swap(arr[swapIndex+1], arr[right]);
    return swapIndex+1;
}

void quickSort(int arr[], int left, int right) {
    if(left > right || left == right) return;
    else {
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex-1);
        quickSort(arr, pivotIndex+1, right);
    }
}

int main() {
    int arr[8] = {19,4,3,67,2,1,23,17};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0 , size-1);
    for(int i : arr)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}