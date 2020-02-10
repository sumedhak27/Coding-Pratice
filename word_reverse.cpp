#include<iostream>
#include<cstring>

using namespace std;

int main() {

    string s = "I am the boss!!";
    for(int i = 0, j = s.length()-1; i<j; i++, j--) {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    int i = 0, j = 0;
    cout<<j<<"  "<<s<<endl;
    while (s[i])
    {
        while(s[j] != ' ') j++;
        int lenght = j;
        cout<<lenght<<endl;
        j-=1;
        while(i<j) {
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
            i++;j--;
        }
        i = lenght+1;
        j = lenght+1;
    }
    cout<<s<<endl;
    

   
    return 0;
}