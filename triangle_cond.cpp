#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n] = {0};
    for(int i = 0 ; i < n; i++) {
        cin>>arr[i];
    }
    sort(arr, arr+n);
    int i = 0, j = i+1, k = i+2;
    // cout<<i<<" "<<j<<" "<<k<<endl;
    while(k<n) {
        // cout<<"loop 1";
        while(j<k){
            // cout<<"loop 2";
            if(arr[i] + arr[j] > arr[k]){
                for (int s = j; s<k; s++){
                    cout<<arr[i]<<" "<<arr[s]<<" "<<arr[k]<<endl;
                }        
                k++;
                break;
            }
            if(j+1<k)
                j++;
            else break;   
        }
        while (i<j) {
            if(arr[i] + arr[j] > arr[k]){
                for (int s = j; s<k; s++){
                    cout<<arr[i]<<" "<<arr[s]<<" "<<arr[k]<<endl;
                }        
                k++;
                break;
            }
            if(i+1<j)
                i++;
            else break;  
        }
        if(i+1 == j && j+1 == k)  {i++,j++,k++;}
        else if( i+1 == j && j+1!=k) {i++,j++;}
        else if(i+1!=j) i++;
    }
    return 0;
}