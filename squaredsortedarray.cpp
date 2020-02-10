#include <iostream>
using namespace std;

void sq_sort(int arr[], int size) {
    int sq_sort_arr[size] = {0};
    int i = 0, k = 0; 
    while(arr[i]<0) i++;
    // cout<<arr[--i]<<endl;
    int j = i--;
    while(i >= 0 && j < size) {
        if(abs(arr[i]) < arr[j]) sq_sort_arr[k++] = arr[i]*arr[i--];
        else sq_sort_arr[k++] = arr[j]*arr[j++];    
    }
    while (i>=0) sq_sort_arr[k++] = arr[i]*arr[i--];
    while (j<size) sq_sort_arr[k++] = arr[j]*arr[j++];
    for(int num: sq_sort_arr) cout<<num<<" ";
    cout<<endl;
}

int main() {
    int arr[6] = {-6, -4, -1, 2, 3, 5};
    sq_sort(arr, 6);
    return 0;
}