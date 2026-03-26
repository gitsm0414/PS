/*
BOJ 7569
Used Algorithms:
Time Complexity: O()

핵심 아이디어
- 

실수
-3차원 배열에 원소값을 받을 때 for문의 i,j,k 순서를 예시와 잘 비교해야한다.

다른 관점
-
*/

#include <bits/stdc++.h>
using namespace std;

int board[101][101][101];
int days[101][101][101]; //-1is unvisited, 익은 토마토 초기값은 0, 이후 하루씩 증가

int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    queue<tuple<int, int, int>> Q;
    int total = 0;//총 토마토의 개수
    int day = 0;//모두 익을때 까지 걸리는 날짜
    int n, m, h;
    cin >> m >> n >> h;
    fill(days[0][0], days[0][0] + 101*101*101, -1); //vis -1으로 초기화

    for(int i = 0; i < h; i++){ //board[z][y][x]
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                cin >> board[i][j][k];

                if(board[i][j][k] == 0) total++;
                else if(board[i][j][k] == 1){
                    days[i][j][k] = 0;
                    Q.push({i, j, k});
                    total++;
                }
            }
        }
    }


    while(!Q.empty()){
        auto [z, y, x] = Q.front(); //순서주의
        Q.pop();
        total--;

        for(int dir = 0; dir < 6; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];
            if(nx < 0 || ny < 0 || nz < 0 || nx >= m || ny >= n || nz >= h) continue;
            if(board[nz][ny][nx] == -1 || days[nz][ny][nx] > -1) continue;
            
            Q.push({nz, ny, nx});
            days[nz][ny][nx] = days[z][y][x] + 1;
            day = days[nz][ny][nx];
        }
    }
    if(total == 0) cout << day;
    else cout << -1;

    return 0;
}