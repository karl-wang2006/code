#define _CRT_SECURE_NO_WARNINGS
#pragma once
//定义最大容量
//姓名 性别 年龄 电话号码 住址
#define MAX_NAME 20
#define MAX_SEX 20
#define MAX_DATA 1000
#define MAX_TELE 20
#define MAX_ADDRESS 50
#define INIT_SIZE 3
#define ADD_SIZE 2
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

//通讯录内部信息
typedef struct peo_info
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char address[MAX_ADDRESS];
} peo_info;


//通讯录
// static version
//typedef struct con
//{
//	peo_info data[MAX_DATA];
//	int size;
//} con;

//malloc version
typedef struct con
{
	peo_info* data;
	int size;
	int capacity;
} con;

enum Option
{
	EXIT,
	ADD,
	DELETE,
	SREACH,
	MODIFY,
	SHOW,
	SORT,
};
//函数声明
void init_contact(con*);
//添加
void add_info(con*);

//打印信息
void show_info(const con*);

void delete_info(con*);

void modify_info(con*);

void sort_info(con*);

int search_info(con*);

int only_search(con*, char*);

void modify_info_by_idx(con*, int);

void menu();

void destructor(con*);

void Check_Memory(con*);