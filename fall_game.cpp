#include <iostream>
#include <numeric>
using namespace std;

int main() {
    int x, y;
    cin>>x>>y;
    int row_max[x] = {0};
    for(int i = 0 ; i< x; i++) {
        string s;
        cin>>s;
        for(int j = 0; j < y; j++){
            if(row_max[i]< (int(s[j]) - 48)) row_max[i] = (int(s[j]) - 48);
        }
    }
    for(int i: row_max)
        cout<<i<<" ";
    cout<<endl;
    int sum = 0;
    sum = accumulate(row_max, row_max+x, sum);
    cout<<sum<<endl;
    return 0;
}