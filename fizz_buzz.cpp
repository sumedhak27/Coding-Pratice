#include<iostream>

using namespace std;

void fizz_buzz(int n){
    for(int i = 1 ; i<=n; i++){
        if(i%3 == 0 && i%5 == 0) cout<<"FizzBuzz";
        else if(i%3 == 0) cout<<"Fizz";
        else if(i%5 == 0) cout<<"Buzz";
        else cout<<i;
        cout<<endl;
    }
}

int main() {
    int n = 20;
    fizz_buzz(n);
    return 0;
}