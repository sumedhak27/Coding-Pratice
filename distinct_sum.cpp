#include <iostream>
#include <unordered_set>
#include <map>
typedef long long int ll;
using namespace std;

ll n, x, y;
unordered_set<ll> mys;
map<ll , unordered_set<ll>> mym;

void myutil(int c_sum, int rem_count) {
    if(mym[c_sum].find(rem_count)!=mym[c_sum].end()) return;
    if(rem_count == 0){
        mys.insert(c_sum);
        return;
    } 
    for(int i = x; i<=y; i++) {
        myutil(c_sum+i, rem_count-1);
    }
    mym[c_sum].insert(rem_count);
}

int myf(int n, int x, int y) {
    if(x > y) return 0;
    myutil(x+y, n-2);
    return mys.size();
}

int main() {
    cin>>n>>x>>y;
    cout<<myf(n,x,y);
    return 0;
}