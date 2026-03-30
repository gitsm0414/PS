/*
BOJ 1759 암호 만들기
Used Algorithms:
Time Complexity: O()

핵심 아이디어
- 

실수
- 

다른 관점
-v, c 인자를 추가해 isValid()를 없앨 수도 있다.

// v: 모음 개수, c: 자음 개수
void f(int idx, int st, int v, int c) {
    if (idx == L) {
        if (v >= 1 && c >= 2) {
            cout << res << '\n';
        }
        return;
    }
    for (int i = st; i < C; i++) {
        res[idx] = input[i];
        
        // 현재 선택한 문자가 모음인지 확인
        bool isVow = (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u');
        
        // 인자로 개수를 더해서 넘김
        f(idx + 1, i + 1, v + (isVow ? 1 : 0), c + (isVow ? 0 : 1));
    }
}
*/

#include <bits/stdc++.h>
using namespace std;

int L, C;
char input[20];
char res[20];

bool isValid(){
    int vow = 0;//vowel 모음
    int cons = 0;//consonant
    for(int i = 0; i < L; i++){
        if(res[i] == 'a' || res[i] == 'e' || res[i] == 'i' || res[i] == 'o' || res[i] == 'u') vow++;
        else cons++;
    }
    if(vow>=1 && cons >=2) return true;
    else return false;
}

void f(int idx, int st){
    if(idx == L){
        if(!isValid()) return;

        res[L] = '\0';
        cout << res << '\n';
        return;
    }
    for(int i = st; i < C; i++){
        res[idx] = input[i];
        f(idx+1, i+1);
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> L >> C;
    for(int i = 0; i < C; i++){
        cin >> input[i];
        for(int j = i; j > 0; j--){
            if(input[j-1] > input[j]){
                int tmp = input[j-1];
                input[j-1] = input[j];
                input[j] = tmp;
            }
        }
    }

    f(0, 0);

    return 0;
}