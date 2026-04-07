#pragma once
#include <iostream>
using namespace std;

class Complex {
	double real, imag;

public:
	void set(double r, double i) {
		real = r;
		imag = i;
	}
	void read(const char* msg ="복소수는 =") {
		cout << msg;
		cin >> real >> imag;
	}
	void print(const char* msg = "복소수는 =") {
		cout << msg << real << " + " << imag <<"i" << endl;
	}
	void add(Complex a, Complex b) {
		real = a.real + b.real;
		imag = a.imag + b.imag;
	}
};