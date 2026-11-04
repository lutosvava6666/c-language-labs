/*-----------------------------------------------------------
 * 3-13_fibonacci.c  递归求 Fibonacci 数列
 * 题目：用递归的方法编写函数求 Fibonacci 级数，公式为：
 *           F(n) = F(n-1) + F(n-2)  (n > 2)
 *           F(1) = F(2) = 1
 *       注意观察递归调用的过程。
 *-----------------------------------------------------------*/
#include <stdio.h>

/* 函数：fib —— 递归计算 Fibonacci 数列第 n 项
 * 参数：n —— 项数（n >= 1）
 * 返回：第 n 项的值 */
long long fib(int n)
{
    if (n == 1 || n == 2)   /* 递归出口：F(1) = F(2) = 1 */
        return 1;
    return fib(n - 1) + fib(n - 2);  /* 递归调用：F(n) = F(n-1) + F(n-2) */
}

int main(void)
{
    int n, i;

    printf("请输入要求的项数 n（n >= 1）：");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("输入无效！n 必须为正整数。\n");
        return 1;
    }

    /* 输出数列前 n 项 */
    printf("Fibonacci 数列前 %d 项为：\n", n);
    for (i = 1; i <= n; i++) {
        printf("F(%d) = %lld\n", i, fib(i));
    }

    /* 单独输出第 n 项 */
    printf("\n第 %d 项的值为：%lld\n", n, fib(n));

    return 0;
}
