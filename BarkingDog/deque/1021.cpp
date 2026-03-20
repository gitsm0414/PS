/*
BOJ 1021

문제
지민이는 N개의 원소를 포함하고 있는 양방향 순환 큐를 가지고 있다. 지민이는 이 큐에서 몇 개의 원소를 뽑아내려고 한다.

지민이는 이 큐에서 다음과 같은 3가지 연산을 수행할 수 있다.

첫 번째 원소를 뽑아낸다. 이 연산을 수행하면, 원래 큐의 원소가 a1, ..., ak이었던 것이 a2, ..., ak와 같이 된다.
왼쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 a2, ..., ak, a1이 된다.
오른쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 ak, a1, ..., ak-1이 된다.
큐에 처음에 포함되어 있던 수 N이 주어진다. 그리고 지민이가 뽑아내려고 하는 원소의 위치가 주어진다. (이 위치는 가장 처음 큐에서의 위치이다.) 
이때, 그 원소를 주어진 순서대로 뽑아내는데 드는 2번, 3번 연산의 최솟값을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 큐의 크기 N과 뽑아내려고 하는 수의 개수 M이 주어진다. N은 50보다 작거나 같은 자연수이고, M은 N보다 작거나 같은 자연수이다. 
둘째 줄에는 지민이가 뽑아내려고 하는 수의 위치가 순서대로 주어진다. 위치는 1보다 크거나 같고, N보다 작거나 같은 자연수이다.

출력
첫째 줄에 문제의 정답을 출력한다.

Algorithms: 
Time Complexity: O()

핵심 아이디어
- deque 라이브러리 이용

실수
- circular deque의 배열을 이용한 구현
초기원소위치 k, head, tail 간의 상대적인 위치 차이를 통해 짧은 쪽으로 연산과정을 결정한다. 
연산 과정에는 실제로 1, 2, 3번을 실시하면서 head, tai, count 등을 업데이트한다.
다만 이때 실제로 큐 안의 값을 확인하거나 삽입/삭제할 필요가 없으므로 circular deque를 추상적으로만 이용한다.

>>을! 하려고 했으나 논리적 오류가 너무 많았다. n <= 50처럼 범위가 작을 때는 복잡한 자료구조라도 직접 구현하거나 라이브러리를
사용하는 것을 꺼리지 말자.

다른 관점
-다음에는 배열과 인덱스를 사용해서 문제를 풀어보자. 실제로 다른사람의 풀이에서는 arr[50]만을 가지고 푼 것도 있다.
*/

#include <bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<int> dq;
    int count = 0;
    int n, m;
    cin >> n;

    for(int i = 0; i < n; i++){
        dq.push_back(i+1);
    }

    cin >> m;
    while(m--){
        int k;
        cin >> k;
        
        int i;
        for(i = 0; i < (int)dq.size(); i++){
            if(dq[i] == k) break;
        }
        
        int l, r; //각각 왼쪽 오른쪽으로 쉬프트해야하는 횟수
        l = i;
        r = dq.size() - i;

        if(l <= r){//left  
            count += l;
            while(l--){//2번 연산 l번
                dq.push_back(dq.front());
                dq.pop_front();
            }
            dq.pop_front();

        }else{//right
            count += r;
            while(r--){//3번 연산 r번
                dq.push_front(dq.back());
                dq.pop_back();
            }
            dq.pop_front();
        }
    }
    
    cout << count <<'\n';
    return 0;
}