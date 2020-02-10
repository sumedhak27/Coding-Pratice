#include <iostream>
#include <set>
#include <map>
#include <cmath>
using namespace std;

bool isPrime(int n) { 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 

    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int trees[n] = {0};
        map<int,set<int> > tno;
        for(int i = 0; i<n; i++){
            cin>>trees[i];
            if(isPrime(trees[i])) tno[0].insert(i+1);
            else{
                int c_num = trees[i];
                int next_prime = 0; 
                for(int j = ceil(c_num/6.0)*6; ;j+=6) {
                    // cout<<"test"<<j<<endl;
                    if(j!=c_num) {
                        if(isPrime(j-1)) {
                            next_prime = j-1;
                            break;
                        }
                    }
                    if(isPrime(j+1)) {
                        next_prime = j+1;
                        break;
                    }
                }
                // cout<<"test-->"<<next_prime<<endl;
                tno[next_prime - c_num].insert(i+1);
            } 
        }
        for(auto itr = tno.begin(); itr!=tno.end(); itr++){
            // cout<<itr->first<<endl;
            for(auto it = itr->second.begin(); it!= itr->second.end(); it++){
                cout<<*it<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}