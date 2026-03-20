/*
BOJ 7576

Used Algorithms:
Time Complexity: O(N*M) 시간, 공간

핵심 아이디어
- 동시에 확산하는(출발하는)걸 카운트하는 BFS

실수
- 

다른 관점
-"근데 굳이 max_days가지고 비교할 필요 없이. Q.front() 이후에 max_days = cur위치의 days값 이렇게 해도 의도대로 동작하겠네? 
왜냐면 Q에서 가장 마지막에 빠질 원소가 가장 큰 값이니까?"

>> "오, 정확한 통찰입니다! BFS의 핵심 성질을 완벽하게 이해하고 계시네요. 
굳이 if문으로 비교(Comparison)하지 않고 그냥 덮어쓰기(Assignment)만 해도 결과는 똑같습니다."
*/

#include <bits/stdc++.h>
using namespace std;

int box[1000][1000];//-1(wall), 0(안익은), 1(익은)
int days[1000][1000];//-1 방문안된곳, 0은 익은 과일의 위치, 나머지 부분에 그 위치가 익기까지 최소일수를 채워넣을 것임
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int yet = 0; //아직 안 익은 놈 개수
    int max_days = 0; //days[][]안의 공간이 다 채워지고 나면 그 중 최댓값이 바로 다 퍼지기까지 걸리는 최소 일 수이다.
    int n, m;
    cin >> m >> n;
    queue<pair<int,int>> Q;

    //days[][] -1초기화
    for(int i = 0; i < n; i++){
        fill(days[i], days[i] + m, -1);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> box[i][j];
            if(box[i][j] == 0){
                yet++;
            }else if(box[i][j] == 1){
                days[i][j] = 0; //진원지
                Q.push({i, j});
            }
        }
    }

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        if(max_days < days[cur.first][cur.second])  max_days = days[cur.first][cur.second]; //updating max_days
        //max_days업데이트를 yet과 달리 Q.pop될 때 수행하는 이유: 예를들어 박스안에 벽아니면 이미 익은 과일만 초기상태에 있다 가정해보자.
        //이 경우 yet이 있는 for문 안에 넣는 다는 것은 while문 이후부터 추가된 애들만 고려한다는 뜻이다.
        //근데 추가될 애가 없으므로 초기값인 -1이 결과값이 되어버린다(지금은 초기값 0으로 수정함). 이때는 초기 애들까지 다 포함해서 고려하면 
        //max_days는 위와 같은 예외사항에도 충족한다.
        //근데 사실 max_days를 애초에 0으로 초기화했다면 어차피 yet이 -1인 경우를 담당하고 있으니 사실 그렇게하면 어찌되든 문제없긴하다.

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(box[nx][ny] == -1 || days[nx][ny] > -1) continue;

            days[nx][ny] = days[cur.first][cur.second] + 1;
            Q.push({nx, ny});
            yet--; //Q.pop()의 횟수 중에는 처음부터 익어있던 초기 애들의 pop도 포함하므로, 새로 추가된 애들만 유효하게 카운트한다.
        }
    }
    //안익은 과일이 있을 경우
    if(yet) cout << -1;
    else cout << max_days;

    return 0;
}