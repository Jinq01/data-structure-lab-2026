#include "WGraphMST.h"
#include "WGraphPrim.h"
#include "WGraphDijkstra.h"

int main() {
	/*WGraphMST g;
	g.load("graphs.txt");
	printf("MST By Krukal`s Algorithm\n");
	g.Kruskal();
	return 0;*/

	WGraphPrim g;
	g.load("graph.txt");

	printf("MST By Prim'Algorithm\n");
	g.Prim(0);
	

	WGraphdijkstra g1;
	g1.load("graph_sp.txt");
	printf("Shortest Path By Dijkstra Algorithm\n");
	g1.ShortestPath(0);

	return 0;
}