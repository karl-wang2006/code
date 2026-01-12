#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
//通讯录
//  1.添加联系人  2.删除  3.查找  4.修改信息  5.打印已有信息  6.排序  0.退出

int main()
{
	int input = 0;
	con contact;
	int flag = 0;
	init_contact(&contact);
	int n = 0;
	do
	{
		menu();
		printf("please enter a number:");
		int ret = scanf("%d", &input);
		while (getchar() != '\n');
		if (ret != 1) 
		{   // 读取失败（非数字）
			input = -1; // 设为无效值，触发 default 分支
		}
		switch (input)
		{
		case 0:
			printf("The program has successfully exited.\n");
			break;
		case 1:
			add_info(&contact);
			break;
		case 2:
			delete_info(&contact);
			break;
		case 3:
			 flag = search_info(&contact);
			 if (flag != -1)
			 {
				 printf("Do you want to modify?(Yes:1 No:2)  ");
				 scanf("%d", &n);
				 switch (n)
				 {
				 case 2:
					 break;
				 case 1:
					 modify_info_by_idx(&contact,flag);
					 break;
				 default:
					 printf("Invalid order\n");
					 printf("\n");
				 }
			 }
			break;
		case 4:		
			modify_info(&contact);
			break;
		case 5:
			show_info(&contact);
			break;
		case 6:
			sort_info(&contact);
			break;
		default:
			printf("Invalid number, please try again.\n");
			break;
		}
	} while (input);
	destructor(&contact);
	return 0;
}