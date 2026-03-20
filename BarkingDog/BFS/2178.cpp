/*
BOJ 2178
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

char board[100][100] = {};//'0'(wall) or '1'(path)
int dist[100][100] = {}; //distance from start, dist[0][0] is 1
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    scanf("%d %d\n", &n, &m); //scanf("%d %d\n", n, m)때문에 에러남...
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%c", &board[i][j]);
        }
        getchar(); //이는 scanf('\n');이렇게도 쓸 수 있다.
    }

    queue<pair<int, int>> Q;
    dist[0][0] = 1;
    Q.push({0, 0});

    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();

        if(cur.first==n-1 && cur.second==m-1){//n, m 거꾸로써서 틀림
            cout << dist[cur.first][cur.second];
            break;
        }

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(board[nx][ny] == '0' || dist[nx][ny] > 0) continue;

            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({nx, ny});
        }
    }


    return 0;
}