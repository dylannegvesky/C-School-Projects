/*
Dylan Negvesky
COP 3363
HW3
Ask user to input a number of days worked, calculate how much money
they would have made if day 1 = $0.01 and everyday salary doubles.
Check for correct input and format data in neat table.
*/

#include <iostream>
using namespace std;

void DisplayMenu();

int main()
{

	int daysWorked = 0;   // User input for days worked
	double dailyPay = 0.01;     // Variable that will be adjusted based on user input
	double payTotal = 0.00;     // Variable to keep track of total sum for every cycle of loop

	// Loop to cin user's selection and verify its possibility
	do
	{
		cout << "Please enter the number of days worked: ";
		cin >> daysWorked;

		if(daysWorked <= 0)
			cout << "Invalid number of days.  Try again\n";		

	}while(daysWorked <= 0);  // Loop if user entry invalid
	
	DisplayMenu();    // Display the menu

	cout << fixed << showpoint;    // Ensure values are displayed in proper form
	cout.precision(2);

	// Loop to adjust variables according to user input
	for(int i = 0; i < daysWorked; i++)
	{
		payTotal += dailyPay;   // For every iteration of the loop, add the new daily pay to the total sum

		cout << i + 1 << "\t\t\t\t$ " << dailyPay << "\n";    // cout the result of daily pay to the menu

		dailyPay *= 2;  // Double the daily pay
	}

	cout << "\nTotal earnings: $ " << payTotal << endl;    // Display the total pay after loop ends

	return 0;

}

// Menu function
void DisplayMenu()
{

	cout << "\nDays Worked\t\t\tAmount Earned\n";
	cout << "---------------------------------------------------\n";
	
}
