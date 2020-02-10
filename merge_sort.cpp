#include <iostream>

using namespace std;

void merge(int* arr, int s, int e, int n) {
    int mid = (s + e) / 2;
    int temp[n] = {0};
    int i = s, j = mid + 1, k = s;
    while(i <= mid && j <= e) {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else 
            temp[k++] = arr[j++];
    }
    while (i<=mid) temp[k++] = arr[i++];
    while (j<=e) temp[k++] = arr[j++];

    for(int i = s; i <= e; i++)
        arr[i] = temp[i];    
}

void merge_sort(int* arr, int s, int e, int n) {
    if(s >= e) return;
    int mid = (s + e)/2;
    merge_sort(arr, s, mid, n);
    merge_sort(arr, mid+1, e, n);
    merge(arr, s, e, n);
}

int main() {

    int arr[7] = {5,3,6,1,0,98,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr, 0 , size-1, size);
    for(int i : arr)
        cout<<i<<"\t";
    cout<<endl;
    return 0;
}