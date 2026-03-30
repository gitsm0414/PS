/*
BOJ 9663 nQ
Used Algorithms:
Time Complexity: O(N!)*O(1) >> O(1)은 내부연산이다. column이 하나씩 빠지는것만 생각하면 O(N!)이지만 실제로는 대각선에 의해서 함수 콜이 더 줄어든다는
걸 알아두자.(이를 백트래킹에서 가지치기라 함. 이런 가지치기 때문에 시간복잡도를 예측하기 어렵다.) 

핵심 아이디어
- 

실수
>>다 필요없고 그냥 "2차원 배열 전체를 매번 업데이트하는 것은 $O(N^3)$ 이상의 비용이 들어 시간 초과의 주범이 된다."
>>다른 관점이 필요하다.

다른 관점
-2차원 배열 하나에 몰아넣어서 판단하지 않고, N퀸은 행 기준으로 한 행당 하나씩만 있음을 이용하여서, 나머지 이동구간인 열, 대각선 x 2 를 각각의 1차원 배열
로 따로 만들어서 isused판단을 O(1)에 끝낼 수 있게 해준다.
*/

#include <bits/stdc++.h>
using namespace std;

int N;
int cnt = 0;

bool isused_col[15]; //[c]
bool isused_sum[30]; //[r + c]
bool isused_dif[30]; //[r - c + (N -1)]


void f(int r){//row
    if(r == N){
        cnt++;
        return;
    }
    
    for(int c = 0; c < N; c++){//column
        if(isused_col[c] || isused_sum[r+c] || isused_dif[r-c+N-1]) continue;

        isused_col[c] = true;
        isused_sum[r+c] = true;
        isused_dif[r-c+N-1] = true;

        f(r+1);

        isused_col[c] = false;
        isused_sum[r+c] = false;
        isused_dif[r-c+N-1] = false;
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    f(0);
    cout << cnt;

    return 0;
}

/*
내 처음 코드...

#include <bits/stdc++.h>
using namespace std;

int N;
int cnt = 0;

bool isused[15][15]; //0으로 초기화
int arr[15][2]; //각 퀸들의 x좌표를 저장하기 위한 배열, 무조건 오름차순으로 저장해야한다는 규칙이 있다.

void f(int k){
    if(k == N){
        cnt++;
        return;
    }

    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
            if(!isused[x][y]){
                if((k >= 1 && arr[k-1][0] < x) || k == 0){//N퀸에서는 각 좌표들이 겹치는 부분이 없기에 한 좌표만 기준으로 줄세워도 유일하다.
                    //marking unvalid coordinates step-a
                    for(int i = 0; i < N; i++){
                        for(int j = 0; j < N; j++){
                            if(i == x || j == y || i-j == x-y || i+j == x+y) isused[i][j] = 1;
                        }
                    }
                    arr[k][0] = x;
                    arr[k][1] = y;

                    f(k+1);

                    //unmasking step-a
                    for(int i = 0; i < N; i++){
                        for(int j = 0; j < N; j++){

                            if(i == x || j == y || i-j == x-y || i+j == x+y){

                                bool flag = true;
                                for(int idx = 0; idx < k; idx++){
                                    if(i == arr[idx][0] || j == arr[idx][1] || i-j == arr[idx][0]-arr[idx][1] || i+j == arr[idx][0]+arr[idx][1]){
                                        flag = false;
                                    }
                                }
                                if(flag) isused[i][j] = 0;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    f(0);
    cout << cnt;

    return 0;
}
*/