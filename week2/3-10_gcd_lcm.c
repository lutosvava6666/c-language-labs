/*-----------------------------------------------------------
 * 3-10_gcd_lcm.c  最大公约数与最小公倍数
 * 题目：编写函数求两个整数的最大公约数和最小公倍数。
 *       要求两个整数以及结果均在主函数中输入输出。
 * 思路：最大公约数用辗转相除法（欧几里得算法）：
 *       gcd(a, b) = gcd(b, a % b)，直到 b 为 0。
 *       最小公倍数 = a * b / gcd(a, b)。
 *-----------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>   /* 用于 abs() 取绝对值 */

/* 函数：gcd —— 求最大公约数（辗转相除法）
 * 参数：a、b —— 两个整数
 * 返回：a 和 b 的最大公约数 */
int gcd(int a, int b)
{
    int t;
    while (b != 0) {
        t = a % b;  /* a 除以 b 取余 */
        a = b;      /* b 变成新的被除数 */
        b = t;      /* 余数变成新的除数 */
    }
    return a;
}

/* 函数：lcm —— 求最小公倍数
 * 公式：lcm(a, b) = |a * b| / gcd(a, b) */
int lcm(int a, int b)
{
    return abs(a * b) / gcd(a, b);
}

int main(void)
{
    int a, b;

    printf("请输入两个整数（空格分隔）：");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("输入无效！\n");
        return 1;
    }

    /* 处理特殊情况：两数中存在 0 时，最大公约数取非零数的绝对值 */
    if (a == 0 || b == 0) {
        printf("%d 和 %d 的最大公约数为：%d\n", a, b, gcd(a, b));
        printf("%d 和 %d 的最小公倍数为：0\n", a, b);
        return 0;
    }

    printf("%d 和 %d 的最大公约数为：%d\n", a, b, gcd(a, b));
    printf("%d 和 %d 的最小公倍数为：%d\n", a, b, lcm(a, b));

    return 0;
}
