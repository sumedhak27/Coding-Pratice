#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int awesome_bin_search(vector<int> arr, int k, int os){

    int index = 0,exp = 0, offset = os;
    while(true) {
        cout<<index+offset<<endl;
        try {
            if(arr.at(index+offset) == k) return index+offset; 
            else if(arr.at(index+offset) < k) index = pow(2,exp);
            else throw index;
        }
        catch(...) {
            exp = log2(index+offset) - 1;
            offset = pow(2, exp) + 1;
            return awesome_bin_search(arr, k, offset);
        }
        exp++;
    }
}

int main() {    

    vector<int> arr{1,2,3,4,5,6,7,8,9,10,12,43,58,90};
    // cout<<arr.at(8)<<endl;
    cout<<awesome_bin_search(arr, 90, 0)<<endl;
    return 0;
}