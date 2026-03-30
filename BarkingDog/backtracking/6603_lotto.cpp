/*
BOJ 6603 로또
Used Algorithms:
Time Complexity: O()

핵심 아이디어
- 

실수
- 

다른 관점
-next_permutation 쓰는 방법

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int karr[13];
    int mask[13];

    while(true){
        int k;
        cin >> k;
        if(k == 0) break;
        for(int i = 0; i < k; i++) cin >> karr[i];

        for(int i = 0; i < k; i++){
            if(i < 6) mask[i] = 0;
            else mask[i] = 1;
        }

        do{
            for(int i = 0; i < k; i++){
                if(mask[i] == 0) cout << karr[i] << ' ';
            }
            cout << '\n';
        }while(next_permutation(mask, mask+k));

        cout << '\n';
    }
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int k;
int karr[13];
int res[7];

void f(int depth, int st){
    if(depth == 6){
        for(int i = 0; i < 6; i++) cout << res[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = st; i < k; i++){
        res[depth] = karr[i];
        f(depth+1, i+1);//또 st라고 해버렸네이거
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        cin >> k;
        if(k == 0) break;
        for(int i = 0; i < k; i++) cin >> karr[i];

        f(0, 0);

        cout << '\n';
    }
    return 0;
}