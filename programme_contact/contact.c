#define _CRT_SECURE_NO_WARNINGS

#include"contact.h"

void menu()
{
	printf("******************************************\n");
	printf("*******  1.add         2.delete    *******\n");
	printf("*******  3.search      4.modify    *******\n");
	printf("*******  5.show        6.sort      *******\n");
	printf("*******  0.exit                    *******\n");
	printf("******************************************\n");
}

void Load_File(con* pc)
{
	assert(pc);
	FILE* pfile = fopen("contact.txt", "rb");
	if (NULL == pfile)
	{
		printf("No previous info.Creating contact.txt...\n");
		FILE* pfile2=fopen("contact.txt", "wb");
		if (pfile2 == NULL)
		{
			perror("Failed to create contact.txt\n"); 
			exit(EXIT_FAILURE); 
		}
		fclose(pfile2);
		pfile2 = NULL;
		return;
	}
	peo_info tmp = { 0 };
	while (1 == fread(&tmp, sizeof(peo_info), 1, pfile))
	{
		Check_Memory(pc);
		pc->data[pc->size] = tmp;
		pc->size++;
	}
	fclose(pfile);
}

void init_contact(con* pc)
{
	peo_info* ptr = (peo_info*)calloc(INIT_SIZE, sizeof(peo_info));
	if (ptr == NULL)
	{
		printf("Not enough space.\n");
		exit(EXIT_FAILURE); 
	}
	pc->data = ptr;
	ptr = NULL;
	pc->size = 0;
	pc->capacity = INIT_SIZE;
	Load_File(pc);
	printf("Initialization success!\n");
}

void show_info(const con* pc)
{
	assert(pc);
	printf("%-10s\t%-10s\t%-10s\t%-13s\t%-20s\n",
		"NAME",
		"GENDER",
		"AGE",
		"TELE",
		"ADDRESS");
	for (int i = 0; i < pc->size; i++)
	{
		printf("%-10s\t%-10s\t%-10d\t%-13s\t%-20s\n",
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

void Check_Memory(con* pc)
{
	assert(pc);
	if (pc->size == pc->capacity)
	{
		peo_info* ptr = realloc(pc->data, (pc->capacity + ADD_SIZE) * sizeof(peo_info));
		if (ptr == NULL)
		{
			perror("Check_Memory");
			exit(EXIT_FAILURE);
		}
		pc->data = ptr;
		ptr = NULL;
		pc->capacity += ADD_SIZE;
		printf("The contact has allocated.\n");
	}
}

void add_info(con* pc)
{
	Check_Memory(pc);
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

void destructor(con* pc)
{
	assert(pc);
	FILE* pfile = fopen("contact.txt", "wb");
	if (pfile == NULL)
	{
		perror("Destructor");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < pc->size; i++)
	{
		size_t num = fwrite(pc->data + i, sizeof(peo_info), 1, pfile);
		if (num != 1)
		{
			printf("Some info failed to be written.\n");
			break;
		}
	}
	printf("The info has been saved.\n");
	fclose(pfile);
	free(pc->data);
	pc->data = NULL;
	printf("The contact has freed.\n");
}

int search_info(con* pc)
{
	assert(pc);
	printf("Enter the name you want to search:");
	char name[MAX_NAME] = { 0 };
	scanf("%s", name);
	for (int i = 0; i < pc->size; i++)
	{
		if ((strcmp(pc->data[i].name, name) == 0))
		{
			printf("%-5s\t%-5s\t%-3s\t%-13s\t%-20s\n",
				"NAME",
				"GENDER",
				"AGE",
				"TELE",
				"ADDRESS");
			printf("%-5s\t%-5s\t%-3d\t%-13s\t%-20s\n",
				pc->data[i].name,
				pc->data[i].sex,
				pc->data[i].age,
				pc->data[i].tele,
				pc->data[i].address);
			return i;
		}
	}
	printf("Not in the list.\n");
	return -1;
}

int only_search(con* pc, char* name)
{
	assert(pc && name);
	for (int i = 0; i < pc->size; i++)
	{
		if ((strcmp(pc->data[i].name, name) == 0))
		{
			return i;
		}
	}
	return -1;
}

void modify_info(con* pc)
{
	printf("Enter the name you want to modify:");
	char name2[MAX_NAME] = { 0 };
	scanf("%s", name2);
	int pos2 = only_search(pc, name2);
	if (pos2 == -1)
	{
		printf("Not in the list.\n");
		return;
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
			pc->data[pos2].name,
			pc->data[pos2].sex,
			pc->data[pos2].age,
			pc->data[pos2].tele,
			pc->data[pos2].address);
	}
	printf("please enter the new name:");
	scanf("%s", pc->data[pos2].name);
	printf("please enter the new gender:");
	scanf("%s", pc->data[pos2].sex);
	printf("please enter the new age:");
	scanf("%d", &(pc->data[pos2].age));
	printf("please enter the new tele:");
	scanf("%s", pc->data[pos2].tele);
	printf("please enter the new address:");
	scanf("%s", pc->data[pos2].address);
	printf("changes success.\n");
}

void modify_info_by_idx(con* pc, int pos2)
{
	assert(pc);
	if (pos2 < 0 || pos2 >= pc->size)
	{
		printf("Invalid index.\n");
		return;
	}
	printf("please enter the new name:");
	scanf("%s", pc->data[pos2].name);
	printf("please enter the new gender:");
	scanf("%s", pc->data[pos2].sex);
	printf("please enter the new age:");
	scanf("%d", &(pc->data[pos2].age));
	printf("please enter the new tele:");
	scanf("%s", pc->data[pos2].tele);
	printf("please enter the new address:");
	scanf("%s", pc->data[pos2].address);
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
	int pos = only_search(pc,name2);
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

int cmp_by_acronym(const void* e1,const void* e2)
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
	int(*ptr)(const void*,const void*) = cmp_by_acronym;
	qsort(pc->data, pc->size, sizeof(pc->data[0]), ptr);
	printf("Sorting success.\n");
	printf("\n");
}