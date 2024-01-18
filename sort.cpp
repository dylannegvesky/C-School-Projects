/* 
Dylan Negvesky
COP 3363
HW 2
Accept three user-input integers and sort from low -> high
*/

#include <iostream>
using namespace std;

int main()
{

	int input1, input2, input3;  // Variables for user input
	int high, mid, low;  // Variables for sorting input


	// Receive user inputs
	cout << "\n\nInput integer 1 : ";
	cin >> input1;
	cout << "Input integer 2 : ";
	cin >> input2;
	cout << "Input integer 3 : ";
	cin >> input3;

	if(input1 >= input2 && input1 >= input3)  // Input 1 is highest
	{
		
		high = input1;
		
		if(input2 >= input3)  // Input 2 is middle
		{
			mid = input2;
			low = input3;
		}
		else  // Input 3 is middle
		{
			mid = input3;
			low = input2;
		}
	}
	else if(input2 >= input1 && input2 >= input3)  // Input 2 is highest
	{

		high = input2;
	
		if(input1 >= input3)  // Input 1 is middle
		{
			mid = input1;
			low = input3;
		}
		else  // Input 3 is middle
		{
			mid = input3;
			low = input1;
		}
	}
	else  // Input 3 is highest
	{
		
		high = input3;

		if(input2 >= input1)  // Input 2 is middle
		{
			mid = input2;
			low = input1;
		}
		else  // Input 1 is middle
		{
			mid = input1;
			low = input2;
		}
	}

	// Output results
	cout << "\n\nSorted : " << low << " <= " << mid << " <= " << high << "\n\n";

	return 0;

}
