#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int calculate(int x, int y, int z) {
    int money;// 리턴값
    int score[3];//for문으로 index로 쉽게 접근하기 위한 배열선언
    int max = 0;//최댓값 비교값 저장 용도
    if (x == y && x == z && y == z) {//같은 눈이 3개가 나오면 10,000원+(같은 눈)×1,000원의 상금을 받게 된다 -> 조건 1
        money = 10000 + (x * 1000);
    }
    else if (x != y && x != z && y != z) {// 모두 다른 눈이 나오는 경우에는 (그 중 가장 큰 눈)×100원의 상금을 받게 된다. -> 조건3
        score[0] = x; score[1] = y; score[2] = z;
        for (int i = 0; i < 3; i++) {
            if (max < score[i]) {
                max = score[i];
            }
        }
        money = max * 100;
    }
    else { // 같은 눈이 2개만 나오는 경우에는 1,000원+(같은 눈)×100원의 상금을 받게 된다 -> 조건 2를 포함한 조건문
        if (x == y && x != z) {
            money = 1000 + (x * 100);
        }
        if (x == z && x != y) {
            money = 1000 + (x * 100);
        }
        if (y == z && y != x) {
            money = 1000 + (y * 100);
        }
    }
    return money;
}
int main() {
    int a, b, c;
    int max = 0;
    int* scoreList;
    int number;
    scanf("%d", &number);
    scoreList = malloc(sizeof(int) * number);//number에 따라 가변적으로 배열의 길이를 달리 하고 싶었음.
    for (int i = 0; i < number; i++) {
        scanf("%d %d %d", &a, &b, &c);
        scoreList[i] = calculate(a, b, c);
        if (max < scoreList[i]) {
            max = scoreList[i];
        }
    }
    printf("%d", max);
    free(scoreList);
    return 0;
}