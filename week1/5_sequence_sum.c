/*-----------------------------------------------------------
 * 5_sequence_sum.c  构造数列求和
 * 题目：输入两个正整数 n 和 a，构造数列：
 *       a, aa, aaa, ...，共 n 项
 *       （例如 a=2, n=3 时数列为 2, 22, 222），求数列所有项的和。
 * 思路：递推生成每一项——下一项 = 上一项 * 10 + a。
 *       注意结果可能很大，用 unsigned long long 存储。
 *-----------------------------------------------------------*/
#include <stdio.h>

int main(void)
{
    int n;                          /* 项数 */
    unsigned long long a;           /* 数字 a（1~9） */
    unsigned long long term = 0;    /* 当前项 */
    unsigned long long sum  = 0;    /* 累加和 */
    int i;

    printf("请输入 n 和 a（用空格分隔，例如：3 2）：");
    if (scanf("%d %llu", &n, &a) != 2 || n <= 0 || a < 1 || a > 9) {
        printf("输入无效！要求 n 为正整数，a 为 1~9 的数字。\n");
        return 1;
    }

    /* 打印数列并累加 */
    printf("数列为：");
    for (i = 0; i < n; i++) {
        term = term * 10 + a;   /* 由上一项递推：2 -> 22 -> 222 */
        sum  += term;
        printf("%llu", term);
        if (i < n - 1) printf(" + ");
    }
    printf(" = %llu\n", sum);
    printf("数列所有项的和为：%llu\n", sum);

    return 0;
}
