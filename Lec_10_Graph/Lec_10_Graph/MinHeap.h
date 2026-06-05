#pragma once
#include "HeapNode.h"
#define MAX_ELEMENT 200

class MinHeap {
	HeapNode node[MAX_ELEMENT];
	int size;
public:
	MinHeap() : size(0) { }
	bool isFull() { return size == MAX_ELEMENT - 1; }
	bool isEmpty() { return size == 0; }
	HeapNode& getParent(int i) { return node[i / 2]; }

	void insert(int key, int u, int v) {
		if (isFull()) return;
		int i = ++size;
		while (i != 1 && key < getParent(i).getkey()) {
			node[i] = getParent(i);
			i /= 2;
		}
		node[i].setkey(key, u, v);
	}

	HeapNode& remove() {
		HeapNode item = node[1];
		HeapNode last = node[size--];
		int parent = 1;
		int child = 2;
		while (child <= size) {
			if (child < size && node[child].getkey()>node[child + 1].getkey())break;
			child++;

			if (last.getkey() <= node[child].getkey())
				break;
			node[parent] = node[child];
			parent = child;
			child *= 2;
		}
		node[parent] = last;
		return item;
	}
};