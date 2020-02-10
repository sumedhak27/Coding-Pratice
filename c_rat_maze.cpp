#include <iostream>

using namespace std;

const int n = 3;

void printOutput(int** output) {
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++)
            cout<<output[i][j]<<"\t";
        cout<<endl;
    }
    cout<<endl;
}

void guide(int maze[][n], int** output, int x, int y) {
    if( x == n-1 && y == n-1){
        output[x][y] = 1;
        printOutput(output);
        return;
    }
    if(x>n-1 || y>n-1 || x<0 || y<0 || output[x][y] == 1 || maze[x][y] == 0) return;
    output[x][y] = 1;
    guide(maze, output, x+1, y);
    guide(maze, output, x-1, y);
    guide(maze, output, x, y+1);
    guide(maze, output, x, y-1);
    output[x][y] = 0;
}

void take_me_out(int maze[][n]) {
    int** output = new int*[n];
    for(int i = 0; i<n; i++) {
        output[i] = new int[n];
        for(int j = 0; j<n; j++)
                output[i][j] = 0;
    }
    guide(maze, output, 0, 0);
}

int main() {
    int maze[n][n] = {{1,0,0},{1,1,0},{1,1,0}};
    take_me_out(maze);
    return 0;
}