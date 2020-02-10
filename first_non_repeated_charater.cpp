#include <iostream>
#include <map>

using namespace std;

int main() {

    string s = "The quick brown fox jumps over the lazy dog";
    map<char, int> char_count;
    for(char c : s)
        char_count[c]++;
    for(char c : s)
        if(char_count[c]==1){
            cout<<"first distinct character in string is '"<<c<<"'."<<endl;
            break;
        }
    for(auto itr = char_count.begin(); itr!= char_count.end(); itr++)
        cout<<itr->first<<"\t"<<itr->second<<endl;
    return 0;
}