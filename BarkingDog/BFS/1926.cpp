/*
BOJ 1926

문제
어떤 큰 도화지에 그림이 그려져 있을 때, 그 그림의 개수와, 그 그림 중 넓이가 가장 넓은 것의 넓이를 출력하여라. 
단, 그림이라는 것은 1로 연결된 것을 한 그림이라고 정의하자. 가로나 세로로 연결된 것은 연결이 된 것이고 대각선으로 연결이 된 것은 떨어진 그림이다. 
그림의 넓이란 그림에 포함된 1의 개수이다.

입력
첫째 줄에 도화지의 세로 크기 n(1 ≤ n ≤ 500)과 가로 크기 m(1 ≤ m ≤ 500)이 차례로 주어진다. 두 번째 줄부터 n+1 줄 까지 그림의 정보가 주어진다. 
(단 그림의 정보는 0과 1이 공백을 두고 주어지며, 0은 색칠이 안된 부분, 1은 색칠이 된 부분을 의미한다)

출력
첫째 줄에는 그림의 개수, 둘째 줄에는 그 중 가장 넓은 그림의 넓이를 출력하여라. 단, 그림이 하나도 없는 경우에는 가장 넓은 그림의 넓이는 0이다.

Used Algorithms: BFS
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

int board[500][500] = {0};
int vis[500][500] = {0};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j]; //0 or 1
        }
    }

    int paintings = 0;
    int max_area = 0;
    queue<pair<int, int>> Q;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            //if it has been painted and not been visited
            if(board[i][j] == 1 && vis[i][j] != 1){
                paintings++;
                int cur_area = 0;

                vis[i][j] = 1;
                Q.push({i, j});
                //do BFS
                while(!Q.empty()){
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    cur_area++;

                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if(board[nx][ny] == 0 || vis[nx][ny] == 1) continue;
                        
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                        
                    }
                }
                //renew maximum area
                if(cur_area > max_area) max_area = cur_area;
            }
        }
    }
    
    cout << paintings << '\n' << max_area;

    return 0;
}