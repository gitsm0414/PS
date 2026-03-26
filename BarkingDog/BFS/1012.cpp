/*
BOJ 1012
Used Algorithms: BFS
Time Complexity: O()

핵심 아이디어
- 

실수
- BFS구현 과정 중 잔실수가 많았으니 코드 참고

다른 관점
-
*/

#include <bits/stdc++.h>
using namespace std;

int vis[50][50]; // -1: unvisited, 0: wall, 1: visited
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t_case;
    cin >> t_case;

    while(t_case--){
        int cnt = 0;
        int n, m, k;

        cin >> m >> n >> k;
        
        for(int i = 0; i < n; i++) fill(vis[i], vis[i] + m, 0); //vis 0 초기화

        for(int i = 0; i < k; i++){//unvisited 양배추 -1 표시
            int x, y;
            cin >> x >> y;
            vis[y][x] = -1;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                if(vis[i][j] == -1){
                    //BFS
                    queue<pair<int, int>> Q;
                    vis[i][j] = 1; //방문 표시 잘해줍시다. 0으로 했다가 틀림
                    Q.push({i, j}); //Q에 시동 안걸어줬다. 이거 빼먹어서 틀림

                    while(!Q.empty()){
                        pair<int, int> cur = Q.front();
                        Q.pop();

                        for(int dir = 0; dir < 4; dir++){
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];
                            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                            if(vis[nx][ny] != -1) continue;

                            Q.push({nx, ny});
                            vis[nx][ny] = 1; //방문 표시 잘해줍시다. 0으로 했다가 틀림

                        }
                    }
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }
    

    return 0;
}