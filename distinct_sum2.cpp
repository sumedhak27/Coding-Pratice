#include <iostream>
using namespace std;

int main() {
    long long int n,x,y;
    cin>>n>>x>>y;
    if(x>y) cout<<0<<endl;
    else cout<<((n-2)*y - (n-2)*x)+1<<endl;
    return 0;
}