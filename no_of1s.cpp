#include <iostream>

using namespace std;

int main(){

    int num = 2047, count = 0;
    int temp = num;
    while(temp>0){
        // cout<<temp<<" ";
        count += temp & 1; 
        temp>>=1;
    }
    cout<<count<<endl;
    return 0;
}