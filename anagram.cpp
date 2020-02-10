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

    string s1 = "Eleven plus two.";
    string s2 = "Twelve plus one.";
    string s1new = "", s2new = "";
    for(int i = 0; i < s1.length(); i++)
        if(isalpha(s1[i]))
            s1new+=tolower(s1[i]);
    for(int i = 0; i < s2.length(); i++)
        if(isalpha(s2[i]))
            s2new+=tolower(s2[i]);
    if(s1new.length() == s2new.length()){
        // sort(s1new.begin(), s1new.end());
        // sort(s2new.begin(), s2new.end());
        sortString(s1new);
        sortString(s2new);
        cout<<s1new<<endl<<s2new<<endl;
        if(s1new == s2new)
            cout<<"It is an Anagram."<<endl;
    }
    else
        cout<<"It is not a Anagram."<<endl;
    return 0;
}