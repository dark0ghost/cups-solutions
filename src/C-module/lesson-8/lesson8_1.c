/**
 * Напишите функцию с названием det, которая принимает квадратную матрицу, размерностью n, и возвращает её определитель. Указатель на матрицу и целочисленный параметр n передаются в функцию аргументом.
 */

#include <stdlib.h>


void clearMemory(long int** a, long int  n) {
    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);
}
double pow(double x, double y){
    if (y != 0)
        return (x * pow(x, y - 1));
    else
        return 1;
}

long int  det(long int ** a,long int  n){
    if (n == 1)
        return a[0][0];
    else if (n == 2)
        return a[0][0] * a[1][1] - a[0][1] * a[1][0];
    else {
        long int  d = 0;
        for (long int  k = 0; k < n; k++) {
            long int** m =  malloc((n - 1)*sizeof(long int ));
            for (long int  i = 0; i < n - 1; i++) {
                m[i] =  malloc((n - 1)*sizeof(long int )) ;
            }
            for (long int  i = 1; i < n; i++) {
                long int t = 0;
                for (long int j = 0; j < n; j++) {
                    if (j == k)
                        continue;
                    m[i-1][t] = a[i][j];
                    t++;
                }
            }
            d += pow(-1, (k + 2)) * a[0][k] * det(m, n - 1);
            clearMemory(m, n - 1);
        }
        return d;
    }
}