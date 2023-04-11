#include <iostream>
#include <iomanip>               //For setprecision
using namespace std;

int main() {
double miles;
double dollars;

cin >> miles;
cin >> dollars;


cout << fixed << setprecision(2) << dollars/miles*20  << " ";
cout << fixed << setprecision(2) << dollars/miles*75 << " ";
cout << fixed << setprecision(2) << dollars/miles*500 << endl;
   return 0;
}
