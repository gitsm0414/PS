/*
BOJ 5014 스타트링크
Used Algorithms:
Time Complexity: O()

핵심 아이디어
- 

실수
-여기서 BFS를 구현하면서 업, 다운의 경우를 for문안에서 일반화하지 않고 각각 따로했기 때문에, 기존 for문 사용하는 방법으로 if조건절 및 continue를
써버리면 up에서 안맞는 조건일 경우 죄없는 down까지 패스해버리는 사태가 발생한다. 따로따로 직접 코드를 적고싶다면 아래와같이 구현한다.
-또한 down값을 구할 때 -가 아니라 +해버린것도 있고, if조건절에서 &&해야하는데 습관적으로 ||한 실수도 있었다. 이 두가지는 모두 out of boundary error로
이어졌다.

다른 관점
-
*/

#include <bits/stdc++.h>
using namespace std;

int vis[1000005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int f, s, g, u, d; //1 <= s, g <= f <= 1,000,000
    cin >> f >> s >> g >> u >> d;
    
    fill(vis, vis + f + 1, -1); //-1 초기화
    queue<int> Q;
    vis[s] = 0;
    Q.push(s);
    
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        if(cur == g){
            cout << vis[cur];
            return 0;
        }

        //up
        int nu = cur + u;
        if(nu <= f && vis[nu] == -1){
            vis[nu] = vis[cur] + 1;
            Q.push(nu);
        }

        //down
        int nd = cur - d;
        if(nd > 0 && vis[nd] == -1){
            vis[nd] = vis[cur] + 1;
            Q.push(nd);           
        }

    }
    cout << "use the stairs\n";

    return 0;
}