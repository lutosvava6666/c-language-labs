/*-----------------------------------------------------------
 * 3_palindrome.c  回文数判断
 * 题目：输入一个整数，判断它是否为回文数（正读和倒读相同）。
 * 思路：把整数按位反转得到 reversed，与原数比较。
 *       例如 12321 反转后仍是 12321，是回文数。
 *-----------------------------------------------------------*/
#include <stdio.h>

int main(void)
{
    int num;
    long long reversed = 0; /* 用 long long 防止反转后溢出 int */
    int temp;

    printf("请输入一个整数：");
    if (scanf("%d", &num) != 1) {
        printf("输入无效！\n");
        return 1;
    }

    /* 负数不是回文数（如 -121 倒读为 121-）；0 是回文数 */
    if (num < 0) {
        printf("%d 不是回文数\n", num);
        return 0;
    }

    temp = num;
    while (temp > 0) {
        reversed = reversed * 10 + temp % 10; /* 取出末位拼到结果后面 */
        temp /= 10;                           /* 去掉末位           */
    }

    if (reversed == num)
        printf("%d 是回文数\n", num);
    else
        printf("%d 不是回文数\n", num);

    return 0;
}
