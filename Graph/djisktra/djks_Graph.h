#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX_MATRIX_SIZE 20
#define INFINITY  32767
typedef struct vexj {
	int vertex;
}vex[MAX_MATRIX_SIZE];
typedef struct adj {
	int adj;
}adj,adjmatrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
typedef struct MGraph {
	vex vexs;
	adjmatrix adjs;
	int vexnums;
	int adjnums;
}MGraph,*Graph;

void CreateUDG(Graph& G);
int LocateG(Graph G,int vex);
void printfG(Graph G);
void CreateDG(Graph& G);
void Djikstra(Graph& G, int vex1, int vex2);
void nextadjvex(Graph& G, int vertex, bool* verx);
int minverx(Graph G, bool* verx, int vex);
bool emptyverx(Graph& G, bool* verx);
void djskG(Graph& G);
void ShowP(int* S,int startIndex, int endIndex);


// stack
typedef struct stack {
	int base[MAX_MATRIX_SIZE];
	int pos;
};

