#include<iostream>

using namespace std;

const int n = 3;

bool guide(int maze[][n], int** output, int x, int y) {
    cout<<x<<" "<<y<<endl;
    if( x == n-1 && y == n-1){
        output[x][y] = 1;
        return true;
    }
    if (x > n-1 || y > n-1 || maze[x][y] == 0 || x<0 || y < 0 || output[x][y] == 1 ) return false;
    output[x][y] = 1;
    if(guide(maze, output, x+1, y)) return true;
    if(guide(maze, output, x-1, y)) return true;
    if(guide(maze, output, x, y+1)) return true;
    if(guide(maze, output, x, y-1)) return true;
    return false;
}

void take_me_out(int maze[][n]) {
    int** output = new int* [n];
    for(int i = 0; i < n; i++) {
        output[i] = new int [n];
        for(int j = 0 ; j < n; j++)
            output[i][j] = 0;
    }
    if(guide(maze, output, 0, 0)) cout<<"Yes Possible"<<endl;
    else cout<<"Impossible"<<endl;
    
}

int main() {

    int maze[n][n] = {{1,0,0},
                      {1,1,0},
                      {1,0,0}};
    take_me_out(maze);
    return 0;
}