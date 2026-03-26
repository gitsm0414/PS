#include<bits/stdc++.h>
#include<random>
using namespace std;

//huge #define mistake: if you include ';', it'll be part of the macro
//never "#define X first;" unless you intend to do that
//never forget it's just a simple text replacement
#define X first
#define Y second
#define MAX 10
#define NWALL 30

int board[MAX][MAX] = {0}; //-1은 못 가는 곳, 이 외는 0이라 가정하자
int vis[MAX][MAX] = {0}; //if visited: 1, if not: 0
const pair<int, int> neigh[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; //directions


int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, MAX-1);

    //setting walls
    for(int i = 0; i < NWALL; i++){
        int x, y;
        x = dis(gen);
        y = dis(gen);
        board[x][y] = -1;
    }

    //starting position
    pair<int, int> P = {0, 0}; 
    queue<pair<int, int>> Q; 
    Q.push(P);
    vis[0][0] = 1;
    board[0][0] = 0;

    //BFS
    while(!Q.empty()){
        //pop first one
        P = Q.front();
        Q.pop();

        //search all neighbors and find valid ones
        for(auto n : neigh){
            pair<int, int> tmp;
            tmp.X = P.X + n.X;
            tmp.Y = P.Y + n.Y;

            //if it's valid and unvisited then push it to the Q
            if(tmp.X >= 0 && tmp.Y >= 0 && tmp.X < MAX && tmp.Y < MAX){
                if(board[tmp.X][tmp.Y] == 0 && vis[tmp.X][tmp.Y] == 0){
                    vis[tmp.X][tmp.Y] = 1; //mark 'visited'
                    Q.push(tmp);
                    /*
                     you can do extra things here
                    */
                }
            }
        }
    }

    //print board
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(board[i][j] == -1) cout << board[i][j] << '\t';
            else cout << " \t";
        }
        cout << "\n\n";
    }
    for(int i = 0; i < MAX; i++){
        cout << "________";
    }
    cout << "\n\n";

    //print vis[][] it should be all '1's except for walls
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(vis[i][j]) cout << vis[i][j] << '\t';
            else cout << " \t";
        }
        cout << "\n\n";
    }

    return 0;
}