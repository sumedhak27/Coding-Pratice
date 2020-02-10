#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i =1; i<=n;){
        if(i & 1) {
            for(int j = 1; j<=n; j++) cout<<i;
            cout<<++i<<endl;
        }
        else {
            cout<<++i;
            i--;
            for(int j = 1; j<=n; j++) cout<<i;
            i++;
            cout<<endl;
        }
    }
    return 0;
}