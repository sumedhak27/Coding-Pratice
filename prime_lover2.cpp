#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> primes(int n) {
    vector<int> res;
    if(n < 1) return res; 
    vector<bool> arr(n, true);
    arr[0] = false; arr[1] = false;
    for(int i = 2; i*i < n; i++)
        if(arr[i])
            for(int j = i*i; j < n; j+=i)
                arr[j] = false;
    for(int i = 0; i<n; i++)
        if(arr[i]) 
            res.push_back(i);
    return res;
}

int main() {
    auto p = primes(7000000);
    // for(auto itr = p.begin(); itr!=p.end(); itr++)
    //     cout<<*itr<<" ";
    // cout<<endl;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int tree_height[n] = {0};
        for(int i = 0; i < n; i++){
            cin>>tree_height[i];
            int curr_num = tree_height[i];
            // int next_prime = *lower_bound(p.begin(), p.end(), curr_num);
            // tree_height[i] = next_prime - curr_num;
            tree_height[i] = *lower_bound(p.begin(), p.end(), tree_height[i]) - tree_height[i];
            // cout<<next_prime<<" ";
        }
        int arr[n];
        for(int i = 0; i<n; i++) {
            arr[i] = i;
        }
        sort(arr, arr+n, [&](int x, int y) {
            if(tree_height[x] == tree_height[y])
                return x < y;
            return tree_height[x] < tree_height[y];
        });
        for(int i : arr)
            cout<<i+1<<" ";
        cout<<endl;
    }
    return 0;
}