#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_set<int> s;
    s.insert(5);
    s.insert(8);
    s.insert(11);
    for(auto si = s.begin(); si!=s.end(); si++)
        cout<<*si<<" ";
    cout<<endl;
    try{
        s.insert(8);
        auto i = s.equal_range(8);
        if(i.first!=s.end() && i.second != s.end())
            cout<<*i.first<<*i.second<<endl;
        else if(i.first!=s.end())
            cout<<"lower bound"<<*(i.first)<<endl;
        else if(i.second != s.end())
            cout<<"upper bound"<<*i.second<<endl;
        else 
            cout<<"-1"<<endl;
    }
    catch(...){
        cout<<"error";
    }
    
    // unordered_map<int, int> s;
    // s.insert({3,0});
    // s.insert({8,0});
    // s.insert({11,0});
    // for(auto si = s.begin(); si!=s.end(); si++)
    //     cout<<si->first<<" ";
    // cout<<endl;

}