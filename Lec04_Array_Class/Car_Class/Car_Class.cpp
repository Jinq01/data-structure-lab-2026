#include "Car_Class.h"

int main() {

	SportsCar mycar(10, "boong", 1, 1);

	mycar.display();
	mycar.whereAmI();
	mycar.changeGear();
	mycar.speedUp();
	mycar.display();
}