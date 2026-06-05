#include "WGraphMST.h"
int main() {
	WGraphMST g;
	g.load("graphs.txt");
	printf("MST By Krukal`s Algorithm\n");
	g.Kruskal();
	return 0;
}