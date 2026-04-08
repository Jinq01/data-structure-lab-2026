#include "PolyNomial_Class.h"
void main() {
	Polynomial a, b, c;
	a.read("A ");
	b.read("B ");
	c.add(a, b);
	a.display("A = ");
	b.display("B = ");
	c.display("A + B = ");
	cout << "최고차수가 0인가? : " << boolalpha << a.isZero() << endl;
	cout << "최고차수가 0인가? : " << boolalpha << b.isZero() << endl;
	a.negate("A ");
	b.negate("B ");
}