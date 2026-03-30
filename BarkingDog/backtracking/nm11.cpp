/*
BOJ 15650 nm2
Used Algorithms:
Time Complexity: O()

핵심 아이디어
- 

실수
- arr 정렬 빼먹음

다른 관점
-
*/

#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int arr[10];
    int res[10];

    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);

    string out = "";

    function<void(int)> backtrack = [&](int idx)
    {
        if(idx == m){
            for(int i = 0; i < m; i++){
                out += to_string(res[i]) + ' ';
            }
            out += '\n';
            return;
        }
        int last_val = 0; //arr가 정렬되어 있다는 전제하에 유효한 방법
        for(int i = 0; i < n; i++){
            if(last_val == arr[i]) continue;
            last_val = arr[i];
            res[idx] = last_val;
            backtrack(idx+1);
        }
    };
    
    backtrack(0);
    cout << out;
    return 0;
}