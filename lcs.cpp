#include <iostream>
#include <cstring>
using namespace std;

int lcs(char* s1, char* s2, int **dp, int l1, int l2) {
    if(dp[l1][l2] != -1) return dp[l1][l2]; 
    int result;
    if(l1 == 0 || l2 == 0) result = 0;
    else if(s1[0] == s2[0]) {
        result =  1 + lcs(s1+1, s2+1, dp, l1-1, l2-1);
    }
    else {
        int temp1 = lcs(s1, s2+1, dp, l1, l2-1);
        int temp2 = lcs(s1+1, s2, dp, l1-1, l2);
        result = max(temp1, temp2);
    }
    dp[l1][l2] = result;
    return result;
}

int main() {
    char s1[] = "aa";
    char s2[] = "bbb";
    int **dp = new int*[strlen(s1)+1];
    for(int i = 0 ; i <= strlen(s1); i++) {
        dp[i] = new int[strlen(s2)+1];
        for(int j = 0; j <= strlen(s2); j++)
            dp[i][j] = -1;
    }
    cout<<"Length of longest common subsequence is : "<<lcs(s1,s2,dp,strlen(s1), strlen(s2));
    return 0;
}