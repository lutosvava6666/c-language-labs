/*-----------------------------------------------------------
 * 3-7_division.c  unsigned short int 除法函数
 * 题目：完成函数，参数为两个 unsigned short int 型数，
 *       返回值为第一个参数除以第二个参数的结果，数据类型为
 *       short int；如果第二个参数为 0，则返回值为 -1。
 *       在主程序中实现输入输出，注意观察函数的参数传入传出、
 *       返回值。
 *-----------------------------------------------------------*/
#include <stdio.h>

/* 函数：div_unsigned
 * 参数：a —— 被除数（unsigned short int）
 *       b —— 除数  （unsigned short int）
 * 返回：a / b 的整数商（short int）；b == 0 时返回 -1 */
short div_unsigned(unsigned short a, unsigned short b)
{
    if (b == 0) {
        return -1;              /* 除数为 0，返回 -1 表示错误 */
    }
    return (short)(a / b);      /* 正常返回整数商 */
}

int main(void)
{
    unsigned short a, b;
    short result;

    printf("请输入两个非负整数 a 和 b（0~65535，空格分隔）：");
    if (scanf("%hu %hu", &a, &b) != 2) {
        printf("输入无效！\n");
        return 1;
    }

    result = div_unsigned(a, b);    /* 调用函数，观察参数传入与返回值 */

    if (result == -1)
        printf("除数 %hu 为 0，无法计算，函数返回 -1\n", b);
    else
        printf("%hu / %hu = %hd\n", a, b, result);

    return 0;
}
