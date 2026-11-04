/*-----------------------------------------------------------
 * 2_movie_rating.c  电影打分
 * 题目：根据用户给电影的打分 score 输出对应语句：
 *   10~9 分：经典
 *   8~7  分：非常好
 *   6~5  分：一般
 *   5 分以下：烂片
 * 例如输入 7，输出："你认为电影非常好"。
 *-----------------------------------------------------------*/
#include <stdio.h>

int main(void)
{
    int score;

    printf("请输入你对电影的打分（0~10）：");
    if (scanf("%d", &score) != 1) {
        printf("输入无效！\n");
        return 1;
    }

    if (score < 0 || score > 10) {
        printf("打分必须在 0~10 之间！\n");
        return 1;
    }

    /* switch 按区间分支：case 会向下贯穿，所以 10、9 落到同一分支 */
    switch (score) {
        case 10:
        case 9:
            printf("你认为电影经典\n");
            break;
        case 8:
        case 7:
            printf("你认为电影非常好\n");
            break;
        case 6:
        case 5:
            printf("你认为电影一般\n");
            break;
        default:               /* 0~4 分 */
            printf("你认为电影是烂片\n");
            break;
    }

    return 0;
}
