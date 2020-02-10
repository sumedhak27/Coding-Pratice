#include <iostream>
#include <cmath>

using namespace std;
 
int main() {

    int t;
    cin>>t;
    while(t--) {
        int l,r;
        cin>>l>>r;
        int upper = max(l,r);
        int lower = min(l,r);
        cout<<((upper-lower+1) - (floor(sqrt(upper)) - ceil(sqrt(lower)) + 1))<<endl;
    }

    return 0;
}