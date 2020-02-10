#include <iostream>
#include <algorithm>

using namespace std;

int change(int x, int *arr, int size) {
    int dp[x+1] = {0};
    for(int i = 0; i < size; i++){
        dp[arr[i]] = 1;
    }
    for(int i = 1; i<=x; i++){
        if(dp[i] == 0){
            int mini = INT32_MAX;
            for(int j = 0; j < size; j++) {
                if( i - arr[j] >=0){
                    mini = min(mini, dp[i-arr[j]] + dp[arr[j]]);
                }
            }
            dp[i] = mini; 
        }
    }
    for(int i =0; i<=x; i++)
        cout<<dp[i]<<" ";
    cout<<endl;
    return dp[x];
}

int main() {

    int arr[] = {1,5, 10, 15, 25};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Min change required = "<<change(32, arr, size)<<endl;
    
    return 0;
}