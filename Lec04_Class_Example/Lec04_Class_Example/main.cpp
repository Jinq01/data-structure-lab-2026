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

	string artist_name;
	cout << "Enter the Artist Name: ";
	cin >> artist_name;

	vector<Music*> artistResult = myservice.searchByArtist(artist_name);
	if (artistResult.size() > 0) {
		cout << "Found" << artistResult.size() << " song by " << artist_name << " : " << endl;
		for (int i = 0; i < artistResult.size(); i++) {
			cout << artistResult[i]->getTitle() << endl;
		}
	}
	else {
		cout << "Not Found" << endl;
	}
	return 0;
}