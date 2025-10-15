// Array&FizzBuzz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <algorithm>
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

//Graph 

void printbarGraph(const std::vector<double>& values) {
    if (values.empty()) return;
    double maxVal = *max_element(values.begin(), values.end());
    cout << "\nBar Graph:\n";
    for (size_t i = 0; i < values.size(); ++i) {
        cout << "Value #" << i + 1 << " (" << values[i] << "): ";
        int barLength = static_cast<int>((values[i] / maxVal) * 50); // scale to max 50 chars
        for (int j = 0; j < barLength; ++j) cout << '#';
        cout << "\n";
    }
}

// ----------- Functions -----------
void Prime() { //Prime Number Checker
    bool again = true;
    while (again) {
        cout << "\n[Prime Number Checker]\n";
        cout << "This is the Prime Number Checker!\n";
        cout << "Write any number and I will tell you if it's a prime number\n";
        int n;
        while (!(cin >> n)) {
            cout << "Invalid input. Please enter a valid integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        bool isPrime = true;
        if (n <= 1) isPrime = false;
        else {
            for (int i = 2; i <= sqrt(n); ++i) {
                if (n % i == 0) {
                    isPrime = false;
                    break;
                }
            }
        }
        if (isPrime)
            cout << n << " is a prime number.\n";
        else
            cout << n << " is not a prime number.\n";
        cout << "Check another number? (1=yes 0=no): ";
        cin >> again;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
   
}

void guessingGame() {
    bool again = true; // Play again loop
    while (again) {
        cout << "\n[Random Number Guessing Game]\n";
        srand(static_cast<unsigned int>(time(nullptr))); // seed for random number generator
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
void fizzBuzz() {
    // Function for option 3: FizzBuzz
    cout << "\n[FizzBuzz]\n";
    for (int i = 1; i <= 100; ++i) {
        if (i % 15 == 0) cout << "FizzBuzz\n";
        else if (i % 3 == 0) cout << "Fizz\n";
        else if (i % 5 == 0) cout << "Buzz\n";
        else std::cout << i << "\n";
    }
}

void Debugging() {
    cout << "\n[Debugging]\nThis section can be used for testing.\n";
}
// Done Uppgift 3: Temperature Converter
void temperatureConverter() {
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

int findValue(vector<double>& values, int value) { 
    int index = -1;     // -1 means we haven't found a value

    for (int i = 0; i < values.size(); i++) {
        int currentValue = static_cast<int>(values[i]);
        if (currentValue == value) {
            index = i;
            break;
        }
            
    }


    return index;
}


// Done Uppgift 1: Data - Measurments & Analysis
void dataAnalysis() {

    cout << "\n[Data - Measurments & Analysis]\n";
    bool running = true;
    vector<double> values;
    while (running) {
        //Printing Menu
        cout << "\n[Data - Measurements & Analysis]\n"
         << "Choose an option:\n"
         << "1) Basic Algebra (mean, variance, etc.)\n"
         << "2) Graph\n"
         << "3) Find Value\n"
         << "4) Back to Main Menu\n"
         << "Enter choice: ";

        //Accepting Input
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
            vector<double> values;
            string input;
            cout << "Enter the numbers to graph (write 'done' to stop inputting numbers):\n";
            while (true) {
                cout << "Number #" << values.size() + 1 << ": ";
                getline(cin >> ws, input);
                if (input == "done" || input == "Done") break;
                stringstream ss(input);
                double value;
                if (ss >> value && ss.eof()) {
                    values.push_back(value);
                }
                else {
                    cout << "Invalid input! Please input a new number\n";
                }
            }
            if (values.empty()) {
                cout << "Nothing was entered\n";
                continue;
            }
            printbarGraph(values);
        }
        else if (choice == 3) {
            cout << "Enter A Value to Find (0-100): ";
            int entry = -1;
            cin >> entry;
            int result = findValue(values, entry); 
            cout << "Found Value at: " << result << "\nEnter done to go back"; 
            string done;
            cin >> done;
        }
        else if (choice == 4) {
            running = false;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }
}


void Array() { //Array
    cout << "\n[Array Swaper]\n";
    void Array(); {
        cout << "\n[Array Swap Example]\n";
        int arr[5] = { 1, 2, 3, 4, 5 };
        cout << "Original array: ";
        for (int i = 0; i < 5; ++i) cout << arr[i] << " ";
        cout << endl;

        // Swap first and last element
        int temp = arr[0];
        arr[0] = arr[4];
        arr[4] = temp;

        cout << "After swap (first and last): ";
        for (int i = 0; i < 5; ++i) cout << arr[i] << " ";
        cout << endl;
    }
}

// Done: LED Simulation
void toggleLED() { // LED Simulation
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
            cout << "Toggle LED " << (ledState ? "ON " : "OFF ") << "\n";
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


void exitProgram() { //Exit
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
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        switch (choice) {
        case 1: Prime(); break;
        case 2: guessingGame(); break;
        case 3: fizzBuzz(); break;
        case 4: Debugging(); break;
        case 5: temperatureConverter(); break;
        case 6: dataAnalysis(); break;
        case 7: Array(); break;
		case 8: toggleLED(); break;
        case 9: exitProgram(); playing = false; break;
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
  
        I need to eventually make seperate files to make it more readable and seperate the different things
        Add Calculator for next time 
        Make it not crash when letters are entered instead of numbers
        */