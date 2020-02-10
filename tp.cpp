#include<iostream>
int n =10;
using namespace std;
int g;
// void function(int arr[]){
//     int size =sizeof(arr)/sizeof(arr[0]);
//     for(int i : arr)
//         cout<<i<<" ";
// }

int main(){
    int arr[n] = {0};
    int num = 100;
    int x;
    int * const ptr = &num;
    *ptr = 9;
    cout << [](int a, int b){ return a>b ? a:b ;} (10,9) << endl;
    cout << g << " " << x;
    // function(arr);
}