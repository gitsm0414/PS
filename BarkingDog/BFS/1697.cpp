/*
BOJ 1697
Used Algorithms:
Time Complexity: O()

핵심 아이디어
- 

실수
- BFS에서는 먼저방문한 놈이 가장 최단거리임을 보장한다. 따라서 다익스트라 마냥 비교할 필요없고 방문한적있는가?만 보면된다.
-fill(dist, dist+MAX, -1)에서 범위는 dist <= x < dist + MAX 이다. 즉 끝나는 지점은 포함하지 않는 것이다. 그렇게 함으로써
-배열의 모든 원소를 채우는 것은 단지 배열의 원소개수를 적기만하면 된다. 머리아프게 원소개수와 최대인덱스가 한개차이난다는 생각을할필요가 없는것이다.

다른 관점
-조건에 의해 수빈이와 동생의 시작위치 범위가 주어졌지만, 수빈이가 이동하면서 이 범위를 나가는 경우에 대해서도 생각할 줄 알아야한다.
-이 문제의 경우 운좋게 그 사이만 생각해도 논리적으로 문제가 없는 상황이지만, 다른문제에서도 그럴 것이란 보장은 없다.
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 100001
int dist[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fill(dist, dist + MAX, -1); //dist초기화, -1로.

    int n, k;
    cin >> n >> k;

    queue<int> Q;
    Q.push(n);
    dist[n] = 0;

    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        if(cur == k){
            cout << dist[cur];
            return 0;
        }
        for(int next : {cur -1, cur +1, cur *2}){
            if(next < 0 || next >= MAX) continue;
            if(dist[next] != -1) continue; //이미 방문한 칸이면 최단시간은 이미 구해졌다.

            dist[next] = dist[cur] + 1;
            Q.push(next);
        }

    }

    return 0;
}


/*
        이렇게 다익스트라처럼 할 필요가 없다. BFS니까
        int fwd = cur + 1;
        if(fwd < MAX && dist[fwd] > dist[cur] + 1){
            dist[fwd] = dist[cur] + 1;
            Q.push(fwd);
        }

        int bwd = cur - 1;
            if(bwd >= 0 && dist[bwd] > dist[cur] + 1){
            dist[bwd] = dist[cur] + 1;
            Q.push(bwd);
        }

        int jmp = cur * 2;
            if(jmp < MAX && dist[jmp] > dist[cur] + 1){
            dist[jmp] = dist[cur] + 1;
            Q.push(jmp);
        }
*/