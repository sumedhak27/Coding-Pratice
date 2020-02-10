#include<iostream>
#include<cstring>

using namespace std;

void str_permutations(string s, int sp, int ep) {
    for(int i = sp; i<ep; i++){
        swap(s[sp], s[i]);
        str_permutations(s, sp+1, ep);
    }
    if(sp == ep)
        cout<<s<<endl;
}

int main() {

    string s = "ABCD";
    str_permutations(s, 0, s.length());
    return 0;
}