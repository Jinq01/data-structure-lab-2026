#include "AdjMatGraph.h"
#include "srchAMGraph.h"

int main() {
	AdjMatGraph g;
	srchAMGraph s;

	for (int i = 0; i < 4; i++)
		g.insertVertex('A' + i);
	g.insertEdge(0, 1);
	g.insertEdge(0, 3);
	g.insertEdge(1, 2);
	g.insertEdge(1, 3);
	g.insertEdge(2, 3);

	printf("인접 행렬로 표현한 그래프\n");
	g.display();


	FILE* fp;
	fopen_s(&fp, "../text_out.txt", "w");
	g.display(fp);
	fclose(fp);

	for (int i = 0; i < 8; i++)
		s.insertVertex('A' + i);
	s.insertEdge(0, 1);
	s.insertEdge(0, 2);
	s.insertEdge(1, 0);
	s.insertEdge(1, 3);
	s.insertEdge(2, 0);
	s.insertEdge(2, 3);
	s.insertEdge(2, 4);
	s.insertEdge(3, 1);
	s.insertEdge(3, 1);
	s.insertEdge(3, 5);
	s.insertEdge(4, 2);
	s.insertEdge(4, 6);
	s.insertEdge(4, 7);
	s.insertEdge(5, 3);
	s.insertEdge(6, 4);
	s.insertEdge(6, 7);
	s.insertEdge(7, 4);
	s.insertEdge(7, 6);

	printf("그래프(graph.txt)\n");
	s.display();

	printf("DFS ==> ");
	s.resetVisited();
	s.DFS(0);
	printf("\n");

	return 0;
}