#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        string result = "";
        // cout<<int('a')<<endl;
        for(char c : s) {
            char te = (c + s.length()%26) > 122 ? (c + s.length()%26)-26 : (c + s.length()%26);
            result+=te ;
        }
        cout<<result<<endl;
    }
    return 0;
}