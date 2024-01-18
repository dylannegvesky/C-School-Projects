/*
Dylan Negvesky
COP 3363
HW 3
Allow the user to enter as many integers as they please.
While loop is running, track statistics about numbers being entered.
Allow user to exit with input of a sentinel.
*/

#include <iostream>
using namespace std;

int main()
{
	int userValue;    // Stores and updates users input every cycle of loop
	double numEntries = 0.00;     // Variables for keeping track of statistics about user inputs
	double sumEntries = 0.00; 
	int numDivis;
	int maxValue = 0; 
	int minValue = 0;    
	double avgEntries;    // Stores calculated average of user inputs

	cout << endl;	

	// Loop that will continue until user enters sentinel value
	do
	{
		cout << "Input integer (0 to stop): ";
		cin >> userValue;
		
		if(userValue != 0)    // If user does not enter sentinel value
		{
			numEntries++;  // Increment the number of user entries

			sumEntries += userValue;   // Add user's value to sum
			avgEntries = sumEntries / numEntries;     // Calculate sum using previous data

			if(userValue % 9 == 0)   // If user's value is divisible by 9
				numDivis++;      // Increment the variable that stores number of values divisible by 9

			if(userValue > maxValue)      // If user's value is greater than current max value
				maxValue = userValue; // Set new max value
			else if(userValue < minValue) // If user's value is smaller than current min value
				minValue = userValue; // Set new min value
		}
			
	}while(userValue != 0);  // Continue until user enters 0

	// Display the calculated variables
	cout << "\nTotal: " << numEntries << "\n";
	cout << "Sum: " << sumEntries << "\n";
	cout << fixed << showpoint;
	cout.precision(2);
	cout << "Average: " << avgEntries << "\n";
	cout << "Divisible by 9: " << numDivis << "\n";
	cout << "Max: " << maxValue << "\n";
	cout << "Min: " << minValue << "\n";


	return 0;
}
