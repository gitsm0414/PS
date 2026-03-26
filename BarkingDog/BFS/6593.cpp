/*
BOJ 6593 상범빌딩
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

char building[32][32][32];

int vis[32][32][32]; 

int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        queue<tuple<int, int, int>> Q; //중간에 E를 찾고 BFS를 중단하면 Q안에 남아있을 수 있다. 따라서 이렇게
        //while문 안에서 Q를 계속해서 초기화시켜줘야 한다.
        int l, r, c;
        cin >> l >> r >> c;

        if(l == 0 && r == 0 && c == 0) break;

        //vis -1으로 초기화
        for(int i = 0; i < l; i++){
            for(int j = 0; j < r; j++){
                for(int k = 0; k < c; k++){
                    vis[i][j][k] = -1;
                }
            }
        }

        //building input
        for(int i = 0; i < l; i++){
            for(int j = 0; j < r; j++){
                cin >> building[i][j];
                for(int k = 0; k < c; k++){
                    if(building[i][j][k] == 'S'){
                        vis[i][j][k] = 0;
                        Q.push({i, j, k});
                    }/*
                    else if(building[i][j][k] == 'E'){//도착지점 좌표 굳이 기억할 필요 없었음
                        ez = i;
                        ey = j;
                        ex = k;
                    }
                    */
                }
            }
        }
        //BFS
        bool escape = false;
        while(!Q.empty()){
            auto [z, y, x] = Q.front();
            Q.pop();
            if(building[z][y][x] == 'E'){
                cout << "Escaped in " << vis[z][y][x] << " minute(s).\n";
                escape = true;
                break;
            }
            for(int i = 0; i < 6; i++){
                int nz = z + dz[i];
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(nz < 0 || ny < 0 || nx < 0 || nz >= l || ny >= r || nx >= c) continue;
                if(building[nz][ny][nx] == '#' || vis[nz][ny][nx] > -1) continue;
                vis[nz][ny][nx] = vis[z][y][x] + 1;
                Q.push({nz, ny, nx});
            }
        }
        if(!escape) cout << "Trapped!\n";
    }
    

    return 0;
}