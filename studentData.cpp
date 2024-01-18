/*
Dylan Negvesky
Bob Myers
COP 3363
Assignment 7
Create a program that stores data about students in a dynamically allocated array of a defined "Student" structure
via file input, and creates a formatted list containing the information via file output
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

// Structure holding student information
struct Student
{
	char lastName[20];
	char firstName[20];
	char course;
	int test1;
	int test2;
	int final;
	double testAvg;
};

void openFile(ifstream&, char[]);	// Overloaded functions for attaching a file to ifstream and ofstream objects
void openFile(ofstream&, char[]);
void readIn(ifstream&, Student*, int size);	// Function reads in the data from ifstream object's file
void printOut(ofstream&, Student*, int size);	// Function prints data to ofstream object's file
char letterGradeCheck(double);			// Function checks the letter grade of a student based on their average
void classLoop(ofstream&, Student*, char, int size);	// Function takes in array of Student structures and a course to search for
							// Calculates and displays information based on this

int main()
{
	// Variables
	char inputFile[20];		// Filenames
	char outputFile[20];
	ifstream in1;			// i/o objects
	ofstream out1;
	Student * stdList = 0;		// Pointer to student object
	int sizeList = 0;		// Stores file-defined size of array

	cout << "Please enter the name of the input file.\n";
	cout << "Filename: ";
	cin >> inputFile;		// Take in user's input file name
	
	openFile(in1, inputFile);	// Call function to open file

	cout << "Please enter the name of the output file.\n";
	cout << "Filename: ";
	cin >> outputFile;		// Take in user's output file name

	openFile(out1, outputFile);	// Call function to open file

	in1 >> sizeList;			// Take in size of array from file
	stdList = new Student[sizeList];	// Dynamically allocate memory based on size

	readIn(in1, stdList, sizeList);		// Call function to read in information from input file
	
	printOut(out1, stdList, sizeList);	// Call function to print data to output file

	// Close attached files to i/o objects
	in1.close();
	out1.close();

	// Clean up dynamically allocated memory
	delete [] stdList;
	stdList = 0;

	return 0;
}

void openFile(ifstream& in1, char fileName[])
{
	in1.open(fileName);	// Attempt to open file using user's file name

	while(!in1)		// While the file name is invalid
	{
		cout << "Sorry... that file name is invalid.\n";
		cout << "Please try again: ";
		cin >> fileName;	// Take in new file name
		in1.open(fileName);	// Attempt to open again
	}

}

void openFile(ofstream& out1, char fileName[])
{
	out1.open(fileName);	// Attempt to open file using user's file name
	
	while(!out1)		// While the file name is invalid
	{
		cout << "Sorry... that file name is invalid.\n";
		cout << "Please try again: ";
		cin >> fileName;	// Take in new file name
		out1.open(fileName);	// Attempt to open again
	}

}

void readIn(ifstream& in1, Student* rcrdsList, int size)
{
	// Loop for getting information from input file
	for(int i = 0; i < size; i++)
	{
		in1.ignore();		// Ignore new line
		in1.getline(rcrdsList[i].lastName, 20, ',');	// Take in last name
		in1.getline(rcrdsList[i].firstName, 20, ',');	// Take in first name
		in1.get(rcrdsList[i].course);			// Take in course character
		in1.ignore();					// Ignore comma
		in1 >> rcrdsList[i].test1;			// Take in test 1 score
		in1.ignore();					// Ignore comma
		in1 >> rcrdsList[i].test2;			// Take in test 3 score
		in1.ignore();					// Ignore comma
		in1 >> rcrdsList[i].final;			// Take in final score
		
		// Calculate average based on defined weights of test 1, test 2, and final
		rcrdsList[i].testAvg = (static_cast<double>(rcrdsList[i].test1)*(30) + rcrdsList[i].test2*(30) + rcrdsList[i].final*(40)) / 100;
	}

}

void printOut(ofstream& out1, Student* rcrdsList, int size)
{

	// Print out Headers
	out1 << "Student Grade Summary\n";
	out1 << "---------------------\n\n";
	out1 << "ENGLISH CLASS\n\n";
	classLoop(out1, rcrdsList, 'E', size);	// Call function that displays all students in English
	out1 << "\nHISTORY CLASS\n\n";
	classLoop(out1, rcrdsList, 'H', size);	// Call function that displays all students in History
	out1 << "\nMATH CLASS\n\n";
	classLoop(out1, rcrdsList, 'M', size);	// Call function that displays all students in Math
}

void classLoop(ofstream& out1, Student* rcrdsList, char course, int size)
{
	double runningSum = 0;	// Stores a running sum of all average scores of students
	double classAvg = 0;	// Uses runningSum variable to calculate class average
	int count = 0;		// Stores the amount of students in a given class
	char tempName[40];	// Used to display student's first and last name in one output

	// Header
	out1 << "Student Name" << setw(35) << right << "Test Avg\n";
	out1 << "---------------------------------------------------------\n";

	// Output formatting
	out1 << showpoint << fixed;
	out1.precision(2);

	// Loop to filter through entire Student array
	for(int i = 0; i < size; i++)
	{
		// If a student is in the desired course
		if(rcrdsList[i].course == course)
		{
			// Create a temporary c-string that stores both the first and last name separated by a space
			strcpy(tempName, rcrdsList[i].firstName);
			strcat(tempName, " ");
			strcat(tempName, rcrdsList[i].lastName);

			out1 << setw(41) << left << tempName;				// Display name
			out1 << rcrdsList[i].testAvg << setw(4) << right;		// Display test average
			out1 << letterGradeCheck(rcrdsList[i].testAvg) << '\n';		// Display return value of called function for finding student's letter grade

			runningSum += rcrdsList[i].testAvg;	// Add student's test average to running sum
			count++;				// Increment count to show how many student's information has been recorded in output
		}
	}
	
	classAvg = runningSum / count;	// Calculate class average using running sum and counter variables 

	out1 << '\n' << setw(41) << left << "Class Average" << classAvg;		// Display class average
	out1 << "\n---------------------------------------------------------\n";

}

char letterGradeCheck(double testAvg)
{
	char letterGrade;	// Stores result of switch statement

		switch(static_cast<int>(testAvg) / 10)		// Student's test average (integer) divided by 10 (will result in an integer)
		{
			case 10:
			case 9:				// If student received a 90 or higher
				letterGrade = 'A';
				break;
			case 8:				// If student received 80-89
				letterGrade = 'B';
				break;
			case 7:				// If student received 70-79
				letterGrade = 'C';
				break;
			case 6:				// If student received 60-69
				letterGrade = 'D';
				break;
			case 5:
			case 4:
			case 3:
			case 2:
			case 1:
			case 0:				// If studen received 0-59
				letterGrade = 'F';
				break;
		}

	return letterGrade;	// Return resulting value
}
