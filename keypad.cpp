#include <iostream>

using namespace std;
const int rows = 4, col = 3;
static int count = 0;

void cout_keypad_n(int i ,int j, int length) {
    // cout<<i<< " "<<j<<endl;
    if(i<0 || j<0 || i>=rows || j>=col || (i == rows-1 && (j == col-1 || j == 0))) return;
    if(length == 1) {count++; return;}
    cout_keypad_n(i,j,length-1);
    cout_keypad_n(i+1,j,length-1);
    cout_keypad_n(i-1,j,length-1);
    cout_keypad_n(i,j+1,length-1);
    cout_keypad_n(i,j-1,length-1);
}

// int total_keypad_n(int length) {
//     for(int i = 0; i<rows; i++)
//         for(int j = 0 ; j<col; j++)
//             cout_keypad_n(i,j,length);
// }

int total_keypad_n(int length) {
    int total_count = 0;
    for(int i =0; i<rows-1; i++){
        cout_keypad_n(i,0,length);
        total_count+=(2*count);
        count = 0;
    }
    for(int i = 0; i<rows; i++){
        cout_keypad_n(i,1,length);
    }
    total_count+=count;
    return total_count;
}

int main() {
    int length = 0;
    cout<<"Enter required length of number : ";
    cin>>length;
    int t_count = total_keypad_n(length);
    cout<<"Total number of combinations possible for length of "<<length<<" is "<<t_count;
    return 0;
}