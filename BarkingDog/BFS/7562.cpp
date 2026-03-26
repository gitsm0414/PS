/*
BOJ 7562
Used Algorithms:
Time Complexity: O()

핵심 아이디어
- 

실수
- 

다른 관점
-
*/

#include <bits/stdc++.h>
using namespace std;

int board[300][300]; //-1 unvisited, 0 start pos, n : n-th step

int dx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[8] = {1,-1,2,-2,2,-2,1,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; //test case
    cin >> t;
    while(t--){
        int l, s_x, s_y, d_x, d_y;
        cin >> l;
        cin >> s_x >> s_y;
        cin >> d_x >> d_y;
        for(int i = 0; i < l; i++) fill(board[i], board[i]+l, -1);//board 초기화, board[0]으로 적었다가 틀림

        board[s_x][s_y] = 0;
        queue<pair<int, int>> Q;
        Q.push({s_x,s_y});

        while(!Q.empty()){
            pair<int, int> cur = Q.front();
            Q.pop();
            if(cur.first == d_x && cur.second == d_y){//목적지 도달?
                cout << board[cur.first][cur.second] << '\n';
                break;
            } //시작과 목적지가 같은경우도 포함하려면 이 위치에 적어야한다.

            for(int i = 0; i < 8; i++){ //8방향 확산
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if(nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
                if(board[nx][ny] > -1) continue;

                board[nx][ny] = board[cur.first][cur.second] + 1;
                Q.push({nx, ny});
            }
        }
    }

    return 0;
}