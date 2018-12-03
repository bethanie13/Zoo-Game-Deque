// Final Project
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <deque>
#include <cstdlib>
#include <stdlib.h>
#include <random>
#include <time.h>


using namespace std;

class Zoo_Animals {
private:
	int num_animals = 0;
	vector <string> Prey_List;
	vector <string> Predator_List;
	vector <string> Neutral_List;
	vector <string> Building_List;
	vector <vector<string>> Animals;
	//deque <string> Trailer (this goes in game class);
public:
	Zoo_Animals()
	{
		Predator_List = { "Lion", "Alligator", "Wolf" , "Tiger", "Snake", "Cougar", "Seal" };
		Prey_List = { "Mouse", "Penguin", "Koala", "Chicken", "Antelope", "Zebra", "Otters" };
		Neutral_List = { "Gorilla", "Elephant", "Panda", "Rhino", "Turtle", "Bear", "Hippopotamus" };
		Building_List = { "Kroger", "Laundromat", "Gas Station", "McDonalds", "Bowling Alley", "Berea Community School" };
		Animals = { Neutral_List, Prey_List, Predator_List };
		// Body of constructor
	}
	int Get_Num_Animals() {
		return num_animals;
	}
	void intro() {
		cout << "Please enter a number between 3-21: " << endl;
		cin >> num_animals;
		cout << num_animals << endl;
		cout << "You are a zoo keeper, and your zoo has lost " << num_animals << " animals." << endl;
		cout << "You will be using a horse trailer to capture them, and it is your job to bring them back safely to the zoo." << endl;
		cout << "When picking up the animals do not let the predators near the prey, and neutral animals are allowed to go wherever you need them." << endl;
		cout << "For example a lion is a predator, a mouse is a prey, and a gorilla is neutral. " << endl;
	}

	string randomize(int iteration) {

		if (num_animals != 0) {
			srand(time(NULL));
			int randIndexVect = rand() % Animals.size();
			int randIndexEachVect = rand() % Animals[0].size();
			if (iteration == 0) {
				return Animals[0][randIndexEachVect];
			}
			else {
				return Animals[randIndexVect][randIndexEachVect];
			}
		}
	}
	string randomize_1()
	{
		srand(time(NULL));
		int rand_Build = rand() % Building_List.size();
		return Building_List[rand_Build];

	}
};

class Zoo_Game {
private:
	deque <string> Trailer; //(this goes in game class);
	//int num_animals;
	Zoo_Animals animals;

public:

	Zoo_Game(Zoo_Animals& Animals)
	{
		animals = Animals;
		//num_animals = Animals.Get_Num_Animals();
		// Body of constructor
	}


	void User_Num_Animals() {

		for (int i = 0; i < animals.Get_Num_Animals(); i++) {
			cout << i << endl;
			string random_animal = animals.randomize(i);
			string random_build = animals.randomize_1();
			cout << "You have found" << random_animal << "at" << random_build << "." << endl;
			Animal_Place();
		}

	}
	void Animal_Place() {
		string place = "";
		cout << "Where would you like to place the animal?" << endl;
		cout << "At the beginning(B) or at the end(E)?" << endl;
		cout << "Please select B or E." << endl;
		cin >> place;
		if (place == "E") {
			Trailer.push_front(//random_animal);

		}
		else if (place == "B") {
			Trailer.push_back();
		}
		else {

		}


	}

};





int main() {
	//Zoo_Animals Sort;
	//Sort.intro();
	//cout << "Change me!" << endl;
	Zoo_Animals game;
	game.intro();
	cout << game.randomize(2);
	cout << game.randomize_1(2);
	Zoo_Game gamer(game);
	gamer.User_Num_Animals();

	char enter;
	cin >> enter;
	return 0;
}


