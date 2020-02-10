#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

void sortString(string& s) {
    map<char, int> char_count;
    string sortedString = "";
    for(char c : s)
        char_count[c]++;
    for(auto itr = char_count.begin(); itr!=char_count.end(); itr++){
        for(int i = 0; i<itr->second; i++)
            sortedString+=itr->first;
    }
    s = sortedString;
}

int main() {
    string s1new = "helloworld";
    sortString(s1new);
    // cout<<s1new<<" initial"<<endl;
    int t;
    cin>>t;
    while(t--){
        string s2;
        cin>>s2;
        string s2new = "";
        for(int i = 0; i < s2.length(); i++)
            if(isalpha(s2[i]))
                s2new+=tolower(s2[i]);
        if(s1new.length() == s2new.length()){
            sortString(s2new);
            // cout<<s2new<<" compare "<<endl;
            if(s1new == s2new)
                cout<<"Yes"<<endl;
            else 
                cout<<"No"<<endl;
        }
        else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}