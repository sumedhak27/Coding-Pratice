#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int t;
	cin>>t;
    set<int> s;
	while(t--) {
        int type, num;
        cin>>type>>num;
        switch(type) {
            case 1 :
                s.insert(num);
                break;
            case 2 : 
                if(s.find(num)!=s.end()) cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
                break;
            case 3 : 
                auto ub = s.upper_bound(num);
                if(ub!=s.end()) cout<<*ub<<endl;
                else cout<<-1<<endl;
                break;
        }
    }
	return 0;
}