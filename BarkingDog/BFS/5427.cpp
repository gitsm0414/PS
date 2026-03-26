/*
BOJ 5427
Used Algorithms:
Time Complexity: O()

핵심 아이디어
- 

실수
- =, ==를 혼동해 쓰는 실수, 구분되있는 큐를 잘못 쓴경우 등 실수가 있었다.
-if(fire[ny][nx] != -1 && (fire[ny][nx] <= vis[y][x] + 1)) continue; >>이 부분이 핵심이었다. 조건을 if문 2개가 아니라 3개로 하는 것
-그리고 fire[ny][nx] == -1 인경우 (fire[ny][nx] <= vis[y][x] + 1)가 참이되버리기 때문에 이 누수를 막기위해 앞의 조건과 &&한것이 중요하다.

다른 관점
-
*/

#include <bits/stdc++.h>
using namespace std;

char board[1001][1001];
int fire[1001][1001]; //불의 발자취
int vis[1001][1001]; //상근의 발자취

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){       
        int w, h;
        cin >> w >> h;
        queue<pair<int, int>> Qf; //fire's queue
        queue<pair<int, int>> Qm; //man's queue

        //fire, vis -1초기화
        for(int i = 0; i < h; i++) fill(fire[i], fire[i]+w, -1);
        for(int i = 0; i < h; i++) fill(vis[i], vis[i]+w, -1);

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> board[i][j];
                if(board[i][j] == '@'){//상근이
                    Qm.push({i, j});
                    vis[i][j] = 0;
                }else if(board[i][j] == '*'){//fire
                    Qf.push({i, j});
                    fire[i][j] = 0;
                }
            }
        }

        //1. fire BFS
        while(!Qf.empty()){
            auto [y, x] = Qf.front();
            Qf.pop();
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
                if(board[ny][nx] == '#' || fire[ny][nx] > -1) continue;
                fire[ny][nx] = fire[y][x] + 1;
                Qf.push({ny, nx});
            }
        }

        //2. man BFS
        bool possible = false; //탈출여부
        while(!Qm.empty()){
            auto [y, x] = Qm.front();
            Qm.pop();
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= h || nx >= w){//경계선을 넘어서면 탈출
                    cout << vis[y][x] + 1 << '\n';
                    possible = true;
                    break;
                }
                if(board[ny][nx] == '#' || vis[ny][nx] > -1) continue;
                if(fire[ny][nx] != -1 && (fire[ny][nx] <= vis[y][x] + 1)) continue; //fire -> -1일 경우를 고려해줘야함.
                vis[ny][nx] = vis[y][x] + 1;
                Qm.push({ny, nx});
            }
            if(possible) break;
        }
        if(!possible) cout << "IMPOSSIBLE\n";
    }

    return 0;
}