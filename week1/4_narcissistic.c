/*-----------------------------------------------------------
 * 4_narcissistic.c  水仙花数
 * 题目：判断一个三位数是否为水仙花数（各位数字立方和等于原数），
 *       并输出所有三位水仙花数。
 *       例如 153 = 1^3 + 5^3 + 3^3，是水仙花数。
 *-----------------------------------------------------------*/
#include <stdio.h>

/* 判断三位数 n 是否为水仙花数：是返回 1，不是返回 0 */
int isNarcissistic(int n)
{
    int a = n / 100;       /* 百位 */
    int b = n / 10 % 10;   /* 十位 */
    int c = n % 10;        /* 个位 */
    int sum = a * a * a + b * b * b + c * c * c;
    return sum == n;
}

int main(void)
{
    int n;

    /* 第一部分：输入一个三位数，判断是否为水仙花数 */
    printf("请输入一个三位数：");
    if (scanf("%d", &n) != 1) {
        printf("输入无效！\n");
        return 1;
    }
    if (n < 100 || n > 999) {
        printf("%d 不是三位数！\n", n);
        return 1;
    }
    if (isNarcissistic(n))
        printf("%d 是水仙花数\n", n);
    else
        printf("%d 不是水仙花数\n", n);

    /* 第二部分：遍历输出所有三位水仙花数 */
    printf("\n所有三位水仙花数有：");
    for (n = 100; n <= 999; n++) {
        if (isNarcissistic(n))
            printf("%d ", n);
    }
    printf("\n");

    return 0;
}
