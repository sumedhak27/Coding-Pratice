#include <iostream>
using namespace std;

int find_count(int n, int e, int x){
    if(n == 1) return 1;
    if(e == 1) return n;
    if(n == 0) return 0;
    return max(find_count(n-x, e, x), find_count(x-1, e-1, x))+1;    
}

// pair<int,int> find_x(int n, int e) {
//     int mini = INT32_MAX, ans_x = 1;
//     for(int x = 1 ; x<n-1 ; x++){
//         int curr_tries = find_count(n,e,x);
//         if(mini > curr_tries) {
//             mini = curr_tries;
//             ans_x = x;
//         }
//     }
//     return pair<int,int>(ans_x, mini);
// }
pair<int,int> find_x(int n, int e) {
    int mini = INT32_MAX, ans_x = 1;
    for(int x = 1 ; x<n-1 ; x++){
        int curr_tries = x + (n/x);
        if(mini > curr_tries){
            mini = curr_tries;
            ans_x = x;
        }
    }
    return pair<int,int>(ans_x, mini);
}


int main() {
    int n = 100, e = 2, x = 25;
    pair<int,int> ans = find_x(n, e);
    cout<<"Minimum number of tries will be "<<ans.second<<" with step of "<<ans.first<<"floors at a time."<<endl;
    return 0;
}