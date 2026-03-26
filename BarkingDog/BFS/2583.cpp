/*
BOJ 2583 영역 구하기
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

int board[101][101]; //-1 is wall, 0 is unvisited, 1 is visited
int arr[5001];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int end_idx = 0; //arr에 원소가 추가될 인덱스값
    queue<pair<int, int>> Q;
    int m, n, k;
    cin >> m >> n >> k;

    for(int i = 0; i < m; i++){//board 0 초기화
        for(int j = 0; j < n; j++){
            board[i][j] = 0;
        }
    }
    for(int i = 0; i < k; i++){//직사각형 부분 -1로 색칠
        int l_x, l_y, r_x, r_y;
        cin >> l_x >> l_y >> r_x >> r_y;

        for(int i = l_y; i < r_y; i++){ //i가 y좌표, j가 x좌표를 담당한다.
            for(int j = l_x; j < r_x; j++){
                board[i][j] = -1;
            }
        }
    }
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 0){
                Q.push({i, j});
                board[i][j] = 1;
                int area = 0;

                while(!Q.empty()){
                    auto [y, x] = Q.front();
                    Q.pop();
                    area++;

                    for(int dir = 0; dir < 4; dir++){
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if(board[ny][nx] != 0) continue;

                        board[ny][nx] = 1;
                        Q.push({ny, nx});
                    }

                }
                arr[end_idx++] = area;
            }
        }
    }
    //arr 정렬
    for(int i = 0; i < end_idx-1; i++){
        int min_idx = i;
        for(int j = i+1; j < end_idx; j++){
            if(arr[j] < arr[min_idx]) min_idx = j; 
        }
        //swap
        int tmp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = tmp;
    }


    cout << end_idx << '\n';
    //오름차순 넓이 출력
    for(int i = 0; i < end_idx; i++){
        cout << arr[i] << ' ';
    }
    return 0;
}