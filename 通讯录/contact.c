#define _CRT_SECURE_NO_WARNINGS

#include"contact.h"


void show_info(const con* pc)
{
	assert(pc);
	printf("%-5s\t%-5s\t%-3s\t%-13s\t%-20s\n",
		"NAME",
		"GENDER",
		"AGE",
		"TELE",
		"ADDRESS");
	for (int i = 0; i < pc->size; i++)
	{
		printf("%-5s\t%-5s\t%-3d\t%-13s\t%-20s\n",
			pc->data[i].name,
			pc->data[i].sex,
			pc->data[i].age,
			pc->data[i].tele,
			pc->data[i].address);
	}
	printf("\n");
	printf("\n");
	printf("\n");
}

void add_info(con* pc)
{
	assert(pc);
	if (pc->size == MAX_DATA)
	{
		printf("The contact has already full.\n");
		return;
	}
	printf("please enter the name:");
	scanf("%s", pc->data[pc->size].name);

	printf("please enter the gender:");
	scanf("%s", pc->data[pc->size].sex);
	printf("please enter the age:");
	scanf("%d", &(pc->data[pc->size].age));
	printf("please enter the tele:");
	scanf("%s", pc->data[pc->size].tele);
	printf("please enter the address:");
	scanf("%s", pc->data[pc->size].address);
	pc->size++;
}

int search_info(con* pc,char des[])
{
	assert(pc);
	for (int i = 0; i < pc->size; i++)
	{
		if ((strcmp(pc->data[i].name, des) == 0))
		{
			return i;
		}
	}
	return -1;
}

void modify_info(con* pc,int pos)
{
	printf("please enter the new name:");
	scanf("%s", pc->data[pos].name);
	printf("please enter the new gender:");
	scanf("%s", pc->data[pos].sex);
	printf("please enter the new age:");
	scanf("%d", &(pc->data[pos].age));
	printf("please enter the new tele:");
	scanf("%s", pc->data[pos].tele);
	printf("please enter the new address:");
	scanf("%s", pc->data[pos].address);
	printf("changes success.\n");
}

void delete_info(con* pc)
{
	assert(pc);
	if (pc->size == 0)
	{
		printf("No info can be deleted.\n");
		return;
	}
	printf("Enter the name you want to delete:");
	char name2[MAX_NAME] = { 0 };
	scanf("%s", name2);
	int pos = search_info(pc, name2);
	if (pos == -1)
	{
		printf("Not in the list.\n");
		return;
	}
	else
	{
		for (int i = pos; i < pc->size - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->size--;
		printf("deletion success.\n");
	}
}

int cmp_by_acronym(void* e1,void* e2)
{
	if (((peo_info*)e1)->name[0] > (((peo_info*)e2)->name[0]))
	{
		return 1;
	}
	else if (((peo_info*)e1)->name[0] == (((peo_info*)e2)->name[0]))
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
void sort_info(con* pc)
{
	assert(pc);
	int(*ptr)(void*, void*) = cmp_by_acronym;
	qsort(pc->data, pc->size, sizeof(pc->data[0]), ptr);
}