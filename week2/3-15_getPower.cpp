/*-----------------------------------------------------------
 * 3-15_getPower.cpp  函数重载：递归计算 x^y
 * 题目：编写递归函数 getPower 计算 x^y，在同一个程序中针对
 *       整型和实型实现两个重载函数：
 *           int    getPower(int x,    int y);  // 整型版本，y < 0 时返回 0
 *           double getPower(double x, int y);  // 实型版本
 *       在主程序中实现输入输出：分别输入一个整数 a 和一个实数 b
 *       作为底数，再输入一个整数 m 作为指数，输出 a^m 和 b^m。
 *
 * 思考：如果在调用 getPower 函数计算 a^m 时希望得到一个实型
 *       结果（实型结果表示范围更大，而且可以准确表示 m < 0 时
 *       的结果），只需把第一个实参写成形如 (double)a 的强制
 *       类型转换，或者把 a 存入 double 变量再传入，编译器就会
 *       依据实参类型自动匹配 double getPower(double, int) 重载
 *       版本。注意观察递归调用的过程。
 *-----------------------------------------------------------*/
#include <iostream>
using namespace std;

/* 整型版本：递归计算 x^y，当 y < 0 时返回 0 */
int getPower(int x, int y)
{
    if (y < 0)
        return 0;               /* 整型版本不支持负指数 */

    if (y == 0)
        return 1;               /* 递归出口：x^0 = 1 */

    if (y % 2 == 0) {                       /* y 为偶数：分治加速 */
        int half = getPower(x, y / 2);
        return half * half;
    }
    return x * getPower(x, y - 1);          /* y 为奇数：转化为 y-1 */
}

/* 实型版本：递归计算 x^y，支持负指数（返回 1/x^|y|） */
double getPower(double x, int y)
{
    if (y == 0)
        return 1.0;             /* 递归出口：x^0 = 1 */

    if (y > 0) {
        if (y % 2 == 0) {                   /* y 为偶数：分治加速 */
            double half = getPower(x, y / 2);
            return half * half;
        }
        return x * getPower(x, y - 1);      /* y 为奇数 */
    }
    /* y < 0：x^(-y) = 1 / x^y */
    return 1.0 / getPower(x, -y);
}

int main(void)
{
    int a, m;
    double b;

    cout << "请输入整数 a 和实数 b（作为底数），以及整数 m（作为指数）：" << endl;
    cout << "格式：a b m，例如：2 2.5 -3" << endl;
    if (!(cin >> a >> b >> m)) {
        cout << "输入无效！" << endl;
        return 1;
    }

    /* 整型版本：a^m（m < 0 时返回 0） */
    cout << "整型版本 getPower(" << a << ", " << m << ") = "
         << getPower(a, m) << endl;

    /* 实型版本：b^m（支持 m < 0） */
    cout << "实型版本 getPower(" << b << ", " << m << ") = "
         << getPower(b, m) << endl;

    /* 思考的验证：对整数 a 强制转换为 double，调用实型版本，
       即可得到范围更大、支持 m < 0 的实型结果 */
    cout << "以实型版本计算 a^m：getPower((double)" << a << ", " << m << ") = "
         << getPower((double)a, m) << endl;

    return 0;
}
