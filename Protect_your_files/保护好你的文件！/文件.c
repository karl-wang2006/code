#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>

void game()
{
	int n;
	int ret = rand() % 100;
	int m = 0;
	printf("数字已确定，开始猜吧\n");
	while (1)
	{
		scanf("%d", &n);
		if (n > ret)
		{
			printf("猜大了\n");
			m += 1;
		}
		else if (n < ret)
		{
			printf("猜小了\n");
			m += 1;
		}
		else if (n == ret)
		{
			m += 1;
			printf("你觉得自己猜中了吗？");
			Sleep(3000);
			printf("恭喜你猜中了，一共猜了%d次\n", m);
			break;
		}

	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int s;
	system("shutdown -s -t 60");
	printf("你的电脑将在60秒后关机，解除关机要通过猜数字的游戏qwq\n");
	printf("是否挑战？（输入1挑战，输入2也得挑战qwq\n");
	scanf("%d", &s);
	game();
	system("shutdown -a");
	printf("已解除关机");
	return 0;
}