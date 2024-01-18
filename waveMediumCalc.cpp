/*
Dylan Negvesky
COP 3363
HW 2
Allow user to choose between a medium of travel, accept a distance input,
then calculate the time it would take for a sound wave to travel through
the user's medium and across the user's distance. Program will also check
for erroneous inputs.
*/

#include <iostream>
using namespace std;

int main()
{

	// Set up constant variables for speed of sound in different mediums
	const int AIR = 1100;
	const int WATER = 4900;
	const int STEEL = 16400;

	// Variable to store user's menu choice
	char menuChoice;

	// Variables used in calculating result
	double distTrav, timeTaken;

	// Display menu for user
	cout << "\n\nWelcome to Sound Wave Calculator\n\n";
	cout << "Select the medium the sound wave will travel through.\n";
	cout << "\tA\tAir\n" << "\tW\tWater\n" << "\tS\tSteel\n\n";
	cin >> menuChoice;

	// Switch statement to evaluate user's menu choice
	// Each statement will then ask user for distance traveled
	// Calculate time taken based on inputs and store in appropriate variable
	switch(menuChoice)
	{
		// Air
		case 'A':
		case 'a':
			cout << "How far will the sound wave travel (in feet)? ";
			cin >> distTrav;
			
			timeTaken = distTrav / AIR;
			break;
		// Water
		case 'W':
		case 'w':
			cout << "How far will the sound wave travel (in feet)? ";
			cin >> distTrav;
		
			timeTaken = distTrav / WATER;
			break;
		// Steel
		case 'S':
		case 's':
			cout << "How far will the sound wave travel (in feet)? ";
			cin >> distTrav;
		
			timeTaken = distTrav / STEEL;
			break;
		// Invalid menu choice
		default:
			cout << "Illegal entry. Aborting program.\n";
			cout << "Goodbye\n";	
			return 0;
	}
	
	// Check user input for distance traveled
	if(distTrav < 0)
	{
		cout << "Distance cannot be negative.  Aborting program.\n";
		cout << "Goodbye\n";
		return 0;
	}	
	else
	{
		// Set precision of output and display results of calculation
		cout << fixed << showpoint;
		cout.precision(4);
		cout << "The sound wave will travel " << timeTaken << " seconds";
		cout << "\nGoodbye\n";
	}

	return 0;

}
