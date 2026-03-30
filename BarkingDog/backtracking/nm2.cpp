/*
BOJ 15650 nm2
Used Algorithms:
Time Complexity: O()

핵심 아이디어
- 

실수
- 

다른 관점

#include <bits/stdc++.h>
using namespace std;

int arr[9];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        if(i < m) arr[i] = 0; //selected
        else arr[i] = 1;
    }
    do{
        for(int i = 0; i < n; i++){
            if(arr[i] == 0) cout << i+1 << ' ';
        }
        cout << '\n';
    }while(next_permutation(arr, arr + n));

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;


int arr[9];
int n, m;

void f(int k, int pre){//pre: previous number(1~n-1이 될 수 있으며, 예외적으로 이전 항이 없는 초기상황에서는 pre = 0으로하여 호출한다.), k: cur idx
    if(k == m){
        for(int i = 0; i < m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = pre+1; i <= n; i++){//range of possible n
        arr[k] = i;
        f(k+1, i);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    cin >> n >> m;

    f(0, 0);
    return 0;
}