#include<iostream>
#include<cstring>
#include<stack>
#include<algorithm>

using namespace std;

int main() {
    stack<string> st;
    string s = "Interviews are awesome! ";
    string temp = "";
    for(int i = 0; i<s.length(); i++) {
        if(s[i] == ' ' || s[i] == '\n' || s[i] == '\t'){
            st.push(temp);
            temp = "";
        }
        else temp = temp + s[i];
    }
    while (!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
    
    return 0;
}