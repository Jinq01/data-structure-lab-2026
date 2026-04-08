#pragma once
#include <iostream>
using namespace std;

class Car {
protected:
	int speed;
	char name[40];
public:
	int gear;
	Car() { }
	~Car() { }
	Car(int s, const char* n, int g)
		: speed(s), gear(g) { 
		strcpy_s(name, n);
	}
	void changeGear(int g = 4) { 
		gear = g;
	}
	void speedUp() { 
		speed += gear * 5;
	}
	void display() { 
		cout << name << ": 기어 = " << gear << "단, 속도: " << speed << endl;
	}
	void whereAmI() {
		cout << "객체 주소 = " << this << endl;
	}
};