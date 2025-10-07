// Array&FizzBuzz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

// ----------- Option functions -----------
void option1() { //Prime Number Checker
    bool again = true;// 
    while (again) {
        cout << "\n[Prime Number Checker]\n";
        cout << "This is the Prime Number Checker!\n";
        cout << "Write any number and I will tell you if it's a prime number\n";
    }
	cout << "Do you want to check another number? (1=yes 0=no):\n";
	cin >> again;
}
void option2() {
	bool again = true; // Play again loop
    while (again) {
        cout << "\n[Random Number Guessing Game]\n";
        srand(static_cast<unsigned int>(time(nullptr))); //Det här är en seed för numret läspå mer
        int randomNum = rand() % 101;
        int guess = -1;

        while (true) {
            cout << "Guess the number (0-100): ";
            cin >> guess;
            if (guess == randomNum) {
                cout << "Correct! The number was " << randomNum << ".\n";
                break;
            }//Add back hint feature asking here
            if (guess < randomNum)
                cout << "Too low!\n";
            else
                cout << "Too high!\n";
        }
		cout << "Do you want to play again? (1=yes 0=no): ";
        cin >> again;
    }
}
void option3() {
	// Function for option 3: FizzBuzz
    cout << "\n[FizzBuzz]\n";
    for (int i = 1; i <= 100; ++i) {
        if (i % 15 == 0) cout << "FizzBuzz\n";
        else if (i % 3 == 0) cout << "Fizz\n";
        else if (i % 5 == 0) cout << "Buzz\n";
        else std::cout << i << "\n";
    }
}

void option4() {
    cout << "\n[Debugging]\nThis section can be used for testing.\n";
}

void option5() {
    cout << "\n[Temperature Converter]\n";
    double temp, result;
    int choice;
	bool again = true; // C is Celsius, F is Fahrenheit, K is Kelvin
    while (again) {
        cout << "1) C → F\n2) F → C\n3) C → K\n4) K → C\n5) F → K\n6) K → F\n7) Back\n";
        cin >> choice;
        if (choice == 7) break;

        cout << "Enter temperature: ";
        cin >> temp;
        switch (choice) {
        case 1: result = (temp * 9 / 5) + 32; cout << result << " °F\n"; break;             // Celsius to Fahrenheit 
        case 2: result = (temp - 32) * 5 / 9; cout << result << " °C\n"; break;             // Fahrenheit to Celcius
        case 3: result = temp + 273.15; cout << result << " K\n"; break;                    // Celcius to Kelvin  
        case 4: result = temp - 273.15; cout << result << " °C\n"; break;                   // Kelvin to Celcius
        case 5: result = (temp - 32) * 5 / 9 + 273.15; cout << result << " K\n"; break;     // Fahrenheit to Kelvin
        case 6: result = (temp - 273.15) * 9 / 5 + 32; cout << result << " °F\n"; break;    // Kelvin to Fahrenheit
        default: cout << "Invalid choice.\n";
			// If it's below 5°C || 41°F || 278K, print "It's getting cold now"
			// if it's below 0°C || 32°F || 273K, print "It's freezing"
			// if it's below -20°C || -4°F || 253K, print "Classic Swedish Winter"
			// if it's below -40°C || -40°F || 233K, print "Did you know penguins only live on the southern hemosphere of the globe"
			// if it's below -100°C || -148°F || 173K, print "Are we out in space?"
			// if it's between -273.15°C and -40°C || -459.67°F and -40°F || 0K and 233K, print "Hell has froozen over"
			// if it's at -273.15°C || -459.67°F || 0K, print "This is absolute zero!"
			// if it's between 0°C and 20°C || 32°F and 68°F || 273K and 293K, print "It's a bit chilly."
			// If it's above 20°C || 68°F || 293K, print "Nice weather we're having today :)"
			// if it's above 30°C || 86°F || 303K, print "It's hot as balls!"
			// if it's above 100°C || 212°F || 373K, print "It's boiling now"
        }
        cout << "Another conversion? (1=yes 0=no): ";
        std::cin >> again;
    }
}


void option6() { //Databehandling 
    cout << "Calculator build in progress"; {
    }//  int number = std:: 101;
        /* if (choice > 8)
        cout << "Welcome to our local Calculator, what do you need?";
        cout << "1) Basic Algebra\n2) Median Calculation\n3) Varians\n4) Max of Three\n5) Pythagorean Theory\n6) Graph / Statistics";
        switch (choice) {
        case 1:
        case 2: float average(float a, float b)
        case 3:ex 3 + 4 + 5 = 12, t = 12 12 / 3 4, 4 = m, (3 - 4) ^ 2 =
        case 4: (float a, float b, float c)
        case 5: a^2 + b^2 = c^2 || a*a + b*b = c*c sqrt a^2 = a
        case 6: add numbers, when done they will be shown in visuell representation
        */
}

    


void option7() { //Array
        cout << "\n";
}


void option8() { //Exit
    cout << "\nGoodbye!\n";
}

// ----------- Main program -----------
int main() {
    cout << "Hello! I'm FizzBuzz-ArrayLoop.\n";
	cout << "" << endl; //giving space between lines
	cout << "How can I be of service?\n";
    bool playing = true;
    while (playing) {
        cout << "\nMenu:\n"
            << "1) Prime Number Checker\n"
            << "2) Random Number Guessing Game\n" //almost done
            << "3) FizzBuzz\n" //Done
            << "4) Debugging\n"
            << "5) Temperature\n"//almost done
            << "6) --Data-- TBD\n"
			<< "7) Array - TBD\n"
            << "8) Exit\n" //Done
            << "Enter choice: ";

        int choice;
        cin >> choice;
        switch (choice) {
        case 1: option1(); break;
        case 2: option2(); break;
        case 3: option3(); break;
        case 4: option4(); break;
        case 5: option5(); break;
        case 6: option6(); break;
		case 7: option7(); break;
        case 8: option8(); playing = false; break;
        default: cout << "Invalid choice.\n"; break; //add if playing = false insert cout << "A random qoute or fact"
        }
    }
    return 0;
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


/* void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = *temp;
}
int x = 3, y = 4;
cout << "Before swap: x=" << x << ", y=" << y << std::endl;
swap(&x,&y);
cout << "After swap: x=" << x << ", y=" << y << std::endl;
void setLedState(bool* led, bool state) {
    if (led) {
        *led = state;
        * 
        * 
        * bool led = false;
        * setLedState(&led, true);
        * cout << "LED state:" << (led ? "On" : "Off");
        * 
        * Add Calculator for next time
        * Maybe try going for chess? making a chess bot? Q-Queen,K-King,B-Bishop,Kn-Knight,R-Rook,P-Pawn. int for how Q,K,B,Kn,R and P can move on a 8x8 board
*/