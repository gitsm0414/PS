#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[502][502] = {};
bool vis[502][502] = {};
int n = 7; //행
int m = 10; //열

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> Q;
    vis[0][0] = 1;
    Q.push({0,0});

    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();
        //print current position
        cout << '(' << cur.X << ", " << cur.Y << ") ->";

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(vis[nx][ny] || board[nx][ny] != 0) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }

    return 0;
}