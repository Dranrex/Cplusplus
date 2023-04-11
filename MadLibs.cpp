#include <iostream>
#include <string>
using namespace std;

int main() {

    string userString;

    while (userString != "quit") {
        //Enter a string (or 'quit' to exit)
        cin >> userString ;
        
      if (userString == "quit") {
            break;
        }

        
        int userInt;
        //Enter an integer
        cin >> userInt;

        //Print the output sentence
        cout << "Eating " << userInt << " " << userString << " a day keeps you happy and healthy." << endl;
    }

    return 0;
}