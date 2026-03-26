/*
BOJ 2667 단지번호 붙이기
Used Algorithms:
Time Complexity: O()

핵심 아이디어
- 

실수
- if(board[i][j] == 1 && vis[i][j] == 0){//&& vis[i][j] == 0이거 빼먹어서 틀림.

-그 외에도 각 배열에서 각 값이 가진 의미를 잘못 입력하는 실수가 있었다. 아래처럼 잘 확인하기

int board[25][25];//0 unvisited, 1 vsiited
int vis[25][25];//0 unvisited, 1 vsiited

-문자열로 받을 때에는(스트링) 맨 끝에 '\0'이 자동으로 채워지므로 n의 범위 25에 딱맞게 설정해버리면, '\0'을 넣느라 런타임 에러가날 수 있다.
따라서 평소에 배열같은 걸 선언할 때는 몇개 더 여유있게 선언하는게 좋다.

다른 관점
-
*/

#include <bits/stdc++.h>
using namespace std;

char board[30][30];//0 unvisited, 1 vsiited
int vis[30][30];//0 unvisited, 1 vsiited

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> V; //각 단지의 단지 수를 저장
    queue<pair<int, int>> Q;
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) fill(vis[i], vis[i] + n, 0); //vis 0 초기화, 또 i를 0으로 써버렸네...

    for(int i = 0; i < n; i++){//board input
        cin >> board[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == '1' && vis[i][j] == 0){//&& vis[i][j] == 0이거 빼먹어서 틀림.
                vis[i][j] = 1;
                Q.push({i, j});
                int area = 0;

                while(!Q.empty()){
                    auto [x, y] = Q.front();
                    Q.pop();
                    area++;

                    for(int dir = 0; dir < 4; dir++){
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if(board[nx][ny] == '0' || vis[nx][ny] == 1) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
                V.push_back(area);
            }
        }
    }
    cout << V.size() << '\n';
    //벡터 정렬
    sort(V.begin(), V.end());
    for(int i : V) cout << i << '\n';

    return 0;
}