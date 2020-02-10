#include <iostream>

using namespace std;

const int n = 3;

bool take_me_out(int maze[][n], int sr, int sc, int er, int ec) {
    // cout<<"I am here "<<maze[sr][sc]<<endl;
    cout<<"Row : "<<sr<<"  Column : "<<sc<<endl;
    // cout<<maze[sr+1][sc]<<"\t"<<maze[sr-1][sc]<<"\t"<<maze[sr][sc+1]<<"\t"<<maze[sr][sc-1]<<"\t"<<endl;
    if(maze[sr][sc] == 0) { cout<<"s0"<<endl; return false; }
    maze[sr][sc] = 0;
    // cout<<"I am here2 "<<maze[sr][sc]<<endl;
    if (sr == er && sc == ec) {cout<<"s1"<<endl; return true;}
    bool b1 = false,b2 = false,b3 = false,b4 = false;
    if (sr+1 < n) {
        if (maze[sr+1][sc] == 1){
            cout<<"sif1"<<endl; 
            b1 = take_me_out(maze, sr+1, sc, er, ec);
        }
    }
    if (sr-1 >= 0) {
        if (maze[sr-1][sc] == 1) {
            cout<<"sif2"<<endl; 
            b2 = take_me_out(maze, sr-1, sc, er, ec);
        }
    } 
    if (sc+1 < n) {
        if (maze[sr][sc+1] == 1) {
            cout<<"sif3"<<endl; 
            b3 = take_me_out(maze, sr, sc+1, er, ec);
        }
    }
    if (sc-1 >= 0) {
        if (maze[sr][sc-1] == 1) {
            cout<<"sif4"<<endl; 
            b4 = take_me_out(maze, sr, sc-1, er, ec);            
        }
    }
    return (b1 || b2 || b3 || b4);
}

int main() {
    int maze[n][n] = {{1, 0, 0},
                      {1, 1, 1},
                      {1, 1, 1}};
    bool ans = take_me_out(maze, 0, 0, 2, 2);
    if(ans == true) cout<<"I am out of this fu**g maze!! Yeeee.."<<endl;
    else cout<<"Shit..This is impossible."<<endl;
    return 0;
}