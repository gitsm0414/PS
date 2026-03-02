#include<iostream>
using namespace std;

int main(){
    int N;
    int max_num = 1;
    cin >> N;

    while(2*max_num <= N){
        max_num *= 2;
    }
    
    cout << max_num;
    return 0;
}