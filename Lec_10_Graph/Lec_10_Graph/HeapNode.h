#pragma once
class HeapNode {
	int key;
	int v1;
	int v2;
public:
	HeapNode() : key(0), v1(' '), v2(' ') {}
	void setkey(int k, int u, int v) { key = k; v1 = u; v2 = v; }
	int getkey() { return key; }
	int getv1() { return v1; }
	int getv2() { return v2; }
};