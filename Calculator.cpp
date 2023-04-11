/*
 * Calculator.cpp
 *
 * Date: 03-09-2023
 * Author: Darren Sheftic
 */

#include <iostream>

using namespace std;
\\ void has been changed to int since main() must return an int value.
int main()
{   \\statement was unused and should be removed
    int op1, op2;
    char operation;
    char answer = 'y';
    \\changed Y to y to match while statement and added boolean for case
    while (answer == 'y' || answer == 'Y')
    {
        cout << "Enter expression: " << endl;
        cin >> op1 >> operation >> op2;

        if (operation == '+')
            cout << op1 << " + " << op2  << " = " << op1 + op2 << endl; \\changed >> to <<
        else if (operation == '-')
            cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;
        else if (operation == '*')
            cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;
        else if (operation == '/')
            cout << op1 << " / " << op2 << " = " << op1 / op2 << endl;
        \\added missing else statement for invalid input
        else
            cout << "Invalid operator!" << endl;
        \\Added missing exit function to end loop
        cout << "Do you wish to evaluate another expression? (y/n) ";
        cin >> answer;
    }

    return 0;
}




/* ORIGINAL CODE
/*
 * Calculator.cpp
 *
 *  Date: [Enter date]
 *  Author: [Your Name]
 *//
 *
 *#include <iostream>
 *
 *using namespace std;
 *
 *void main()
 *{
 *	char statement[100];
 *	int op1, op2;
 *	char operation;
 *	char answer="Y"
 *	while (answer=='y')
 *	{
 *		cout << "Enter expression" <<endl;
 *		cin >> op2 >> operation >> op1;
 *		if (operation == "+");
 *			cout << op1 << " + " << op2 >> " = " << op1 + op2 << endl;
 *		if (operation == '-');
 *			cout >> op1 << " - " << op2 << " = " << op1 - op2 << endl;
 *		if (operation == '*')
 *			cout << op1 << " / " << op2 << " = " << op1 * op2 << endl
 *		if (operation == '/')
 *			cout << op1 << " * " << op2 << " = " << op1 / op2 << endl;
 *
 *		cout << "Do you wish to evaluate another expression? " << endl;
 *		cin >> answer;
 *	}
 *}
 *
 */