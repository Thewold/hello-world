#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
# define INFINITY 32767
# define MAX_VERTEX_NUM 20
typedef enum { DG, DN, UDG, UDN } Graphkind;
//相关信息结构体
typedef struct Vexs {
	int vex;
	int cdata;
}VexMatrix[MAX_VERTEX_NUM];
typedef struct ArcCell {
	int adj; //	对无权图用0和1代表是否邻接，对有权图代表权值。
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
//图（网） 的总描述，包括邻接矩阵，顶点矩阵，统计，类型
typedef struct MGraph{
	VexMatrix vexs;
	AdjMatrix arcs; //邻接矩阵
	int vexnum, arcnum;
	Graphkind kind;
}MGraph;
bool CreateGraph(MGraph& G); //选择图类型
bool CreateUDN(MGraph& G);//无向网
bool CreateDN(MGraph& G);//有向网
bool CreateUDG(MGraph& G);//无向图
bool CreateDG(MGraph& G);//有向图
int LocateVex(MGraph& G,int vex);
int FirstAdjVex(MGraph& G, int vex);
int NextAdjVex(MGraph& G, int fvex, int nvex);
void DFSTraverse(MGraph& G);
void DFS(MGraph& G, int arr);
bool PutVex(MGraph& G, int vex, int value);
int GetVex(MGraph& G, int vex);
bool DestoryGraph(MGraph& G);
int InsertVex(MGraph& G, int vex);
int DeleteVex(MGraph& G, int vex);
int InsertArc(MGraph& G, int fvex,int nvex);
int DeleteArc(MGraph& G, int fvex, int nvex);
void BFSTraverse(MGraph& G);
void printarc(MGraph& G);

//queue
typedef struct Queue {
	int* base;
	int front;
	int rear;
}Queue,*queue;

void InitQueue(Queue& Q);
int EnQueue(Queue& Q, int e);
int DeQueue(Queue& Q, int& e);
int QueueEmpty(Queue& Q);









