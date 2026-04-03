#include "Rectangle.h"
#include "Pet.h"
#include "Music.h"
using namespace std;

int main()
{
	//Rectangle 1 객체 생성
	Rectagle rect1(3.4, 2.5);
	cout << "Rectagle 1:" << endl;
	//printf("Rectanle 1:\n");
	cout << "Area:" << rect1.getArea() << endl;
	//printf("Area: %lf", rect1.getArea());
	cout << "perimeter: " << rect1.getPerimeter() << endl;
	cout << "Is square ? : " << boolalpha << rect1.isSquare() << endl;
	printf("========================\n");

	Pet mypet("kong", 5, "Dog");
	cout << "" << mypet.getName() << endl;
	Puppy mypuppy("Lucky", 10, "Dog", "Puddle");
	cout << "" << mypuppy.getBread() << endl;
	printf("========================\n");

	MusicStreamingService myservice("spotify");
	myservice.addMusic("Sign of the time", "Harry", "Frist", 2023);
	myservice.addMusic("Hello", "ME", "School", 2026);
	myservice.addMusic("Fire", "BTS", "Mola", 2020);
	//Title로 검색
	string music_title;
	cin >> music_title;
	//scanf_s("%s", &music_title);
	Music* result = myservice.searchByTitle(music_title);
	if (result != NULL) {
		cout << "Found: " << result->getTitle() << " by " << result->getArtist() << endl;
	}
	else {
		cout << "Not Found" << endl;
	}
}