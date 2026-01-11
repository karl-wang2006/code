#define _CRT_SECURE_NO_WARNINGS

#include "contact.h"

//通讯录
//  1.添加联系人  2.删除  3.查找  4.修改信息  5.打印已有信息  6.排序  0.退出
void menu()
{
	printf("******************************************\n");
	printf("*******  1.add         2.delete    *******\n");
	printf("*******  3.search      4.modify    *******\n");
	printf("*******  5.show        6.sort      *******\n");
	printf("*******  0.exit                    *******\n");
	printf("******************************************\n");
}
void init_contact(con* pc)
{
	memset(pc->data,0 , sizeof(pc->data));
	pc->size = 0;
}

int main()
{
	int input = 0;
	con contact;
	init_contact(&contact);
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
			printf("Enter the name you want to search:");
			char name[MAX_NAME] = { 0 };
			scanf("%s", name);
			int pos=search_info(&contact,name);
			if (pos == -1)
			{
				printf("Not in the list.\n");
			}
			else
			{
				printf("%-5s\t%-5s\t%-3s\t%-13s\t%-20s\n",
					"NAME",
					"GENDER",
					"AGE",
					"TELE",
					"ADDRESS");
				printf("%-5s\t%-5s\t%-3d\t%-13s\t%-20s\n",
					contact.data[pos].name,
					contact.data[pos].sex,
					contact.data[pos].age,
					contact.data[pos].tele,
					contact.data[pos].address);
				printf("Do you want to modify?(Yes:1 No:2)  ");
				scanf("%d", &input);
				switch (input)
				{
				case 2:
					break;
				case 1:
					modify_info(&contact, pos);
					break;
				default:
					printf("Invalid order\n");
				}
			}
			break;
		case 4:
			printf("Enter the name you want to modify:");
			char name2[MAX_NAME] = { 0 };
			scanf("%s", name2);
			int pos2 = search_info(&contact, name2);
			if (pos2 == -1)
			{
				printf("Not in the list.\n");
			}
			else
			{
				printf("%-5s\t%-5s\t%-3s\t%-13s\t%-20s\n",
					"NAME",
					"GENDER",
					"AGE",
					"TELE",
					"ADDRESS");
				printf("%-5s\t%-5s\t%-3d\t%-13s\t%-20s\n",
					contact.data[pos].name,
					contact.data[pos].sex,
					contact.data[pos].age,
					contact.data[pos].tele,
					contact.data[pos].address);
				modify_info(&contact, pos);
			}
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
	return 0;
}