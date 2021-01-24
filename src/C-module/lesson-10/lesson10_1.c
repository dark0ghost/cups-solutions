/**
 * Напишите код, который считывает из стандартного ввода числа в десятичной форме записи и выводит эти числа построчно в восьмеричной форме.
Программа завершается, когда стандартный ввод закрывается или поступили некорректные данные.
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


int check(char* str){
    for(int i = 0 ; i< strlen(str);i++) {
        if (isdigit(str[i]) == 0 && str[i] != '-')
            return 1;
    }
    return 0;
}

void print(long long* out,int u){
    for(int i = 0; i<u-1;i++)
        printf("%llo ",out[i]);
}

int main(){
    int y = 1;
    char h[500];
    long long  out[500] = {0};
    int po = 0;
    gets(h);

    char* pch = strtok (h," ");
    while (pch != NULL) {
        if (check(pch)) {
            break;
        }
        long long a = atoll(pch);
        out[po] = a;
        po=po+1;
        y+=1;
        pch = strtok (NULL, " ");
    }
    print(out,y);
    return 0;
}