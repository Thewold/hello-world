#include"BSTree.h"
void initarray(array arr) {
	char c;
	array T; //ÁÙÊ±½Úµã
	arr = (array)malloc(sizeof(arr));
	arr->next = (array)malloc(sizeof(arr));
	if (!arr || !arr->next) exit(0);
	arr->pre = NULL;
	arr->data = NULL;
	T = arr->next;
	T->pre = arr;
	T->next = NULL;
	scanf_s("%c", &c);
	T->data = c;
	while (true) {
		scanf_s("%c", &c);
		if (c == '@')break;
		if (c == '#') {
			T = T->next;
			continue;
		}
		else {
			if (c > (int)T->data) {

			}
		}
	}
}