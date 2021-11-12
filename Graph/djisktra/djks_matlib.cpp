#include"djks_Graph.h"
void CreateUDG(Graph& G) {
	G = (Graph)malloc(sizeof(MGraph));
	if (!G) exit(-1);
	printf("please input vexnums,adjnums:\n");
	scanf_s("%d %d", &G->vexnums, &G->adjnums);
	printf("please input vexs:");
	for (int i = 0; i < G->vexnums; i++)scanf_s("%d", &G->vexs[i].vertex);
	for (int i = 0; i < G->vexnums; i++)
		for (int j = 0; j < G->vexnums; j++)
			G->adjs[i][j].adj = 0;
	for (int i = 0; i < G->adjnums; i++) {
		int v1, v2,weight,k,j;
		printf("please input from v1 to v2 with weight(0 or 1 or weight):");
		scanf_s("%d %d %d", &v1, &v2, &weight);
		k = LocateG(G, v1); j = LocateG(G, v2);
		if (k != INFINITY && j != INFINITY) {
			G->adjs[i][j].adj = weight;
			G->adjs[j][i].adj = weight;
		}
	}
}
void CreateDG(Graph& G) {
	G = (Graph)malloc(sizeof(MGraph));
	if (!G) exit(-1);
	printf("please input vexnums,adjnums:\n");
	scanf_s("%d %d", &G->vexnums, &G->adjnums);
	printf("please input vexs:");
	for (int i = 0; i < G->vexnums; i++)scanf_s("%d", &G->vexs[i].vertex);
	for (int i = 0; i < G->vexnums; i++)
		for (int j = 0; j < G->vexnums; j++)
			G->adjs[i][j].adj = INFINITY;
	for (int i = 0; i < G->adjnums; i++) {
		int v1, v2, weight, k, j;
		printf("please input from v1 to v2 with weight(0 or 1 or weight):");
		scanf_s("%d %d %d", &v1, &v2, &weight);
		k = LocateG(G, v1); j = LocateG(G, v2);
		if (k != -1 && j != -1) {
			G->adjs[k][j].adj = weight;
		}
	}
}

// return arr
int LocateG(Graph G,int vex) {
	for (int i = 0; i < G->vexnums; i++) {
		if (G->vexs[i].vertex == vex) return i;
	}
	return -1;

}
void printfG(Graph G) {
	printf("  ");
	for (int i = 0; i < G->vexnums; i++)
		printf("%d ", G->vexs[i].vertex);
	printf("\n");
	for (int i = 0; i < G->vexnums; i++) {
		printf("%d", G->vexs[i].vertex);
		for (int j = 0; j < G->vexnums; j++) {
			printf(" %d", G->adjs[i][j].adj);
		}
		printf("\n");

	}

}

void Djikstra(Graph& G,int vex1,int vex2) {
	
	int result[MAX_MATRIX_SIZE];
	for (int i = 0; i < MAX_MATRIX_SIZE; i++) result[i] = INFINITY;
	int end = LocateG(G,vex1);
	int pos = 0;
	result[0] = vex1;
	while (end != vex2 ) {
		int minv;
		// 定义 bool verx 数组，saved the numbers nextadj-vex;
		bool verx[MAX_MATRIX_SIZE];
		for (int i = 0; i < MAX_MATRIX_SIZE; i++)verx[i] = false;
		nextadjvex(G, end, verx);
		minv = minverx(G, verx, end);
		if (minv != -1) {
			result[++pos] = minv;
			end = minv;
		}
		else break;
	}
	if (end != vex2)printf("cannot create path!");
	else {
		printf("\n");
		for (int i = 0; result[i] != INFINITY; i++) {

			printf("%d", result[i]);
		}
	}
}
// to find all the nextadjvertex of the vex;
void nextadjvex(Graph& G, int vertex, bool* verx) {
	int pos = LocateG(G, vertex);
	for (int i = pos+1; i < G->vexnums; i++) {
		if (G->adjs[pos][i].adj != 0)verx[i] = true;
	}

}
// to determine the minnumber of nextadjvex;
int minverx(Graph G,bool* verx,int vex) {
	if (emptyverx(G, verx))return -1;
	int min = INFINITY;
	int minpos = -1;
	for (int i = 0; i < G->vexnums; i++) {
		if (verx[i] && G->adjs[LocateG(G, vex)][i].adj < min) {
			min = G->adjs[LocateG(G, vex)][i].adj;
			minpos = i;

		}
	}
		return minpos;
}
// to determine whether the verx array is empty or not
bool emptyverx(Graph& G,bool* verx) {
	for (int i = 0; i <G->vexnums; i++) {
		if (verx[i])return false;
	}
	return true;
}
int result[4] = {0,0,0,5};
int i = 2;
void djskG(Graph& G) {
	int d[MAX_MATRIX_SIZE];
	bool ins[MAX_MATRIX_SIZE];
	int* S = (int*)calloc(MAX_MATRIX_SIZE, sizeof(int));
	for (int i = 0; i < G->vexnums; i++) {
		d[i] = G->adjs[0][i].adj;
		ins[i] = false;
		S[i] = 0;
	}
	ins[0] = true;
	int u = 0;
	for (int i = 0; i < G->vexnums; i++) {
		int dmin = INFINITY;
		for (int j = 1; j <= G->vexnums; j++) {
			if (!ins[j] && d[j] < dmin) {
				dmin = d[j];
				u = j;
			}
		}
		ins[u] = true;

		for (int k = 0; k < G->vexnums; k++) {
			if (G->adjs[u][k].adj<INFINITY&& d[k] > d[u] + G->adjs[u][k].adj) {
				d[k] = d[u] + G->adjs[u][k].adj;
				S[k] = u;
			}

		}

	}
	printf("\n");
	for (int i = 0; i < G->vexnums; i++)
		printf("%d ", d[i] != INFINITY ?d[i]:0);
	printf("\n");
	printf("5");
	ShowP(S, 0, 5);
	printf("0");
	printf("\n");
	for (int i = 0; i < 4; i++)
		printf("%d", result[i]);
}
void ShowP(int* S,int startIndex, int endIndex)
{
	endIndex = S[endIndex];
	if (startIndex != endIndex)
	{
		result[i--] = endIndex;
		ShowP(S,startIndex, endIndex);
	}
}
//