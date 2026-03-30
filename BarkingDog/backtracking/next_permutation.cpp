#include<algorithm>
#include<iostream>
using namespace std;

/*
next_permutation()
반환값: 다음 순열이 존재하면 true를 반환하고 배열을 변환합니다. 
만약 현재가 마지막 순열(내림차순 정렬된 상태)이라면 false를 반환하고 배열을 다시 첫 번째 순열(오름차순)로 되돌립니다.
*/
int main(){
    

    //arr의 가능한 permutation들을 출력하는 과정
    int arr[4] = {1, 2, 3, 4};
    do{
        for(int i = 0; i < 4; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }while(next_permutation(arr, arr+4));

    //arr의 가능한 combination들을 출력하는 과정 >> 4C2
    int arr1[4] = {0, 0, 1, 1};
    do{
        for(int i = 0; i < 4; i++){
            if(arr1[i] == 0)
                cout << i+1 << ' ';
        }
        cout << '\n';
    }while(next_permutation(arr1, arr1+4));


    return 0;
}