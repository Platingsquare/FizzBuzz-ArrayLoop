// Array&FizzBuzz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <sstream>
using namespace std;

// ----------- Option functions -----------
void Prime() { //Prime Number Checker
    bool again = true;// 
    while (again) {
        cout << "\n[Prime Number Checker]\n";
        cout << "This is the Prime Number Checker!\n";
        cout << "Write any number and I will tell you if it's a prime number\n";
        std::cin >> n;
        bool isPrime = true;
        if (n <= 1) isPrime = false;

        if (isPrime)
            std::cout << n << " is a prime number.\n";
        else
            std::cout << n << " is not a prime number.\n";
    }
        vector<string>
            loadfunfacts(const string & funfacts); {

        }
        cin >> again;
    }
    cout << "Do you want to check another number? (1=yes 0=no):\n";
    cin >> again;
}

void RNG() {
    bool again = true; // Play again loop
    while (again) {
        cout << "\n[Random Number Guessing Game]\n";
        srand(static_cast<unsigned int>(time(nullptr))); // seed för random
        int randomNum = rand() % 101;
        int guess = -1;

        while (true) {
            cout << "Guess the number (0-100): ";
            cin >> guess;
            if (guess == randomNum) {
                cout << "Correct! The number was " << randomNum << ".\n";
                break;
            }
            if (guess < randomNum)
                cout << "Too low!\n";
            else
                cout << "Too high!\n";
        }
        cout << "Do you want to play again? (1=yes 0=no): ";
        cin >> again;
    }
}
// Done Uppgift 2: FizzBuzz
void FizzBuzz() {
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
// Done Uppgift 3: Temperature Converter
void Temperature() {
    cout << "\n[Temperature Converter]\n";
    double temp, result;
    int choice;
    bool again = true; // C is Celsius, F is Fahrenheit, K is Kelvin
    while (again) {
        cout << "1) Celcius -> Fahrenheit\n2) Fahrenheit -> Celsius\n3) Celcius -> Kelvin\n4) Kelvin -> Celcius\n5) Fahrenheit -> Kelvin\n6) Kelvin -> Fahrenheit\n7) Back\n";
        cin >> choice;
        if (choice == 7) break;

        cout << "Enter temperature: ";
        cin >> temp;

        switch (choice) {
        case 1: result = (temp * 9 / 5) + 32; cout << result << " Fahrenheit\n"; break;
        case 2: result = (temp - 32) * 5 / 9; cout << result << " Celcius\n"; break;
        case 3: result = temp + 273.15; cout << result << " Kelvin\n"; break;
        case 4: result = temp - 273.15; cout << result << " Celcius\n"; break;
        case 5: result = (temp - 32) * 5 / 9 + 273.15; cout << result << " Kelvin\n"; break;
        case 6: result = (temp - 273.15) * 9 / 5 + 32; cout << result << " Fahrenheit\n"; break;
        default: cout << "Invalid choice.\n";
        }

        cout << "Another conversion? (1=yes 0=no): ";
        std::cin >> again;
    }
}

// Done Uppgift 1: Data - Measurments & Analysis
void option6() {
    cout << "\n[Data - Measurments & Analysis]\n";
    bool running = true;
    while (running) {
        cout << "\n[Data - Measurements & Analysis]\n";
        cout << "Choose an option:\n";
        cout << "1) Basic Statistics (mean, variance, etc.)\n";
        cout << "2) Pythagoras Theorem\n";
        cout << "3) Back to Main Menu\n";
        cout << "Enter choice: ";

        int choice;
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline

        if (choice == 1) {
            // --- Existing statistics code ---
            vector<double> values;
            string input;
            cout << "Enter the numbers you wish to measure/analyze (write 'done' to stop inputting numbers):\n";

            while (true) {
                cout << "Number #" << values.size() + 1 << ": ";
                getline(cin >> ws, input); // ws = whitespace

                if (input == "done" || input == "Done") break;

                stringstream ss(input);
                double value;
                if (ss >> value && ss.eof()) {
                    values.push_back(value);
                }
                else {
                    cout << "Won't Work! Please input a new number\n";
                }
            }

            if (values.empty()) {
                cout << "Nothing was entered\n";
                continue;
            }

    // --- Calculations ---
    double sum = 0;
    double minVal = values[0];
    double maxVal = values[0];

    for (double v : values) {
        sum += v;
        if (v < minVal) minVal = v;
        if (v > maxVal) maxVal = v;
    }

    double mean = sum / values.size();
    double variance = 0;

    for (double v : values) {
        variance += pow(v - mean, 2);
    }
    variance /= values.size();
    double stddev = sqrt(variance);

    // --- Output ---
    cout << fixed;
    cout.precision(3);
    cout << "\n=== Resultat ===\n";
    cout << "Antal värden: " << values.size() << "\n";
    cout << "Summa: " << sum << "\n";
    cout << "Medelvärde: " << mean << "\n";
    cout << "Min-värde: " << minVal << "\n";
    cout << "Max-värde: " << maxVal << "\n";
    cout << "Varians: " << variance << "\n";
    cout << "Standardavvikelse: " << stddev << "\n";

}
        else if (choice == 2) {
            // --- Pythagoras Theorem ---
            cout << "\n[Pythagoras Theorem]\n";
            cout << "Choose what to calculate:\n";
            cout << "1) Hypotenuse (given sides a and b)\n";
            cout << "2) Side a (given hypotenuse c and side b)\n";
            cout << "3) Side b (given hypotenuse c and side a)\n";
            cout << "Enter choice: ";

            int pChoice;
            if (!(cin >> pChoice)) {
                cout << "Invalid input.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            double a, b, c;

            switch (pChoice) {
            case 1:
                cout << "Enter side a: ";
                cin >> a;
                cout << "Enter side b: ";
                cin >> b;
                c = sqrt(pow(a, 2) + pow(b, 2));
                cout << "Hypotenuse (c) = " << c << "\n";
                break;

            case 2:
                cout << "Enter hypotenuse c: ";
                cin >> c;
                cout << "Enter side b: ";
                cin >> b;
                if (c <= b) { cout << "Error: c must be greater than b.\n"; break; }
                a = sqrt(pow(c, 2) - pow(b, 2));
                cout << "Side a = " << a << "\n";
                break;

            case 3:
                cout << "Enter hypotenuse c: ";
                cin >> c;
                cout << "Enter side a: ";
                cin >> a;
                if (c <= a) { cout << "Error: c must be greater than a.\n"; break; }
                b = sqrt(pow(c, 2) - pow(a, 2));
                cout << "Side b = " << b << "\n";
                break;

            default:
                cout << "Invalid choice.\n";
            }
        }

        else if (choice == 3) {
            running = false;
            cout << "Returning to main menu...\n";
        }

        else {
            cout << "Invalid choice.\n";
        }
    }
}
void option7() { //Array
    cout << "\n";
}
// Done: LED Simulation
void LED() { // LED Simulation
    cout << "\n[LED Simulation]\n";

    bool ledState = false; // false = OFF, true = ON
    bool running = true;

    while (running) {
        cout << "\n--- LED Control Menu ---\n";
        cout << "1) Toggle LED\n";
        cout << "2) Show LED state\n";
        cout << "3) Exit\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
       
        case 1:
            ledState = !ledState;
            cout << "LED toggled " << (ledState ? "ON " : "OFF ") << "\n";
            break;
        case 2:
            cout << "LED is currently " << (ledState ? "ON " : "OFF ") << "\n";
            break;
        case 3:
            running = false;
            cout << "Exiting LED simulation...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    }
}


void Exit() { //Exit
    cout << "\nGoodbye!\n";
}

// ----------- Main program -----------
int main() {
    cout << "Hello! I'm FizzBuzz-ArrayLoop.\n";
    cout << "" << endl;
    cout << "How can I be of service?\n";
    bool playing = true;
    while (playing) {
        cout << "\nMenu:\n"
            << "1) Prime Number Checker\n"
            << "2) Random Number Guessing Game\n"
            << "3) FizzBuzz\n"
            << "4) Debugging\n"
            << "5) Temperature Converter\n"
            << "6) Data - Measurments & Analysis\n"
            << "7) Array - TBD\n"
			<< "8) LED Simulation\n"
            << "9) Exit\n"
            << "Enter choice: ";

        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // rensa bufferten

        switch (choice) {
        case 1: Prime(); break;
        case 2: RNG(); break;
        case 3: FizzBuzz(); break;
        case 4: option4(); break;
        case 5: Temperature(); break;
        case 6: option6(); break;
        case 7: option7(); break;
		case 8: LED(); break;
        case 9: Exit(); playing = false; break;
        default: cout << "Invalid choice.\n"; break;
        }
    }
    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
/* void swap(int* a, int* b) { 
int temp = *a; *a = *b; *b = *temp; }
int x = 3, y = 4; 
cout << "Before swap: x=" << x << ", y=" << y << std::endl;
swap(&x,&y); 
cout << "After swap: x=" << x << ", y=" << y << std::endl; 
void setLedState(bool* led, bool state) {
    if (led) { 
        led = state;
        bool led = false; 
        setLedState(&led, true);
        cout << "LED state:" << (led ? "On" : "Off");
        Add Calculator for next time 
        Maybe try going for chess? making a chess bot? Q-Queen,K-King,B-Bishop,Kn-Knight,R-Rook,P-Pawn. int for how Q,K,B,Kn,R and P can move on a 8x8 board 
        E-engaging, A-application, R-resource, L-loader - Hello my name is Earl
        Make it not crash when letters are entered instead of numbers
		Add hint for option 2
		Add fun facts for option 1
        Make new names to replace the option names to make it more obvious for the code reader
        
        */