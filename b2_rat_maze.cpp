#include<iostream>

using namespace std;

const int n = 3;

bool guide(int maze[][n], int x, int y) {
    if( x == n-1 && y == n-1) return true;
    if (x > n-1 || y > n-1 || maze[x][y] == 0 || x<0 || y < 0) return false;
    maze[x][y] = 0;
    if(guide(maze, x+1, y)) return true;
    if(guide(maze, x-1, y)) return true;
    if(guide(maze, x, y+1)) return true;
    if(guide(maze, x, y-1)) return true;
    return false;
}

void take_me_out(int maze[][n]) {
    if(guide(maze, 0, 0)) cout<<"Yes Possible"<<endl;
    else cout<<"Impossible"<<endl;    
}

int main() {

    int maze[n][n] = {{1,1,1},
                      {0,1,0},
                      {0,1,1}};
    take_me_out(maze);
    return 0;
}