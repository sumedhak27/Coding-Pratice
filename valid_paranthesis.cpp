#include <iostream>
#include <stack>

using namespace std;

void is_string_valid(string s) {
    stack<char> parastack;
    int count;
    for(char c : s){
        count++;
        if(c == '{' || c == '(' || c == '[')
            parastack.push(c);
        else if( c == '}' && parastack.top() == '{')
            parastack.pop();
        else if( c == ')' && parastack.top() == '(')
            parastack.pop();
        else if( c == ']' && parastack.top() == '[')
            parastack.pop();
        else count--;
    }
    if( parastack.empty() || count == s.length())
        cout<<"Valid paranthesis string."<<endl;
    else
        cout<<"Invalid paranthesis string."<<endl;
    for(stack<char> temp = parastack; !temp.empty(); temp.pop())
        cout<<temp.top()<<" ";
    cout<<endl;
}

int main() {

    string s = "{([])}}";
    is_string_valid(s);
    return 0;
}