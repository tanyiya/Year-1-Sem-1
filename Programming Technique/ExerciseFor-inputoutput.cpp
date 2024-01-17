/*
Tan Yi Ya A23CS0187 01/01/2024
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


void readFile(const string& filename, double F[], int& Data) {
    ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        cerr << "ERROR: Cannot open file\n";
        exit(1);
    }

    Data = 0;
    double value;
    while (inputFile >> value)
    {
        F[Data++] = value;
    }

    inputFile.close();
}

void computeC(const double F[], double C[], int Data)
{
    for (int i = 0; i < Data; ++i)
    {
        C[i] = (5.0 / 9.0) * (F[i] - 32);
    }
}

double average(const double array[], int Data)
{
    double sum = 0.0;
    for (int i = 0; i < Data; ++i)
    {
        sum += array[i];
    }
    return sum / Data;
}

char grade(double c)
{
    if (c >= 35.0)
        return 'H';
    else if (c < 35.0 && c >= 20.0)
        return 'M';
    else
        return 'L';
}

void writeFile(const string& filename, const double F[], const double C[], int Data)
{
    ofstream outputFile(filename);
    if (!outputFile.is_open())
    {
        cerr << "ERROR: Cannot create output file" << endl;
        exit(1);
    }
    outputFile << setw(13) << "C(Celsius)" << setw(13) << "F(Fahrenheit)" << setw(13) << "Description" << endl;
    outputFile << setw(13) << "==========" << setw(13) << "=============" << setw(13) << "===========" << endl;

    for (int i = 0; i < Data; ++i)
    {
        outputFile << fixed << setprecision(2) << setw(13) << C[i] << setw(13) << F[i] << setw(13) << grade(C[i]) << endl;
    }

    outputFile.close();
}


int main() {
    const string inputFilename = "C:/Users/Admin/Downloads/fahrenheit.txt";
    const string outputFilename = "output.txt";
    const int maxSize = 100;

    double F[maxSize];
    double C[maxSize];
    int Data;

    readFile(inputFilename, F, Data);
    computeC(F, C, Data);

    double avgC = average(C, Data);

    int High = 0, Medium = 0, Low = 0;
    for (int i = 0; i < Data; ++i) {
        char g = grade(C[i]);
        if (g == 'H') {
            High++;
        } else if (g == 'M') {
            Medium++;
        } else {
            Low++;
        }
    }

    cout << "Average of the temperature in Celsius: " << fixed << setprecision(2) << avgC << endl;
    cout << "Number of high temperature: " << High << endl;
    cout << "Number of medium temperature: " << Medium << endl;
    cout << "Number of low temperature: " << Low << endl;

    writeFile(outputFilename, F, C, Data);

    return 0;
}

/*
 C:\h\cmake-build-debug\h.exe
Average of the temperature in Celsius: 35.68
Number of high temperature: 2
Number of medium temperature: 3
Number of low temperature: 3

Process finished with exit code 0
 */

/*
output.txt
C(Celsius)F(Fahrenheit)  Description
=======================  ===========
     54.94       130.89            H
     19.86        67.75            L
     93.71       200.67            H
     13.77        56.78            L
     28.97        84.15            M
     33.60        92.48            M
     24.07        75.32            M
     16.53        61.75            L
 */