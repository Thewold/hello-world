#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
# define INFINITY 32767
# define MAX_VERTEX_NUM 20
typedef enum { DG, DN, UDG, UDN } Graphkind;
//�����Ϣ�ṹ��
typedef struct Vexs {
	int vex;
	int cdata;
}VexMatrix[MAX_VERTEX_NUM];
typedef struct ArcCell {
	int adj; //	����Ȩͼ��0��1�����Ƿ��ڽӣ�����Ȩͼ����Ȩֵ��
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
//ͼ������ ���������������ڽӾ��󣬶������ͳ�ƣ�����
typedef struct MGraph{
	VexMatrix vexs;
	AdjMatrix arcs; //�ڽӾ���
	int vexnum, arcnum;
	Graphkind kind;
}MGraph;
bool CreateGraph(MGraph& G); //ѡ��ͼ����
bool CreateUDN(MGraph& G);//������
bool CreateDN(MGraph& G);//������
bool CreateUDG(MGraph& G);//����ͼ
bool CreateDG(MGraph& G);//����ͼ
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









