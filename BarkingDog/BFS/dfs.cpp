#include <bits/stdc++.h>
using namespace std;
#include<random>

#define X first
#define Y second
#define MAX 10
#define NWALL 30

int board[MAX][MAX] = {0}; //-1은 못 가는 곳, 이 외는 0이라 가정하자
int vis[MAX][MAX] = {0}; //if visited: 1, if not: 0

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void print_();

int main(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, MAX-1);

    //setting walls
    for(int i = 0; i < NWALL; i++){
        int x = dis(gen);
        int y = dis(gen);
        board[x][y] = -1;
    }
    board[0][0] = 0;

    //setting before DFS
    stack<pair<int, int>> S;
    S.push({0, 0});
    vis[0][0] = 1;

    //DFS
    while(!S.empty()){
        pair<int, int> cur = S.top();
        S.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= MAX || ny >= MAX) continue; //out of boundary
            if(board[nx][ny] == -1 || vis[nx][ny] == 1) continue; //when it's wall or it was visited before..

            S.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }

    print_();
    return 0;
}

void print_(){
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
}