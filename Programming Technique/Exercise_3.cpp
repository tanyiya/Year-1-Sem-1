#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

// Function Prototypes
void dispStatus(int activeCases);
void getInput(int& totalCases, int& newCases, int& totalDeath, int& totalRecovered);
void dispOutput(int activeCases);
double calcAverage(int totalActiveCases, int numStates);

// Function Definitions
void dispStatus(int activeCases) {
    string status;
    if (activeCases > 40)
        status = "Red zone";
    else if (activeCases >= 21)
        status = "Orange zone";
    else if (activeCases >= 1)
        status = "Yellow zone";
    else
        status = "Green zone";

    cout << left << setw(15) << "Status" << left << setw(2) << ":" << left << setw(15) << status << endl;
}

void getInput(int& totalCases, int& newCases, int& totalDeath, int& totalRecovered) {
    cout << left << setw(15) << "Total cases" << left << setw(2) << ":" << left << setw(15);
    cin >> totalCases;

    cout << left << setw(15) << "New cases" << left << setw(2) << ":" << left << setw(15);
    cin >> newCases;

    cout << left << setw(15) << "Total deaths" << left << setw(2) << ":" << left << setw(15);
    cin >> totalDeath;

    cout << left << setw(15) << "Total recovered" << left << setw(2) << ":" << left << setw(15);
    cin >> totalRecovered;
    
    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void dispOutput(int activeCases) {
    cout << setw(32) << setfill('_') << "" << endl;
    cout << setfill(' ');
    cout << setw(12) << "" << "<<<SUMMARY>>>>>" << "" << endl;
    cout << left << setw(15) << "Active cases" << left << setw(2) << ":" << left << setw(15) << activeCases << endl;
    dispStatus(activeCases);
    cout << setfill(' ');
}

double calcAverage(int totalActiveCases, int numStates) {
    return totalActiveCases / numStates;
}

int main() {
    int totalCases, newCases, totalDeath, totalRecovered;
    int highestActiveCases = 0;
    int totalActiveCases = 0;
    int numStates = 0;
    string stateName;
    string highestStateName;
    
    char repeat;
    do {
        cout << setw(32) << setfill('_') << "" << endl;
        cout << setfill(' ');
        cout << setw(12) << "" << "<<<DATA>>>>>" << "" << endl;
        cout << left << setw(15) << "State name" << left << setw(2) << ":" << left << setw(15);
        getline(cin,stateName);
		
        getInput(totalCases, newCases, totalDeath, totalRecovered);
        
		int activeCases = totalCases + newCases - totalDeath - totalRecovered;

        // Accumulating total number of active cases
        totalActiveCases += activeCases;
        
        numStates++;

        // Tracking state with the highest number of active cases
        if (activeCases > highestActiveCases) {
            highestActiveCases = activeCases;
            highestStateName = stateName;
        }
        dispOutput(activeCases);
        
        cout << "\nPress <ENTER> to continue...";
        cin.get(repeat);
    } while (repeat == '\n'); 

    cout << left << setw(15) << "Total" << left << setw(2) << ":" << left << setw(15) << totalActiveCases << endl;
    cout << left << setw(15) << "Highest" << left << setw(2) << ":" << left << setw(1) << highestActiveCases << " (" << highestStateName << ")" << endl;
    double averageActiveCases = calcAverage(totalActiveCases, numStates);
    cout << left << setw(1) << "Average for " << numStates << " states: " << averageActiveCases << endl;
    
    return 0;
}