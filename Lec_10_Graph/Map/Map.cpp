#include "Location2D.h"
#include <stack>
#include <deque>
#include <iostream>

using namespace std;

const int MAZE_SIZE = 6;
char map[MAZE_SIZE][MAZE_SIZE];
char original_map[MAZE_SIZE][MAZE_SIZE] = {
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'},
};

void resetMap() {
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++) {
			map[i][j] = original_map[i][j];
		}
	}
}

bool isValidLoc(int r, int c)
{
	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE) return false;
	else return map[r][c] == '0' || map[r][c] == 'x';
}

int main() {

	int ds_num;
	printf("DFS 데이터 구조 라이브러리 선택: 1)stack, 2)deque \n");
	scanf_s("%d", &ds_num);

	stack<Location2D>  locStack;
	deque<Location2D>  locDeque;
	Location2D entry(1, 0);
	bool success = false;
	resetMap();

	printf("\n[1단계: 선택한 자료구조 탐색 결과]\n");
	switch (ds_num) {
	case 1:
		locStack.push(entry);
		while (locStack.empty() == false) {
			Location2D here = locStack.top();
			locStack.pop();

			int r = here.row, c = here.col;
			printf("(%d,%d) ", r, c);
			if (map[r][c] == 'x') {
				success = true;
				printf(" 미로 탐색 성공\n");
				break;
			}
			else {
				map[r][c] = '.';
				if (isValidLoc(r - 1, c))locStack.push(Location2D(r - 1, c));
				if (isValidLoc(r + 1, c))locStack.push(Location2D(r + 1, c));
				if (isValidLoc(r, c - 1))locStack.push(Location2D(r, c - 1));
				if (isValidLoc(r, c + 1))locStack.push(Location2D(r, c + 1));
			}
		}
		if (!success) printf("미로 탐색 실패\n");

	case 2:
		locDeque.push_back(entry);
		while (locDeque.empty() == false) {
			Location2D here = locDeque.front();
			locDeque.pop_front();

			int r = here.row, c = here.col;
			printf("(%d,%d) ", r, c);
			if (map[r][c] == 'x') {
				success = true;
				printf(" 미로 탐색 성공\n");
				break;
			}
			else {
				map[r][c] = '.';
				if (isValidLoc(r - 1, c))locDeque.push_back(Location2D(r - 1, c));
				if (isValidLoc(r + 1, c))locDeque.push_back(Location2D(r + 1, c));
				if (isValidLoc(r, c - 1))locDeque.push_back(Location2D(r, c - 1));
				if (isValidLoc(r, c + 1))locDeque.push_back(Location2D(r, c + 1));
			}
		}
		if (!success) printf("미로 탐색 실패\n");
	}

	while (!locStack.empty()) locStack.pop();
	locDeque.clear();
	resetMap();
	success = false;
	printf("\n[2단계: Stack과 Deque(Queue 방식) 차례대로 자동 출력]\n");

	printf(" Stack 탐색 과정: ");
	locStack.push(entry);
	bool stack_success = false;
	while (locStack.empty() == false) {
		Location2D here = locStack.top();
		locStack.pop();

		int r = here.row, c = here.col;
		printf("(%d,%d) ", r, c);
		if (map[r][c] == 'x') {
			printf(" 미로 탐색 성공\n");
			success = true;
			break;
		}
		else {
			map[r][c] = '.';
			if (isValidLoc(r - 1, c))locStack.push(Location2D(r - 1, c));
			if (isValidLoc(r + 1, c))locStack.push(Location2D(r + 1, c));
			if (isValidLoc(r, c - 1))locStack.push(Location2D(r, c - 1));
			if (isValidLoc(r, c + 1))locStack.push(Location2D(r, c + 1));
		}
	}
	if (!success) printf("미로 탐색 실패\n");

	resetMap();
	success = false;
	printf(" Deque 탐색 과정: ");
	locDeque.push_back(entry);
	bool deque_success = false;
	while (locDeque.empty() == false) {
		Location2D here = locDeque.front();
		locDeque.pop_front();

		int r = here.row, c = here.col;
		printf("(%d,%d) ", r, c);
		if (map[r][c] == 'x') {
			success = true;
			printf(" 미로 탐색 성공\n");
			break;
		}
		else {
			map[r][c] = '.';
			if (isValidLoc(r - 1, c))locDeque.push_back(Location2D(r - 1, c));
			if (isValidLoc(r + 1, c))locDeque.push_back(Location2D(r + 1, c));
			if (isValidLoc(r, c - 1))locDeque.push_back(Location2D(r, c - 1));
			if (isValidLoc(r, c + 1))locDeque.push_back(Location2D(r, c + 1));
		}
	}
	if (!success) printf("미로 탐색 실패\n");

	return 0;
}