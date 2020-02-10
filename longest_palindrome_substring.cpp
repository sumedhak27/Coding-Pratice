#include <iostream>
using namespace std;

int lps(char* s,int i, int j) {
    cout<<s[i]<<s[j]<<i<<j<<endl;
    if(i>j) return 0;
    if(s[i] == s[j]) {
        return (i == j ? 1 : 2) + lps(s, i+1, j-1);
    }
    else return max(lps(s, i, j-1), lps(s, i+1, j));
}

int main() {
    // int n;
    // cin>>n;\
    // char str[n];
    // for(int i = 0; i<n; i++)
    //     cin>>str[i];
    // cout<<lps(str, 0, n-1);
    char s[] = "abba";
    cout<<lps(s, 0, 4);
    return 0;
}