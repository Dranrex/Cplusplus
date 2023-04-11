#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Open the input file for reading
    ifstream inFile("FahrenheitTemperature.txt");
    if (inFile.fail()) {
        cout << "Unable to open file FahrenheitTemperature.txt" << endl;
        exit(1);   // call system to stop
    }

    // Open the output file for writing
    ofstream outFile("CelsiusTemperature.txt");
    if (outFile.fail()) {
        cout << "Unable to open file CelsiusTemperature.txt" << endl;
        exit(1);   // call system to stop
    }

    // Read data from input file, convert to Celsius, and write to output file
    string city;
    int fahrenheitTemp;
    while (inFile >> city >> fahrenheitTemp) {
        double celsiusTemp = (fahrenheitTemp - 32) * (5.0/9.0);
        outFile << city << " " << celsiusTemp << endl;
    }

    // Close both files
    inFile.close();
    outFile.close();

    return 0;
}
