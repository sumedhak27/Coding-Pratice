#include <iostream>
typedef unsigned long long int ll;
using namespace std;

ll xoring(ll n) {
    if(n < 0)
    return 0;
	switch(n & 3) {
		case 0 : return n; 
		case 1 : return 1;
		case 2 : return n+1;
		case 3 : return 0;
	}
}

int main() {
    ll r;
    cin>>r;
    cout<<xoring(r);
    return 0;
}