/* /*-------------------------------------------------------------------------------
# FP-maze.cpp | Final Project 
# 
# Purpose: 
# Reflect on our learning, gain practice in identifying key concepts from the course materials,
# Develop materials to help others understand key concepts in the course, and synthesize data structures 
# concepts learned in this course. In this program we seek to meet these objects by producing a game that 
# that allows the user to implement a deque by storing animals to the front or back of the Trailer (deque)
# in order to input the animals correctly without one eating another.
#
# Author:  Bethanie Williams, Berucha Cintron, and John Martin
#
# Created: 12/04/18
#
#------------------------------------------------------------------------------*/

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
	/* 
	A class to declare the animals and their respective categories, as well as to generate a random selection of animals and buildings
	*/
private:
	int num_animals = 0;
	vector <string> Prey_List; //creates a vector to hold the list of animals that are prey
	vector <string> Predator_List; //creates a vector to hold the list of animals that are predators
	vector <string> Neutral_List; //creates a vector to hold the list of animals that are neutral
	vector <string> Building_List; //creates a vector to hold the list of buildings 
	vector <vector<string>> Animals; // creates a vector of all the animals vectors
	
public:
	Zoo_Animals()
	{
		Predator_List = { "Lion", "Alligator", "Wolf" , "Tiger", "Snake", "Cougar", "Seal" }; //stores the predator animals
		Prey_List = { "Mouse", "Penguin", "Koala", "Chicken", "Antelope", "Zebra", "Otters" }; //stores the prey animals
		Neutral_List = { "Gorilla", "Elephant", "Panda", "Rhino", "Turtle", "Bear", "Hippopotamus" }; //stores the neutral animals
		Building_List = { "Kroger", "Laundromat", "Gas Station", "McDonalds", "Bowling Alley", "Berea Community School" }; //stores the buidings
		Animals = { Neutral_List, Prey_List, Predator_List }; //stores the all of the animals in their respective lists
	}
	int Get_Num_Animals() {
		/*
		returns what the user outputted for the number of zoo animals in game
		O(1) - no iteration being performed, just returning num_animals
		*/
		return num_animals; 	}
	void intro() { 
		/*
		this function is created to introduce the user to the game and find out how many animals will be utilized in game
		between O(1) and O(N) - O(n) because it recursively iterates until the user inputs the right number, if user does so correctly
		the first time then the Big O Notation is O(1), otherwise the function will continue to call itself until the user's input is valid
		*/
		cout << "Please enter a number between 3-21: " << endl;
		cin >> num_animals;
		
		if (num_animals < 3 || num_animals > 21) { // if user does not follow instructions, make them input a number again
			cout << "That number is invalid. Please enter a number between 3-21. " << endl;
			intro(); // uses recursion to call the function again so the user can input another number
		}
		
		// intro story
		cout << "" << endl;
		cout << "You are a zoo keeper, and your zoo has lost " << num_animals << " animals." << endl;
		cout << "You will be using a horse trailer to capture them, and it is your mission to bring them back safely to the zoo." << endl;
		cout << "" << endl;
		cout << "When picking up the animals do not let the predators near the prey, and neutral" << endl;
		cout << "animals are allowed to go wherever you need them. Do you know which are which?" << endl;
		cout << "" << endl;
		cout << "Hint: a Lion is a predator, a Mouse is a prey, and a Gorilla is neutral. " << endl;
		cout << "\n";
	}

	vector<string> randomize(int iteration) {
		/*
		creates a vector that produces a random animal, the category the animal can be found in, and
		erases the animal form the vector to make sure not to output the animal again
		O(1) - no iteration is being performed, it goes through the conditions once, there are no loops
		*/
		vector<string>current; // creates a vector to hold the animal and its category
		if (num_animals != 0) { // while there are still animals
			srand(time(NULL)); // needed for randomizing
			int randIndexVect = rand() % Animals.size(); //chooses a random vector within the Animal vector
			int randIndexEachVect = rand() % Animals[0].size();
			string current_animal = ""; // variable to hold the randomly chosen animal
			if (iteration == 0) { // if it is the first animal to be found it must be nuetral for the game to be solvable
				// below: goes within the nuetral vector and gets random index of an animal and makes 'current_animal' equal the animal
				current_animal = Animals[0][randIndexEachVect]; 
				Animals[0].erase(Animals[0].begin() + randIndexEachVect); // erases the animal from the vector
				current.push_back(current_animal);  // puts the randomly selected animal in the 'current' vector
				current.push_back("Neutral"); // since the first one should always be a neutral, it pushes its category into the 'current' vector as well 
				return current; // return the vector of the randomly selected animal and its category
			}
			else { // if it is not the first animal to be selected 
				// below: picks a random animal vector and gets random index of an animal in that vector and makes 'current_animal' equal the animal
				current_animal = Animals[randIndexVect][randIndexEachVect]; 
				Animals[randIndexVect].erase(Animals[randIndexVect].begin() + randIndexEachVect); // erases the animal from the vector
				current.push_back(current_animal);  // pushes the randomly selected animal into the 'current' vector

				// below: pushes the category of the animal based on the random vector index
				if (randIndexVect == 0) {
					current.push_back("Neutral");
				}
				else if (randIndexVect == 1) {
					current.push_back("Prey");
				}
				else if (randIndexVect == 2) {
					current.push_back("Predator");
				}
				return current; // return the vector of the randomly selected animal and its category

			}
		}
	}

	string randomize_1()
		/*
		randomly selects a building from the building vector list 
		O(1) - no iteration is performed, just simply gets a random building an outputs it
		*/
	{
		srand(time(NULL));
		int rand_Build = rand() % Building_List.size(); // chooses a random building from the building list
		return Building_List[rand_Build]; // returns random building

	}
};

