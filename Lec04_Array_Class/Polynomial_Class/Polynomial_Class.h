#pragma once
#include <iostream>
#define MAX_DEGREE 80 // 다항식의 처리 가능한 최대 차수+1
using namespace std;

class Polynomial {
	int degree; // 다항식의 최고 차수
	float coef[MAX_DEGREE]; // 각 항에 대한 계수
public:
	Polynomial() { degree = 0; } 

	void read(const char* str = " Poly = ") {
		cout << str << "다항식의 최고 차수를 입력:";
		cin >> degree;
		cout << "각 항의 계수를 입력하시오 (총 " << degree + 1 << "개)" << endl;
		for (int i = 0; i <= degree; i++)
			cin >> coef[i];
	};
	void display(const char* str = " Poly = ") { 
		cout << str ; 
		for (int i = 0; i < degree; i++) {
			cout << coef[i] << "x^" << degree - i << " + ";
		}
		cout << coef[degree] << endl;
	};
	void add(Polynomial a, Polynomial b) {
		if (a.degree > b.degree) { 
			*this = a;
			for (int i = 0; i <= b.degree; i++)
				coef[i + (degree - b.degree)] += b.coef[i];
		}
		else { 
			*this = b;
			for (int i = 0; i <= a.degree; i++)
				coef[i + (degree - a.degree)] += a.coef[i];
		}
	}
	bool isZero() { 
		if (coef[0] == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	void negate(const char* str = " Poly = ") {
		for (int i = 0; degree >= i ; i++) {
			if (coef[i] == 0) {
				coef[i] = 0;
			}
			else {
				coef[i] = -coef[i];
			}
			cout << degree - i << "차의 바뀐 계수: " << coef[i] << " ";
		}
		cout << endl;
	}
};