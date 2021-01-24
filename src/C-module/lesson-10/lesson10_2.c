/**
 * Напишите программу для сложения и вычитания целочисленных векторов.
Программа считывает знак операции + или -. Затем считывает количество элементов в векторах, затем элементы первого и второго векторов. Программа выводит элементы результирующего вектора через пробел. Если операцию провести невозможно, выведите error.
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void input_array( long long* buffer,int n){
    for (int i=0;i<n;i++){
        long long  u;
        int check_u = scanf("%lld",&u);
        if ( check_u ==  1) {
            buffer[i] = u;
        }else{
            printf("error");
            exit(0);
        }
    }
}

void print(long long* buffer,int n){
    for (int i=0;i<n;i++){
        printf("%lld ",buffer[i]);
    }
}

void operation(int znak,int n, long long* vec1 ,  long long* vec2){
    long long* out = calloc(n, sizeof(long long));
    int plus =  1;
    int minus = 0;
    if( znak == plus){
        for (int i=0;i<n;i++){
            out[i] = vec1[i]+vec2[i];
        }
        print(out,n);
        return;
    }else if (znak == minus){
        for (int i=0;i<n;i++){
            out[i] = vec1[i]-vec2[i];
        }
        print(out,n);
        return;
    }
    printf("error");
    exit(0);
}
int main(){
    char znak;
    scanf("%s",&znak);
    int n;
    scanf("%d",&n);
    long long buff1[n],buff2[n];
    input_array(buff1,n);
    input_array(buff2,n);
    int g;
    if (znak == '+'){
        g = 1;
    }else if (znak =='-'){
        g = 0;
    }else{
        printf("error");
        exit(0);
    }
    operation(g, n, buff1, buff2);
    return 0;
}