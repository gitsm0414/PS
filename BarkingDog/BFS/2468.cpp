/*
BOJ 2468 안전영역
Used Algorithms:
Time Complexity: O()

핵심 아이디어
- 

실수
- //vis 0 초기화 (처음엔 빼먹어서 틀림)
- int max_sec = 1; //max sectors 1높이만 쭉 있는경우 max_sec은 0이 아니라 1이 되야하므로 초기값을 설정할때는 이렇듯 특이케이스를 염두에 두고 정하자.

다른 관점
-
*/

#include <bits/stdc++.h>
using namespace std;

int board[105][105]; //높이는 1~100포함 자연수
int vis[105][105] = {0}; //visit -> 1

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<pair<int, int>> Q;
    int n;
    cin >> n;
    int max_h = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
            if(max_h < board[i][j]) max_h = board[i][j];
        }
    }

    int max_sec = 1; //max sectors
    for(int height = 1; height < max_h; height++){//최대 높이까지 잠기기 직전까지만 체크
        int sec = 0;

        //vis 0 초기화 (처음엔 빼먹어서 틀림)
        for(int i = 0; i < n; i++) fill(vis[i], vis[i] + n, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] > height && vis[i][j] == 0){
                    //BFS
                    Q.push({i, j});
                    vis[i][j] = 1;
                    
                    while(!Q.empty()){
                        auto [x, y] = Q.front();
                        Q.pop();
                        for(int i = 0; i < 4; i++){
                            int nx = x + dx[i];
                            int ny = y + dy[i];
                            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                            if(board[nx][ny] <= height || vis[nx][ny] == 1) continue;
                            
                            Q.push({nx, ny});
                            vis[nx][ny] = 1;
                        }
                    }
                    sec++;
                }
            }
        }
        if(max_sec < sec) max_sec = sec;
    }
    cout << max_sec;

    return 0;
}