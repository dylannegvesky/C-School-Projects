/* 
Dylan Negvesky
COP 3363
HW 1
Calculate the amount of paint cans necessary to paint the side of a house
*/

#include <iostream>
using namespace std;

int main()
{

	const int PAINT_COV = 400;								// Represents the amount of coverage provided by one can of paint 

	double houseWidth, houseHeight, roofHeight, windowWidth, windowHeight;			// Represents user inputs for house dimensions

	double wallArea, roofArea, windowArea, paintableArea, cansRequired;			// Represents the calculated values derived from user input

	cout << "Welcome to Paint Calculator 2023!!\n\n";					// Following lines gather data from user regarding dimensions
	cout << "How wide is the wall (in feet)? ";
	cin >> houseWidth;
	cout << "and how high is the wall to the bottom of the roof? ";
	cin >> houseHeight;
	cout << "and how high is the wall to the top of the roof? ";
	cin >> roofHeight;
	cout << "How wide is the window (in feet)? ";
	cin >> windowWidth;
	cout << "and what is the window's height? ";
	cin >> windowHeight;

	cout << "\nA side wall that is\n\t" << houseWidth << "' wide and\n\t";			// Following lines display the user inputs
	cout << houseHeight << "' tall to the roof bottom and\n\t";
	cout << roofHeight << "' tall to the roof top,\n";
	cout << "containing a window that is\n\t";
	cout << windowWidth << "' wide and\n\t";
	cout << windowHeight << "' tall,\n";

	wallArea = houseWidth * houseHeight;							// Calculates area of main side wall
	roofArea = (houseWidth * (roofHeight - houseHeight)) / 2;				// Calculates area of JUST roof
	windowArea = windowWidth * windowHeight;						// Calculates area of window

	paintableArea = wallArea + roofArea - windowArea;					// Combines necessary variables to get paintable area of house

	cansRequired = paintableArea / PAINT_COV;						// Calculates the amount of paint cans necessary for the job

	cout << fixed << showpoint;
	cout.precision(1);
	cout << "has " << paintableArea << " square feet of paintable wall\n";			// Following lines display calculated values to user
	cout.precision(2);
	cout << "and would require " << cansRequired << " cans of paint\n";
	cout << "(assuming that each can will cover " << PAINT_COV << " square feet of wall).\n\n";
	cout << "Thanks for using Paint Calculator 2023. Goodbye!!\n\n";
		
	return 0;

}
