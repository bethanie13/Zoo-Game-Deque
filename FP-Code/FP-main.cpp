

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
		if (num_animals < 3 || num_animals > 21) {
			cout << "That number is invalid. Please enter a number between 3-21. " << endl;
			intro();
		}
		
	
		//cout << num_animals << endl;
		cout << "" << endl;
		cout << "You are a zoo keeper, and your zoo has lost " << num_animals << " animals." << endl;
		cout << "You will be using a horse trailer to capture them, and it is your job to bring them back safely to the zoo." << endl;
		cout << "" << endl;
		cout << "When picking up the animals do not let the predators near the prey, and neutral" << endl;
		cout << "animals are allowed to go wherever you need them." << endl;
		cout << "" << endl;
		cout << "For example a lion is a predator, a mouse is a prey, and a gorilla is neutral. " << endl;
	}

	vector<string> randomize(int iteration) {
		vector<string>current;
		if (num_animals != 0) {
			srand(time(NULL));
			int randIndexVect = rand() % Animals.size();
			int randIndexEachVect = rand() % Animals[0].size();
			string current_animal = "";
			if (iteration == 0) {
				current_animal = Animals[0][randIndexEachVect];
				Animals[0].erase(Animals[0].begin() + randIndexEachVect);
				current.push_back(current_animal);
				current.push_back(to_string(randIndexVect));
				return current;
			}
			else {
				current_animal = Animals[randIndexVect][randIndexEachVect];
				Animals[randIndexVect].erase(Animals[randIndexVect].begin() + randIndexEachVect);
				current.push_back(current_animal);
				current.push_back(to_string(randIndexVect));
				return current;

			}
		}
	}
	/*
	void Print_Neutral_List()
	{
		for (int i = 0; i < Neutral_List.size(); i++) {
			cout << Neutral_List[i] << " ";
		}
		cout << "\n";
	}

	void Print_Predator_List()
	{
		for (int i = 0; i < Predator_List.size(); i++) {
			cout << Predator_List[i] << " ";
		}
		cout << "\n";
	}

	void Print_Prey_List()
	{
		for (int i = 0; i < Prey_List.size(); i++) {
			cout << Prey_List[i] << " ";
		}
		cout << "\n";
	}*/

	string randomize_1()
	{
		srand(time(NULL));
		int rand_Build = rand() % Building_List.size();
		return Building_List[rand_Build];

	}
};

class Zoo_Game {
private:
	deque <vector<string>> Trailer; //(this goes in game class);
	//int num_animals;
	Zoo_Animals animals;

public:

	Zoo_Game(Zoo_Animals& Animals)
	{
		animals = Animals;
		//num_animals = Animals.Get_Num_Animals();
		// Body of constructor
	}

	void print_trailer() {
		for (auto vect : Trailer) {
			cout << vect[0] << ", ";
		}
		cout << endl;
	}

	void User_Num_Animals() {

		for (int i = 0; i < animals.Get_Num_Animals(); i++) {
			//cout << i << endl;
			vector<string> random_animal = animals.randomize(i);
			string random_build = animals.randomize_1();
			cout << "You have found a " << random_animal[0] << " at " << random_build << "." << endl; // inclde 
			bool game = Animal_Place(random_animal);

			if (game == false) {
				return;
			}

		}

	}
	bool Animal_Place(vector<string> curr_animal) {
		string place = "";
		
		cout << "Where would you like to place the animal?" << endl;
		cout << "At the front(F) or at the back(B)?" << endl;
		cout << "Please type F or B." << endl;
		cin >> place;
		if (place == "F") {
			Trailer.push_front(curr_animal);
			print_trailer();
			if (Trailer.size() > 1) {
				if (curr_animal[1] == "1" && Trailer[1][1] == "2") {
					cout << "Uh-Oh! It looks like the " << Trailer[1][0] << " has eaten the " << curr_animal[0] << "!" << endl;
					cout << "You have failed your mission and lost your job! Game Over!" << endl;
					return false;
				}
				else if (curr_animal[1] == "2" && Trailer[1][1] == "1") {
					cout << "Uh-Oh! It looks like the " << curr_animal[0] << " has eaten the " << Trailer[1][0] << "!" << endl;
					cout << "You have failed your mission and lost your job! Game Over!" << endl;
					return false;
				}
				else {
					return true;
				}
			}
			else {
				return true;
			}

		}
		else if (place == "B") {
			Trailer.push_back(curr_animal);
			print_trailer();
			if (Trailer.size() > 1) {
				if (curr_animal[1] == "1" && Trailer[Trailer.size() - 2][1] == "2") {
					cout << "Uh-Oh! It looks like the " << Trailer[Trailer.size() - 2][0] << " has eaten the " << curr_animal[0] << "!" << endl;
					cout << "You have failed your mission and lost your job! Game Over!" << endl;;
					return false;
				}
				else if (curr_animal[1] == "2" && Trailer[Trailer.size() - 2][1] == "1") {
					cout << "Uh-Oh! It looks like the " << curr_animal[0] << " has eaten the " << Trailer[Trailer.size() - 2][0] << "!" << endl;
					cout << "You have failed your mission and lost your job! Game Over!" << endl;;
					return false;
				}
				else {
					return true;
				}
			}
			else {
				return true;
			}
		}
		else {
			Animal_Place(curr_animal);
		}
		cout << "You have won the game!" << endl;
	}
	
};





int main() {
	Zoo_Animals game;
	game.intro();
	Zoo_Game gamer(game);
	gamer.User_Num_Animals(); 


	char enter;
	cin >> enter;
	return 0;
}

