#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct arr {
	char data;
	arr* pre;
	arr* next;
}arr,*array;
void initarray(array arr);