class Zoo_Game {
	/*
	Main class that implements the game by outputting the randomly selected animals and buildings 
	and utilizes a deque for the user to put the animals either in the front or the back of the trailer
	to make sure that they can collect all of the animals without one eating another
	*/
private:
	deque <vector<string>> Trailer; // creates a deque to store the animals when found
	Zoo_Animals animals; // calls the Zoo_animals class to be able to use its functions


public:

	Zoo_Game(Zoo_Animals& Animals)
	{
		animals = Animals; // so we can use the Zoo_animals class in this class
	}

	//void print_trailer() {
	//	/*
	//	this function prints out the animals in the Trailer deque
	//	used for testing purposes
	//	O(n) - iterates n number of times
	//	*/
	//	for (auto vect : Trailer) {
	//		cout << vect[0] << ", ";
	//	}
	//	cout << endl;
	//}

	void User_Num_Animals() {
		/*
		calls functions from Zoo_animal class to be able to implement the finding of a 
		random animal and building and return it while also calling functions from this class
		that adds the animal onto the trailer, but if they fail, ends the game
		O(N) - iterates through the function n number of times - until "count" (the iterations) is less than the number of animals used for the game
		*/
		for (int count = 0; count < animals.Get_Num_Animals(); count++) { // while there are still animals in the game, continue
			//cout << i << endl; // testing purposes
			// below: takes the vector that the randomize function from the Zoo_animals class returns to find out what animal it picked
			vector<string> random_animal = animals.randomize(count); 
			// below: takes the random building that the randomize function from the Zoo_animals class returns
			string random_build = animals.randomize_1(); 
			/*
			below: returns a message showing what random animal was "found" and at what random building
			because random animal is a vector, we access the 0 index to be able to return the string of the animal
			*/
			//cout << "You have found a " << random_animal[0] << " in the " << random_animal[1] << " category at " << random_build << "." << endl; // testing purposes
			cout << "You have found a " << random_animal[0] << " at the " << random_build << "." << endl;
			bool game = Animal_Place(random_animal); // calls the Animal_place function below

			if (game == false) { // if the function returns false, end the game
				return;
			}

		}

	}
	bool Animal_Place(vector<string> curr_animal) { 
		/*
		main funciton and purpose of the deque
		this function allows the user to push their animal to the front or back of the deque
		however, if they push a predator and prey next to each other, they lose the game
		between O(1) and O(N) - O(n) because it recursively iterates until the user inputs either F or B, if user does so correctly
		the first time then the Big O Notation is O(1), otherwise the function will continue to call itself until the user's input is valid
		*/
		string place = ""; // variable to take in the user's response of where they wanted the animal to go (front/back)
		// below: allows the user to add to the front or back of the Trailer deque
		cout << "Where would you like to place the animal?" << endl;
		cout << "At the front(F) or at the back(B)?" << endl;
		cout << "Please type F or B." << endl;
		cin >> place; // stores the user's decision in 'place' variable
		if (place == "F") { // if the user decided to push the animal to the front of the Trailer deque
			//print_trailer(); // for testing purposes
			//cout << Trailer.size(); // for testing purposes
			if (Trailer.size() == 0) { // if there is nothing in the Trailer, there are no conflicts so just push animal to deque
				Trailer.push_front(curr_animal); // pushes animal to front of deque
			}
			else {
				//cout << Trailer[0][1]; // for testing purposes
				// below: checks if the animal that is about to be added to the deque will conflict with the first animal in the deque
				if (curr_animal[1] == "Prey" && Trailer[0][1] == "Predator") {  // if prey is added next to predator, this is a conflict
					//cout << "Trailer size " << Trailer.size() << " current animal index " << curr_animal[1] << "\n "; // testing purposes
					cout << "Uh-Oh! It looks like the " << Trailer[0][0] << " has eaten the " << curr_animal[0] << "!" << endl;
					cout << "You have failed your mission and lost your job! Game Over!" << endl;
					//cout << "place 1"; // testing purposes
					return false; // ends the game
				}
				// below: checks if the animal that is about to be added to the deque will conflict with the first animal in the deque
				else if (curr_animal[1] == "Predator" && Trailer[0][1] == "Prey") { // if predator is added next to prey, this is a conflict
					//cout << "Trailer size " << Trailer.size() << " current animal index " << curr_animal[1] << "\n "; // testing purposes
					cout << "Uh-Oh! It looks like the " << curr_animal[0] << " has eaten the " << Trailer[0][0] << "!" << endl;
					cout << "You have failed your mission and lost your job! Game Over!" << endl;
					//cout << "place 2"; // testing purposes
					return false; // ends the game
				}
				else {
					Trailer.push_front(curr_animal); // if there are no conflicts, push the animal to the front of the Trailer deque
					//print_trailer(); // testing purposes
					// below: if they are the same then there are no more animals to add and there have been no conflicts, so the user wins!
					if (animals.Get_Num_Animals() == Trailer.size()) { 
						cout << "Hooray! You have won the game! You keep your job and get to work another day." << endl;
					}
					return true; // keep playing
				}

			}
		}
		else if (place == "B") { // if the user decided to push the animal to the back of the Trailer deque
			//cout << Trailer.size(); // testing purposes
			if (Trailer.size() == 0) { // if there is nothing in the Trailer deque, there are no conflicts so just push animal to deque
				Trailer.push_back(curr_animal); // pushes animal to back of deque
			}
			else {
				// below: checks if the animal that is about to be added to the deque will conflict with the last animal in the deque
				if (curr_animal[1] == "Prey" && Trailer[Trailer.size() - 1][1] == "Predator") { // if prey is added next to predator, this is a conflict
					//cout << "Trailer size " << Trailer.size() << " current animal index " << curr_animal[1] << "\n "; // testing purposes
					cout << "Uh-Oh! It looks like the " << Trailer[Trailer.size() - 1][0] << " has eaten the " << curr_animal[0] << "!" << endl;
					cout << "You have failed your mission and lost your job! Game Over!" << endl;
					//cout << "place 3"; // testing purposes
					return false; // ends game
				}
				// below: checks if the animal that is about to be added to the deque will conflict with the last animal in the deque
				else if (curr_animal[1] == "Predator" && Trailer[Trailer.size() - 1][1] == "Prey") { // if predator is added next to prey, this is a conflict
					//cout << "Trailer size " << Trailer.size() << " current animal index " << curr_animal[1] << "\n "; // testing purposes
					cout << "Uh-Oh! It looks like the " << curr_animal[0] << " has eaten the " << Trailer[Trailer.size() - 1][0] << "!" << endl;
					cout << "You have failed your mission and lost your job! Game Over!" << endl;;
					//cout << "place 4"; // testing purposes
					return false; // ends game
				}
				else {
					Trailer.push_back(curr_animal); // if there are no conflicts, push the animal to the back of the Trailer deque
					// print_trailer(); // testing purposes
					// below: if they are the same then there are no more animals to add and there have been no conflicts, so the user wins!
					if (animals.Get_Num_Animals() == Trailer.size()) {
						cout << "Hooray! You have won the game! You keep your job and get to work another day." << endl;
					}
					return true; // keep playing
				}
			}
		}
		else {
			Animal_Place(curr_animal); // recursively iterates until the user inputs either F or B
		}
	}
	
};





int main() {
	Zoo_Animals game; // calls the Zoo_Animals constructor and uses 'game' to refer to it
	game.intro(); // runs intro function from the Zoo_Animals class
	Zoo_Game gamer(game); // calls the Zoo_Game constructor and uses 'gamer' to refer to it
	gamer.User_Num_Animals(); // runs the main function in the Zoo_Games class to implement the game 

	// for screen
	char enter;
	cin >> enter;
	return 0;
}

