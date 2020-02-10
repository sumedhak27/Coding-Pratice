#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;


int main() {
	int t;
	cin>>t;
    unordered_set<int> us;
    long long maxi = 0;
	while(t--) {
        int type, num;
        cin>>type>>num;
        switch(type) {
            case 1 :
                us.insert(num);
                if(num > maxi) maxi = num;
                break;
            case 2 : 
                if(us.find(num)!=us.end()) cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
                break;
            case 3 : 
                if(maxi <= num) {
                    cout<<-1<<endl;
                }
                else {
                    for(int i = num+1; i<=maxi; i++){
                        if(us.find(i)!=us.end()) {
                            cout<<i<<endl; 
                            break;
                        } 
                    }
                }
                break;
        }
    }
	return 0;
}