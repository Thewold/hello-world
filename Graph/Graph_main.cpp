#include"Graph.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
/*
测试用例：
Graph type:
3
vexnum and arcnum:
4 4
vex:
1 2 3 4
arc:
1 2 1
2 3 1
3 4 1
4 1 1
tips: 以下复制直接使用
3
4 4
1 2 3 4
1 2 1
2 3 1
3 4 1
4 1 1
测试用例2：
3
8 8
1 2 3 4 5 6 7 8
1 2 1
1 3 1
2 4 1
2 5 1
4 8 1
5 8 1
3 6 1
3 7 1

3
6 5
1 2 3 4 5 6
1 3 1
3 2 5
5 2 3
3 6 4
6 4 2
*/
int main(){
	int cur;
	MGraph* G  = (MGraph *)malloc(sizeof(MGraph));
	CreateGraph(*G);
	DFSTraverse(*G);
	//DeleteVex(*G, 3);
	//printf("\n");
	//DFSTraverse(*G);
	//PutVex(*G, 3, 98);
	printf("\n");
	BFSTraverse(*G);
	printf("\n");
	printf("printarc:\n");
	printarc(*G);



	return 0;
}