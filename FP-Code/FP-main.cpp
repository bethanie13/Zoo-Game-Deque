// Final Project

#include <iostream>
#include <vector>
#include <cstring>
#include <deque> 
using namespace std;

class ZooGame {
private:
	vector <string> AnimalList;
	deque <string> Horsetrailer;

public:
	ZooGame()
	{AnimalList = { "Lion", "dog", "Rabbit" };
		// Body of constructor
	}

	void intro()
	{
		cout << "You are a zoo keeper, and your zoo has lost three animals" << endl;
		cout << "you will be using a horse trailer to capture them, and bring them back safely" << endl;
		cout << "Do not let the preadators near the prey, and neutral animals are allowed to go wherever you need them" << endl;
		cout << "Lion is Preadator" << endl;
		cout << "dog is Neutral" << endl;
		cout << "Rabbit is Prey" << endl;
	}

	//void addfront()
	//{
		//Horsetrailer.push_front cin << "Your first animal is " << endl;
	//}

	//void addback()
	//{
		//Horsetrailer.push_front cin << "Your first animal is " << endl;
	//}

	//void removeback()
	//{
		//Horsetrailer.push_front cin << "Your first animal is " << endl;
	//}

	//void removefront()
	//{
		//Horsetrailer.push_front cin << "Your first animal is " << endl;
	//}

	//void add_empt-space()
	//{
		//Horsetrailer.push_front cin << "Your first animal is " << endl;
	//}

	

};

int main() {

	ZooGame Sort;
	Sort.intro();
	cout << "Change me!" << endl;

	char enter;
	cin >> enter;
	return 0;
}

