/*
BOJ 4179
Used Algorithms:
Time Complexity: O()

핵심 아이디어
- BFS 이용, J와 F의 턴제 게임으로 해석, 단 F턴먼저 시작하고(사실 J먼저), F가 확산에 제약이 없는 반면 J는 확산에 제약이 크다.
- 만약 그 제약을 뚫고 끝에 닿는데 성공하면 성공, BFS즉 움직이는 영상을 단위시간 별로 끊어서 캡쳐하는 과정이 다끝났다?
- 이말은 즉 J는 이미 불에타 사라졌다는 것이다.

실수
- J가 애초에 처음 있던 위치가 경계선인 경우를 생각못했다. 그리고 결괏값 또한 경계선에 닿기까지가 아니라 완전히 넘어가기 까지 포함해야한다.
- 그리고 예시를 잘보면 J와F가 딱 붙어있는데, 이를 통해 F가 아닌 J가 선턴임을 알 수 있다. 동일한 턴에 서로 겹치는 위치가 아니라 서로 맞닥뜨리는
- 상황이라면 J는 먼저 피하고 불이 그 이후에 덮쳐 서로 꼬리물기를 하는 상황이 연출된다는 것을 예시를 통해 알아야한다.
- 문제를 잘읽고 예시를 보며 예외상황을 떠올리는 습관 가지자

다른 관점
-바킹독 강의 버전: 
상황판을 두가지 만들고, J/F에 대한 BFS를 각각 따로 실행한다. 우선 F에 대해서 각 칸에 퍼지기까지 시간을 기록해두고,
이후 J의 BFS를 실행한다. 이때는 J가 F보다 해당 칸에 더 일찍 도달해야한다는 조건하에 BFS가 진행된다.
처음에 나도 이런 접근을 하기도 했지만 싱크 맞추기에 대해 너무 걱정해서 방향을 틀었었다.
>>하지만 알아두어야 할것: 이 문제의 경우 둘다 서로 영향을 미치는게 아니라 적어도 한 종류는 독립적으로 그냥 퍼질 수 있기 때문에 BFS를 따로해도 문제 없었다.
하지만 물과 불같이 서로가 서로에게 영향을 미친다면 이 경우 강의버전의 접근법으로는 해결하지 못한다.

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
string board[1002];
int dist1[1002][1002]; // 불의 전파 시간
int dist2[1002][1002]; // 지훈이의 이동 시간
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    fill(dist1[i], dist1[i]+m, -1);
    fill(dist2[i], dist2[i]+m, -1);    
  }
  for(int i = 0; i < n; i++)
    cin >> board[i];
      
  queue<pair<int,int> > Q1;
  queue<pair<int,int> > Q2;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(board[i][j] == 'F'){
        Q1.push({i,j});
        dist1[i][j] = 0;        
      }
      if(board[i][j] == 'J'){
        Q2.push({i,j});
        dist2[i][j] = 0;
      }
    }
  }

  // 불에 대한 BFS
  while(!Q1.empty()){
    auto cur = Q1.front(); Q1.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue; 
      dist1[nx][ny] = dist1[cur.X][cur.Y]+1;
      Q1.push({nx,ny});
    }
  }

  // 지훈이에 대한 BFS
  while(!Q2.empty()){
    auto cur = Q2.front(); Q2.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m){ // 범위를 벗어났다는 것은 탈출에 성공했다는 의미. 큐에 거리 순으로 들어가므로 최초에 탈출한 시간을 출력하면 됨.
        cout << dist2[cur.X][cur.Y]+1; 
        return 0;
      }
      if(dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
      if(dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y]+1) continue; // 불의 전파 시간을 조건에 추가
      dist2[nx][ny] = dist2[cur.X][cur.Y]+1;
      Q2.push({nx,ny});
    }
  }
  cout << "IMPOSSIBLE"; // 여기에 도달했다는 것은 탈출에 실패했음을 의미.
}
*/

#include <bits/stdc++.h>
using namespace std;

char maze[1001][1001];//#: 벽 .: 길 J: 사람 F: 불
int board[1001][1001];
/*
board: (screen/monitor)
-1 초기화(unvisited)
-2(fire)
o(J starting position)
n(J가 n 걸음 감)

보드의 초기상황: J는 0값이 있는 곳에 위치, F있다면 그 곳에 -2들이 있고, 나머지는 -1(unknown)인 상태로 게임 시작
*/
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    queue<tuple<int, int, char>> Q;

    for(int i = 0; i < n; i++){
        fill(board[i], board[i] + m, -1);
    }

    //상황판(인풋) 읽어들이기 및 초기 세팅
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> maze[i][j];
            if(maze[i][j] == 'J'){
                Q.push({i, j, 'J'});
                board[i][j] = 0;
            }else if(maze[i][j] == 'F'){
                Q.push({i, j, 'F'});
                board[i][j] = -2;
            }
        }
    }

    while(true){//J를 맨 앞에 위치시키기
        auto [x, y, z] = Q.front();
        if(z == 'J') break;
        else{
            Q.push({x, y, z});
            Q.pop();
        }
    }

    while(!Q.empty()){
        auto [x, y, spc] = Q.front(); // spc = species
        Q.pop();

        if(spc == 'J'){
            if(board[x][y] == -2) continue; //저번턴의 불에의해 타버린 세계선인 경우 그 세계선을 버린다.

            //일단 경계만 닿으면 어떤 경우든 1턴 뒤에 탈출가능하다. 위의 조건을 통과했기 때문이다.
            if(x == 0 || x == n-1 || y == 0 || y == m-1){
                cout << board[x][y] + 1;
                return 0;
            }
        
            for(int dir = 0; dir < 4; dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;//out of boundary
                if(maze[nx][ny] == '#' || board[nx][ny] != -1) continue; 
                //벽이면 막힘. 안가본 곳을 제외한 나머지 모든 경우의 수는 다 막힘. (불에 의해서든, 지나온 발자국이든)      

                board[nx][ny] = board[x][y] + 1;
                Q.push({nx, ny, 'J'});     
          
            }
        }
        else if(spc == 'F'){
            for(int dir = 0; dir < 4; dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue; //out of boundary
                if(maze[nx][ny] == '#' || board[nx][ny] == -2) continue; //벽이거나, 이미 확산된 불중 하나거나(J가 지나왔던 길은 F의 제한사항이 아니다)

                board[nx][ny] = -2;
                Q.push({nx, ny, 'F'});
            }

        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}   