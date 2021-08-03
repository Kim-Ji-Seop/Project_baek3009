#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int calculate(int x, int y, int z) {
    int money;// ���ϰ�
    int score[3];//for������ index�� ���� �����ϱ� ���� �迭����
    int max = 0;//�ִ� �񱳰� ���� �뵵
    if (x == y && x == z && y == z) {//���� ���� 3���� ������ 10,000��+(���� ��)��1,000���� ����� �ް� �ȴ� -> ���� 1
        money = 10000 + (x * 1000);
    }
    else if (x != y && x != z && y != z) {// ��� �ٸ� ���� ������ ��쿡�� (�� �� ���� ū ��)��100���� ����� �ް� �ȴ�. -> ����3
        score[0] = x; score[1] = y; score[2] = z;
        for (int i = 0; i < 3; i++) {
            if (max < score[i]) {
                max = score[i];
            }
        }
        money = max * 100;
    }
    else { // ���� ���� 2���� ������ ��쿡�� 1,000��+(���� ��)��100���� ����� �ް� �ȴ� -> ���� 2�� ������ ���ǹ�
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
    scoreList = malloc(sizeof(int) * number);//number�� ���� ���������� �迭�� ���̸� �޸� �ϰ� �;���.
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