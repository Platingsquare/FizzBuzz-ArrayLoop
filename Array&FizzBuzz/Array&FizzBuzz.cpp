// Array&FizzBuzz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <cmath>


int option1() {
	std::cout << "You chose option 1 \n";
	return 0;
}
int option2() {
	std::cout << "You chose option 2 \n";
	return 0;
}
int option3() {
	std::cout << "You chose option 3 \n";
	return 0;
}
int option4() {
	std::cout << "You chose option 4 \n";
	return 0;
}
int option5() {
	std::cout << "You chose option 5 \n";
	return 0;
}
int option6() {
	std::cout << "You chose option 6 \n";
	return 0;
}
int option7() {
	std::cout << "You chose option 7 \n";
	return 0;
}



int main()
{
	std::cout << "Hello! I'm FizzBuzz-ArrayLoop \n";
	int i = 1;
	int playing = 1;
	while (playing == 1) {
		std::cout << "[1] Prime Number Checker" << std::endl;
		std::cout << "[2] Random Number Guessing Game" << std::endl;
		std::cout << "[3] FizzBuzz" << std::endl;
		std::cout << "[4] Debugging" << std::endl;
		std::cout << "[5] Temperaure" << std::endl;
		std::cout << "[6] Array" << std::endl;
		std::cout << "[7] Exit" << std::endl;
		int choice;

		std::cin >> choice;

		switch (choice) {
		case 1:option1();
			//Prime Number Checker
			using namespace std;
			/*variable definition and initialization*/
			int n, i, c = 0;

			/*Get us input*/
			cout << "Enter any number n: "; cin >> n;
			/*Logik*/
		break;
		case 2:option2();
			//Random Number Guessing Game 

			std::cout << "Welcome to the number guessing game! \n";
			std::cout << "Guess the random number from 0 to 100 \n";
			int prime = 0;
			srand(static_cast<unsigned int>(time(0)));
			int randomNum = rand() % 101;
			std::cout << randomNum;

			int guess = 0;
			while (randomNum != guess) {
				std::cout << "Guess the number! ";
				std::cin >> guess;
				std::cout << "You guessed: " << guess << std::endl;
				if (guess == randomNum) {
					std::cout << "You guessed the correct number, Congrats!" << std::endl;
					//Replayability here
					std::cout << "Do you want to play again? y/n" << std::endl;
					std::string playAgain;
					std::cin >> playAgain;
					break;
					if (guess == prime) {
						std::cout << "Did you know this number is a prime number?" << std::endl;
					}
				}
				else {
					std::cout << "Try again!" << std::endl;
					std::cout << "Hint? y/n" << std::endl;
					std::string hint;
					std::cin >> hint;

					if (hint == "y" || hint == "yes") {
						if (guess < randomNum) {
							std::cout << "Number is too low, Try Agin!" << std::endl;
						}
						else if (guess > randomNum)
							std::cout << "Number is too high, Try Agin!" << std::endl;
					}

					else if (hint == "n" || hint == "no") {


					}
				}
			} // <-- Added this closing brace for the while loop
			break; // <-- Added this break for case 2
		case 3:option3();
			//FizzBuzz
			break;
		case 4:option4();
			//Debugging
			break;
		case 5:option5();
			//Temperaure
			break;
		case 6:option6();
			//Array

				//Uppgift 1: Array
				/*int arr[5] = { 1, 5, 8, 15, 21 };*/

					//-primtal check- if randomNum is prime, tell user "Did you know this number is a prime number"
			/*return 0; */
			break;
			//Exit

		case 7: {
			option7();
			std::cout << "Goodbye! \n";
			return 0;
		}
		default: {
			std::cout << "Invalid choice.\n";
			break;



			}


		}
	}
}
/*int data[] = {1, 5, 8, 15, 21};
int sum = 0;
for (int i = 0; i < 5; i++) sum += data[i];
double avg = sum / 5.0;*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
