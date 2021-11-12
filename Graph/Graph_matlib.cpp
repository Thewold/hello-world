#include "Graph.h"
#define MAX 20
bool visited[MAX];
bool  CreateGraph(MGraph& G) {
	// choice GraphType
	printf("please input Gtype:\n\
0: Directed Graph\n\
1: Directed Network\n\
2: Undefined Directed Graph\n\
3: Undefined Directed Network\n");
	scanf_s("%d", &G.kind);
	switch (G.kind) {
	case DG:return CreateDG(G);
	case DN:return CreateDN(G);
	case UDG:return CreateUDG(G);
	case UDN:return CreateUDN(G);
	}
	return true;
}

bool CreateUDN(MGraph& G) {
	int incinfo;
	printf("please input vexnum,arcnum:");
	scanf_s("%d %d", &G.vexnum, &G.arcnum);
	printf("please input vertex:");
	for (int i = 0; i < G.vexnum; i++) scanf_s("%d", &G.vexs[i].vex);
	for (int i = 0; i < G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++) G.arcs[i][j] = { INFINITY };
	for (int k = 0; k < G.arcnum; k++) {
		int v1, v2, w,i,j;
		printf("please input v1 v2 with a arc before inputing 0 or 1 to w\n");
		scanf_s("%d %d %d", &v1, &v2, &w);
		i = LocateVex(G, v1); j = LocateVex(G, v2);
		G.arcs[i][j].adj = w;
		G.arcs[j][i] = G.arcs[i][j];
	}
	return true;
}//无向网
bool CreateDN(MGraph& G) {
	return true;
}//有向网
bool CreateUDG(MGraph& G) {
	return true;
}//无向图
bool CreateDG(MGraph& G) {
	return true;
}//有向图
int LocateVex(MGraph& G, int vex) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vexs[i].vex == vex)return i; //arr
	}
	return  INFINITY;
}
// 首个邻接点
int FirstAdjVex(MGraph& G, int arr) {
	int i;
	i = arr; //arr
	if (i == INFINITY){
		printf("the vertex is not here");
		exit(0);
		}
	for (int j = 0; j < G.vexnum; j++) {
		if (G.arcs[i][j].adj != INFINITY)return j; // arr
	}
	return INFINITY;
}
void DFS(MGraph& G, int arr) {
	visited[arr] = true;
	if (G.vexs[arr].vex != INFINITY)
	printf("%d", G.vexs[arr].vex);
	for (int w = FirstAdjVex(G, arr); w >= 0 && w <G.vexnum; w = NextAdjVex(G, arr, w))
		if (!visited[w]) DFS(G, w);
}
void DFSTraverse(MGraph& G) {
	
	for (int v = 0; v < G.vexnum; v++) visited[v] = false;
	for (int v = 0; v < G.vexnum; v++)
		if (!visited[v]) DFS(G, v);//arr

}
int NextAdjVex(MGraph& G, int farr, int narr) {
	for (int j = narr + 1; j < G.vexnum; j++) {
		if (G.arcs[farr][j].adj != INFINITY)return j;
	}
	return -1;
}
bool PutVex(MGraph& G, int vex, int value) {
	int i = LocateVex(G, vex);
	if (i != INFINITY)
		G.vexs[i].cdata = value;
	else return false;
	return true;
}
int GetVex(MGraph& G, int vex) {
	int i = LocateVex(G, vex);
	if (i != INFINITY)
		return G.vexs[i].cdata;
	else return 32767;
}
bool DestoryGraph(MGraph& G) {
	free(&G);
	return true;
}
int InsertVex(MGraph& G, int vex) {
	int i = G.vexnum;
	G.vexs[i].vex = vex;
	G.vexnum++;
	for (int j = 0; j < G.vexnum; j++)
		G.arcs[i][j] = { INFINITY };
	for (int j = 0; j < G.vexnum; j++)
		G.arcs[j][i] = { INFINITY };
	return 0;
}
int DeleteVex(MGraph& G, int vex) {
	int i = LocateVex(G, vex);
	G.vexs[i].vex = INFINITY;
	for (int j = 0; j < G.vexnum; j++)
		G.arcs[i][j] = { INFINITY };
	for (int j = 0; j < G.vexnum; j++)
		G.arcs[j][i] = { INFINITY };
	return 0;
}
int InsertArc(MGraph& G, int fvex, int nvex) {
	int i = LocateVex(G, fvex);
	int j = LocateVex(G, nvex);
	G.arcs[i][j].adj = G.arcs[j][i].adj = 1;

	return 0;
}
int DeleteArc(MGraph& G, int fvex, int nvex) {
	int i = LocateVex(G, fvex);
	int j = LocateVex(G, nvex);
	G.arcs[i][j].adj = G.arcs[j][i].adj = { INFINITY };
	return 0;
}
void BFSTraverse(MGraph& G) {
	Queue Q;
	InitQueue(Q);
	for (int v = 0; v < G.vexnum; v++) visited[v] = false;
		if (!visited[0]) {
			visited[0] = true;
			if(G.vexs[0].vex != INFINITY)
			printf("%d", G.vexs[0].vex);
			EnQueue(Q, 0);
			while (!QueueEmpty(Q)) {
				int u;
				DeQueue(Q, u);
				for (int w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w)) {
					if (!visited[w]) {
						visited[w] = true;
						if (G.vexs[w].vex != INFINITY)
						printf("%d", G.vexs[w].vex);
						EnQueue(Q, w);
				}
			}
	}
}
		for (int v = 0; v < G.vexnum; v++) {
			if (!visited[v])printf("%d", G.vexs[v].vex);
}
}


// queue
void InitQueue(Queue& Q) {
	Q.base = (int*)calloc(MAX, sizeof(int));
	if (!Q.base)exit(-1);
	Q.front = Q.rear = 0;

}

int EnQueue(Queue& Q, int e) {
	if ((Q.rear + 1) % MAX > MAX) {
		printf("queue is full");
		exit(0);
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAX;
	return 0;
}
int DeQueue(Queue& Q, int& e) {
	if (Q.rear == Q.front)exit(-1);
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAX;
	return 0;

}
int QueueEmpty(Queue& Q) {
	if (Q.front == Q.rear) return 1;
	return 0;
}

void printarc(MGraph& G) {
	for (int v = 0; v < G.vexnum; v++) {
		printf("   %d", G.vexs[v].vex);// ? G.vexs[v].vex != INFINITY : v + 1);
	}
	printf("\n");
	printf("\n");
	for (int ari = 0; ari < G.vexnum; ari++) {
		printf("%d  ", G.vexs[ari].vex);// ? G.vexs[ari].vex != INFINITY : ari + 1);
		for (int arj = 0; arj < G.vexnum; arj++) {
			printf("%d   ",G.arcs[ari][arj].adj ? G.arcs[ari][arj].adj != INFINITY:0);
		}
		printf("\n");
		printf("\n");
	}
}