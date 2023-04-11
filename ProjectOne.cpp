#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


void clearScreen();
std::string twoDigitString(unsigned int n);
std::string nCharString(size_t n, char c);
std::string formatTime24(unsigned int h, unsigned int m, unsigned int s);
std::string formatTime12(unsigned int h, unsigned int m, unsigned int s);
void printMenu(char* strings[], unsigned int numStrings, unsigned char width);
unsigned int getMenuChoice(unsigned int maxChoice);
void displayClocks();
void addOneSecond(int i);
void addOneMinute(int i);
void addOneHour(int i);

void clearScreen() {
    for (int i = 0; i < 40; ++i) {
        cout << endl;
    }
}
std::string twoDigitString(unsigned int n) {
    if (n < 10) {
        return "0" + to_string(n);
    }
    else {
        return to_string(n);
    }
}
string nCharString(size_t n, char c) {
    return string(n, c);
}
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    string hourStr = twoDigitString(h);
    string minuteStr = twoDigitString(m);
    string secondStr = twoDigitString(s);

    return hourStr + ":" + minuteStr + ":" + secondStr;
}
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    string am_pm = (h >= 12) ? "P M" : "A M";
    if (h == 0) {
        h = 12;
    }
    else if (h > 12) {
        h -= 12;
    }
    return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " " + am_pm;
}
void printMenu() {
    cout << nCharString(27, '*') << endl;
    cout << "* 1-Add One Hour          *" << endl;
    cout << "* 2-Add One Minute        *" << endl;
    cout << "* 3-Add One Second        *" << endl;
    cout << "* 4-Exit Program          *" << endl;
    cout << nCharString(27, '*') << endl;
}
unsigned int getMenuChoice(unsigned int maxChoice) {
    unsigned int choice;
    while (true) {
        std::cin >> choice;
        if (choice >= 1 && choice <= maxChoice) {
            return choice;
        }
    }
}
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
    // Print top border
    std::cout << nCharString(27, '*') << "   " << nCharString(27, '*') << std::endl;

    // Print 12-hour clock
    std::cout << "*" << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << "*" << nCharString(3, ' ') << "*" << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << "*" << std::endl;
    std::cout << "*" << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << "*" << nCharString(3, ' ') << "*" << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << "*" << std::endl;

    // Print bottom border
    std::cout << nCharString(27, '*') << "   " << nCharString(27, '*') << std::endl;
}
void addOneSecond(int i) {
    int second = i;
    if (second < 59) {
        second++;
    }
    else {
        second = 0;
        addOneMinute(1);
    }
}
void addOneMinute(int i) {
    int minute = i;
    if (minute < 59) {
        minute++;
    }
    else {
        minute = 0;
        addOneHour(1);
    }
}

void addOneHour(int i) {
    int hour = i;
    if (hour < 23) {
        hour++;
    }
    else {
        hour = 0;
    }
}
int main() {
    int choice;

    do {
        // Clear screen
        clearScreen();
        displayClocks(12,30,0);
        // Print menu
        printMenu();

        // Get user choice
        choice = getMenuChoice(4);

        switch (choice) {
        case 1:
            // Add a second to the clock
            addOneSecond(1);
            break;
        case 2:
            // Add a minute to the clock
            addOneMinute(1);
            break;
        case 3:
            // Add an hour to the clock
            addOneHour(1);
            break;
        case 4:
            // Exit program
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

        // Wait for user to press Enter
        cout << "Press Enter to continue...";
    } while (choice != 4);

    return 0;
}