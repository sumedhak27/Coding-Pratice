#include <iostream>

using namespace std;

void tower_of_honoi(int n, char from, char aux, char to) {
    if(n == 1) cout<<from<<" -> "<<to<<endl;
    else {
        tower_of_honoi(n-1, from, to, aux);
        cout<<from<<" -> "<<to<<endl;
        tower_of_honoi(n-1, aux, from, to);
    }
    

}

int main() {
    int n = 3;
    tower_of_honoi(n, 'A', 'B', 'C');
    return 0;
}