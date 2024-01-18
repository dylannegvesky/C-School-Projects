/*
Dylan Negvesky
COP 3363
Bob Myers
Program that uses a menu system and appropriate funcitons
to allow the user to manipulate an array in multiple
different ways.

- Using code written by Bob Myers -
*/

#include <iostream>
#include <cctype>

using namespace std;

void PrintArray (const int arr[], const int size);
void FillArray(int arr[], const int size);

/* Add your own function prototypes here */

void DisplayMenu();				// Displays menu
void Insert(int[], const int, int, int);	// Inserts user designated value into designated index
void Delete(int[], const int, int);		// Deletes the value of a user designated index position
void Reverse(int[], const int);			// Reverses the order of the array
int HowMany(const int[], const int, int);	// Counts the occurances of a user designated value in the array
int SumOdds(const int[], const int, int);	// Sums the first user designated amount of odd numbers in the array

int main()
{

	const int SIZE = 15;

	int array[SIZE] = {0};
	bool invalidChoice = false;	// Allows for a separate output in cases where input was invalid
	char menuChoice;
	int newVal, userVal, amountInt, oddCount, oddSum;

	DisplayMenu();

	do
	{
		int index = 0;
		
		if(!invalidChoice)  // If choice was valid
		{
			cout << "\nEnter your menu selection: ";
			cin >> menuChoice;
			
			menuChoice = toupper(menuChoice);
		}

		invalidChoice = false;  // Reset choice to valid
		
		switch(menuChoice)
		{
			case 'P':    // If user selects print
				PrintArray(array, SIZE);
				break;
			case 'F':    // If user selects fill
				FillArray(array, SIZE);
				break;
			case 'I':    // If user selects insert
				cout << "\nWhat integer value would you like to insert? > ";
				cin >> newVal;     // Get their desired value
				cout << "What index position would you like your new value in? > ";
				cin >> index;      // Get their desired index
				Insert(array, SIZE, newVal, index);
				PrintArray(array, SIZE);
				break;
			case 'D':     // If user selects delete
				cout << "\nWhat index value would you like to erase? > ";
				cin >> index;   // Get their desired index
				Delete(array, SIZE, index);
				PrintArray(array, SIZE);
				break;
			case 'R':     // If user selects reverse
				Reverse(array, SIZE);
				PrintArray(array, SIZE);
				break;
			case 'H':     // If user selects How Many
				cout << "\nChoose a value to search the array for > ";
				cin >> userVal;     // Get the value to search for
				amountInt = HowMany(array, SIZE, userVal);
				cout << "The value " << userVal << " appears in the list " << amountInt << " times\n";   // Display result
				break;
			case 'S':     // If user selects Sum Odds
				cout << "\nHow many odd numbers would you like to add? > ";
				cin >> oddCount;     // Get the amount of odds they would like to add

				// While the input is out of range
				while(oddCount > SIZE || oddCount < 0)
				{
					cout << "Sorry, that entry is invalid...\n";
					cout << "Please try again: ";
					cin >> oddCount;    // Try again
				}

				oddSum = SumOdds(array, SIZE, oddCount);
				cout << "The sum of the first " << oddCount << " odd numbers is:  " << oddSum << '\n';	// Display result
				break;
			case 'M':     // If user selects display menu
				DisplayMenu();
				break;
			case 'Q':     // If user selects quit
				PrintArray(array, SIZE);
				break;
			default:      // If the user's entry is invalid
				cout << "\nThat entry was not valid...\n";
				cout << "Please try again: ";
				cin >> menuChoice;     // Try again

				menuChoice = toupper(menuChoice);

				invalidChoice = true;  // Skips normal prompt after invalid entry until otherwise specified
				break;
		}
		
	}while(menuChoice != 'Q');    // End loop if user selects quit

	return 0;
}

/* Add in the definitions of your own 5 functions */

// Displays the menu options
void DisplayMenu()
{
	cout << "\n\t** Given features **\n";
	cout << " P\tPrint the array contents\n";
	cout << " F\tFill the array (user entry)\n\n";
	cout << "\t** Function Tests **\n";
	cout << " I\tInsert\n";
	cout << " D\tDelete\n";
	cout << " R\tReverse\n";
	cout << " H\tHowMany\n";
	cout << " S\tSumOdds\n\n";
	cout << " M\tPrint this menu\n";
	cout << " Q\tQuit this program\n";
}

// Insert value into array
void Insert(int array[], const int SIZE, int newVal, int index)
{
	// If user index is invalid
	if(index >= SIZE)
	{
		cout << "\nIndex exceeds the limits of the array\n";
		return;    // Abort
	}
	
	// Loop moves backward through array
	for(int i = SIZE - 1; i >= index; i--)
	{
		// While i > index, move prior value up a slot
		if(i > index)
			array[i] = array[i - 1];
		// While i == index, set the value to the user's choice
		else if(i == index)
			array[i] = newVal;	
	}
}

// Delete a value from array
void Delete(int array[], const int SIZE, int index)
{
	// If user's index is out of range
	if(index >= SIZE)
	{
		cout << "\nIndex exceeds the limits of the array\n";
		return;    // Abort
	}

	// Loop moves forward through array
	for(int i = index; i <= SIZE - 1; i++)
	{
		// While i < SIZE - 1, overwrite current slot with next slot's value
		if(i < SIZE - 1)
			array[i] = array[i + 1];
		// Once i == final index, set value to 0
		else if(i == SIZE - 1)
			array[i] = 0;
	}
}

// Reverse the contents of the array
void Reverse(int array[], const int SIZE)
{
	int j = SIZE - 1;   // Start j on final index

	// For i < midpoint of array; increment i and decrement j
	for(int i = 0; i <= (SIZE / 2) + 1; i++, j--)
	{
		// If i < j, swap the values
		if(i < j)
		{
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		// If i == j, reverse has been completed
		else if(i == j)
			return;
	}
}

// Count the occurances of a designated value in the array
int HowMany(const int array[], const int SIZE, int searchVal)
{
	int valOccur = 0;  // Initialize counter

	// Parse through entire array
	for(int i = 0; i < SIZE; i++)
	{
		// If array index value == user's value
		if(array[i] == searchVal)
			valOccur++;    // Increment counter
	}	

	return valOccur;   // Return result
}

// Count the first (user designated) amount of odd numbers
int SumOdds(const int array[], const int SIZE, int amountAdd)
{
	int oddSum = 0;    // Initialize accumulator

	// For all contents of array or until user designated amount has been reached
	for(int i = 1, j = 0; i <= amountAdd && j < SIZE; j++)
	{
		// If value in array is odd
		if(array[j] % 2 != 0)
		{
			oddSum += array[j];   // Add to accumulator
			i++;   // Only increment i when odd number found
		}
	}	

	return oddSum;    // Return result
}

/* Definitions of PrintArray and FillArray below
 *  Written by Bob Myers for C++			*/

void PrintArray(const int arr[], const int size)
// this function prints the contents of the array
{
   cout << "\nThe array:\n { ";
   for (int i = 0; i < size-1; i++)	// print all but last item
      cout << arr[i] << ", ";

   cout << arr[size-1] << " }\n";	// print last item
}

void FillArray(int arr[], const int size)
// this function loads the contents of the array with user-entered values
{
   cout << "Please enter " << size 
	<< " integers to load into the array\n> ";

   for (int i = 0; i < size; i++)
	cin >> arr[i];			// enter data into array slot
}















