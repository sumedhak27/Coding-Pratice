#include<iostream>
using namespace std;

int l_c_s(string s1, string s2, int **dp,int l1,int l2) {
    // for(int i = 0 ; i <= 8; i++) {
    //     for(int j = 0; j <= 6; j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    // cout<<endl;
    if(dp[l1][l2] != -1) return dp[l1][l2]; 
    if(l1 == 0 || l2 == 0) {dp[l1][l2] = 0;return 0;}
    string ds1 = s1, ds2 = s2;
    s1.pop_back();
    s2.pop_back();
    int result;
    if(ds1[l1-1] == ds2[l2-1]) {
        result =  1 + l_c_s(s1,s2,dp,s1.length(), s2.length());
    }
    else {
        int temp1 = l_c_s(s1, ds2, dp, s1.length(), ds2.length());
        int temp2 = l_c_s(ds1, s2, dp, ds1.length(), s2.length());
        result = max(temp1, temp2);
    }
    dp[l1][l2] = result;
    return result;
}

int main() {
    string s1 = "sabcedfgh", s2 = "sumedh";
    int l1 = s1.length(), l2 = s2.length(); 
    int **dp = new int*[l1+1];
    for(int i = 0 ; i <= l1; i++) {
        dp[i] = new int[l2+1];
        for(int j = 0; j <= l2; j++)
            dp[i][j] = -1;
    }
    cout<<"Length of longest common subsequence is : "<<l_c_s(s1,s2,dp,l1,l2);
    return 0;
}