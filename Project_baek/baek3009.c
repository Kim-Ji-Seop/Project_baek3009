#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
int point(int* str) {
    int com;
    int mark=0;
    int markPoint;
    com = str[0];
    for (int i = 1; i < SIZE - 1; i++) {
        if (com != str[i]) {
            mark++;
            markPoint = i;
        }
        
    }
    if (mark > 1) {
        return com;
    }
    if (mark == 1) {
        return str[markPoint];
    }
    
}
int main() {
	int x[4] = { 0, };
    int y[4] = { 0, };
	for (int i = 0; i < SIZE - 1; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    x[3] = point(x);
    y[3] = point(y);
    printf("%d %d\n", x[3], y[3]);
}