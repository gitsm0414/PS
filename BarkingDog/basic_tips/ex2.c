#include<stdio.h>

int func2(int* arr, int n){
    for(int i=0; i < n-1; i++){
        for(int j=i+1; j < n; j++){
            if(arr[i]+arr[j] == 100) return 1;
        }
    }
    return 0;
}

int main(){
    int n;
    int* arr;
    scanf("%d", &n);
    for(int i=0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("%d", func2(arr, n));
}