/*
BOJ 1780 종이의 개수
Used Algorithms:
Time Complexity: O()

핵심 아이디어
-재귀

실수
- 

다른 관점
-
*/

#include <bits/stdc++.h>
using namespace std;

int minu = 0;
int zero = 0;
int one = 0;
//이들을 res[3] 으로 묶어서 -1, 0, 1을 각각 0, 1, 2 idx에 대응되게하면, res[tmp+1]을 이용해 코드를 간단히할 수 있다. 

int baord[2200][2200];

void f(int len, int x, int y){//len: 한변 길이, x&y: 주어진 구역의 좌상단 지점(시작지점)
    int tmp = baord[x][y];
    //base condition 
    if(len == 1){
        if(tmp == -1) minu++;
        else if(tmp == 0) zero++;
        else if(tmp == 1) one++;
        return;
    }
    //examining
    bool same = true;
    for(int i = x; i < x + len; i++){
        for(int j = y; j < y + len; j++){
            if(tmp != baord[i][j]){
                same = false; break;
            }
        }
        if(!same) break;
    }

    if(same){
        if(tmp == -1) minu++;
        else if(tmp == 0) zero++;
        else if(tmp == 1) one++;
        return;
    }
    else //같지 않을 경우 각 9분면에 대해 f를 호출한다.
    {
        int t = len/3;
        //1
        f(t, x, y);
        //2
        f(t, x, y + t);
        //3
        f(t, x, y + 2*t);
        //4
        f(t, x + t, y);
        //5
        f(t, x + t, y + t);
        //6
        f(t, x + t, y + 2*t);
        //7
        f(t, x + 2*t, y);
        //8
        f(t, x + 2*t, y + t);
        //9
        f(t, x + 2*t, y + 2*t);
    }
}
/*
f호출 부분을 for문을 이용해 다음과같이 단순화할 수 있다.

else {//같지 않을 경우 각 9분면에 대해 f를 호출한다.
    int t = len / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            f(t, x + i * t, y + j * t);
        }
    }
}
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            cin >> baord[i][j];
        }
    }

    f(n, 0, 0);

    cout << minu << '\n' << zero << '\n' << one;

    return 0;
}