#include"Dijkstra.h"

int main()
{
	DijkstraGraph d;
	d.Init();
	d.Dijkstra();
	d.Output();
}

/*
8
0 2 8
0 3 7
0 4 1
1 0 7
2 0 1
2 1 6
2 6 2
3 1 7
3 7 9
4 2 9
5 1 8
5 7 7
6 2 8
6 4 8
6 5 3
7 5 9
-1 -1 -1
0
*/
