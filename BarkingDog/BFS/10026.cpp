/*
BOJ 10026
Used Algorithms:
Time Complexity: O()

핵심 아이디어
- 

실수
- 

다른 관점
-R,G,B의 구역을 각각 구하는 과정에서 중복된 로직이 보이기 때문에 이런것들을 함수로 묶는다면 코드를 더 좋게 만들 수 있다.
>>아래 코드 참고

#include <bits/stdc++.h>
using namespace std;

int n;
char board[101][101];
bool vis[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

// 범용 BFS: 시작점의 색상과 같은 인접 구역을 모두 방문 처리
void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true;
    char color = board[i][j];

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[nx][ny] || board[nx][ny] != color) continue;
            
            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

// 현재 board 상태에서 구역의 총 개수를 반환하는 함수
int count_regions() {
    int count = 0;
    for (int i = 0; i < n; i++) fill(vis[i], vis[i] + n, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) {
                bfs(i, j);
                count++;
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> board[i];

    // 1. 일반인 기준 구역 수 출력
    cout << count_regions() << " ";

    // 2. 적록색약용 세팅: G를 R로 치환
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'G') board[i][j] = 'R';
        }
    }

    // 3. 적록색약 기준 구역 수 출력
    cout << count_regions();

    return 0;
}


-재귀함수로 푸는 방법도 있던데 아직 안배운 상태라 모르겠다.
*/

#include <bits/stdc++.h>
using namespace std;

char board[100][100];
int vis[100][100]; //unvisited 0, visited 1
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //input
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    //적록색약 아닌사람 구역 수 구하기
    int rgnot = 0;
    int b = 0; //적록색약의 구역 수 구할 때 중복계산 안하기 위해서 사용
    queue<pair<int, int>> Q;
    for(int i = 0; i < n; i++) fill(vis[i], vis[i]+n, 0); //vis 0 초기화
    //R BFS
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'R' && vis[i][j] == 0){
                Q.push({i, j});
                vis[i][j] = 1;
                while(!Q.empty()){
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if(board[nx][ny] == 'G' || board[nx][ny] == 'B' || vis[nx][ny] == 1) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
                rgnot++;
            }
        }
    }
    //G BFS
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'G' && vis[i][j] == 0){
                Q.push({i, j});
                vis[i][j] = 1;
                while(!Q.empty()){
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if(board[nx][ny] == 'R' || board[nx][ny] == 'B' || vis[nx][ny] == 1) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
                rgnot++;
            }
        }
    }
    //B BFS
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'B' && vis[i][j] == 0){
                Q.push({i, j});
                vis[i][j] = 1;
                while(!Q.empty()){
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if(board[nx][ny] == 'R' || board[nx][ny] == 'G' || vis[nx][ny] == 1) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
                rgnot++; 
                b++;
            }
        }
    }
    cout << rgnot << ' ';

    //적록색약인 사람 구역 수 구하기(b는 구했음)
    int rg = 0;
    for(int i = 0; i < n; i++) fill(vis[i], vis[i]+n, 0); //vis 0 초기화

    //R,G를 묶어서 BFS하기 -> B를 벽으로 취급
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] != 'B' && vis[i][j] == 0){
                Q.push({i, j});
                vis[i][j] = 1;
                while(!Q.empty()){
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if(board[nx][ny] == 'B' || vis[nx][ny] == 1) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }                    
                }
                rg++;
            }
        }
    }
    rg += b;
    cout << rg;

    return 0;
}