#include <iostream>

using namespace std;

void swap(int& a, int& b) { int t = a; a = b, b = t;}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int swapIndex = left;
    for(int i = left; i<right; i++) {
        if(arr[i] < pivot) {
            swap(arr[i], arr[swapIndex]);
            swapIndex++;
        }
    }
    swap(arr[swapIndex+1], arr[right]);
    return swapIndex+1;
}

int kth_smallest(int arr[], int left, int right,int k) {
    if (left > right) { return 0;}
    int index = partition(arr, left, right);
    if(index == k-1) return arr[index];
    else if (index > k-1) return kth_smallest(arr, left, index, k);
    else return kth_smallest(arr, index+1, right, k); 
}

int main() {
    int arr[8] = {19,4,3,67,2,1,23,17};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<kth_smallest(arr, 0 , size-1, 4)<<endl;
    return 0;
}