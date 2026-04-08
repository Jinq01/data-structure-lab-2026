#include "Car_Class.h"

void main() {
	Car mycar(10, "boong", 1);

	mycar.display();
	mycar.whereAmI();
	mycar.changeGear();
	mycar.speedUp();
	mycar.display();
}