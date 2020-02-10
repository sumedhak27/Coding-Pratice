#include<iostream>
#include <string>
#include <stack>

using namespace std;

bool sub_str(char* s, char* q) {
    string sn = s;
    string qn = q;
    bool flag = 0;
    for(int i =0; i<sn.length() - qn.length(); i++){
        if(qn == sn.substr(i, qn.length())){
            cout<<qn<<" found at index "<<i<<endl;
            flag = 1;
        }
    }
    if(!flag) cout<<"Substring not found"<<endl;

    return true;
}

void rev_words(string s, int start){
    int end = start;
    while(s[end] != ' ' || s[end] != '\0') end++;
    if(s[end] == '\0') {cout<<s.substr(start, end-start)<<" "; return;}
    rev_words(s,end+1);
    cout<<s.substr(start, end-start)<<" ";
}   

void rev_words_n(string s){
    stack<string> myst;
    int start = 0;
    for(int i = 0 ; i<=s.length(); i++){
        if(s[i] == ' ' || s[i] == '\0') {
            myst.push(s.substr(start, i-start));
            // cout<<s.substr(start, i-start)<<"test"<<endl;
            start = i+1;
        } 
    }
    while(!myst.empty()){
        cout<<myst.top()<<" ";
        myst.pop();
    }
    cout<<endl;
}

int main() {

    char s[] = "abcdefg";
    char q[] = "cde";
    string mystring  = "hey Shriya, How you doing!!";
    for(auto it = mystring.begin(); it != mystring.end(); it++)
        cout<<*it;
        cout<<endl;
    rev_words_n(mystring);
    // sub_str(s,q);
    return 0;
}