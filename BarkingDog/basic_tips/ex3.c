#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int i = 1;
    while(i*i <= n){
        if(i*i == n){
            printf("%d", 1);
            return 1;
        }  
        i++;
    }
    printf("%d", 0);
    return 0;
}