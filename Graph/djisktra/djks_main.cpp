#include"djks_Graph.h"
/*
6 8
0 1 2 3 4 5
0 5 100
0 4 30
0 2 10
1 2 5
2 3 50
3 5 10
4 3 20
4 5 60

6 5
1 2 3 4 5 6
1 3 1
3 2 1
5 2 1
3 6 1
6 4 1


*/
int main() {
	Graph G;
	CreateDG(G);
	printfG(G);
	printf("input start and end:");
	djskG(G);




}