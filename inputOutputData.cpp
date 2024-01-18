/*
Dylan Negvesky
COP 3363
Bob Myers
Write a program that allows the user to input the name of a text file,
check if the file is openable, read the contents of the file and store data,
and write the information to an output file.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>

using namespace std;

void fileCheck(ifstream&, char[]);      // Input file check
void fileCheck(ofstream&, char[]);	// Output file check
void statCheck(ifstream&, int&, int&, int&, int&, int&, int&, int&, int&, int&, int[], char[]);			// Read through input file and record data
void outputFile(ofstream&, int&, int&, int&, int&, int&, int&, int&, int&, int&, int[], char[], char[]); 	// Output results to file

int main()
{
	// File stream objects

	ifstream userTxt;
	ofstream txtStats;

	// File name arrarys
	char userInFile[30];
	char userOutFile[30];

	// Counter variables
	int charCount = 0, letterCount = 0, digitCount = 0, spaceCount = 0, otherCount = 0, 
	intCount = 0, upperCount = 0, lowerCount = 0, intSum = 0; 
	int alphabetCount[26] = {0};
	
	// Alphabet array
	char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
	'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	
	// Open input file and attach
	fileCheck(userTxt, userInFile);

	// Open output file and attach
	fileCheck(txtStats, userOutFile);

	// Read through file and record data
	statCheck(userTxt, charCount, letterCount, spaceCount, digitCount,
	otherCount, upperCount, lowerCount, intCount, intSum, alphabetCount, alphabet);

	// Print results to output file
	outputFile(txtStats, charCount, letterCount, spaceCount, digitCount,
	otherCount, upperCount, lowerCount, intCount, intSum, alphabetCount, alphabet, userInFile);
	
	// Close files before ending program
	userTxt.close();
	txtStats.close();

	return 0;
}


// OPENS INPUT FILE AND VERIFIES SUCCESS
void fileCheck(ifstream& userTxt, char userInFile[])
{
	cout << "Please enter the name of the input file.\n";
	cout << "Filename:  ";
	cin >> userInFile;

	// Attempt to open user's file name
	userTxt.open(userInFile);

	// While file cannot be opened
	while(!userTxt)
	{
		cout << "Sorry, the file could not be found...\n";
		cout << "Please try again:  ";
		cin >> userInFile;

		// Attempt again
		userTxt.open(userInFile);
	}
} 


// OPENS OUTPUT FILE AND VERIFIES SUCCESS
void fileCheck(ofstream& txtStats, char userOutFile[])
{
	cout << "Please enter the name of the output file.\n";
	cout << "Filename:  ";
	cin >> userOutFile;
	
	// Attempt to open user's file name
	txtStats.open(userOutFile);

	// While file cannot be opened
	while(!txtStats)
	{
		cout << "Sorry, something went wrong with that file name...\n";
		cout << "Please try again:  ";
		cin >> userOutFile;

		// Attempt again
		txtStats.open(userOutFile);
	}
}


// RECORDS THE DATA FROM THE INPUT FILE
void statCheck(ifstream& userTxt, int& charCount, int& letterCount, int& spaceCount, int& digitCount,
int& otherCount, int& upperCount, int& lowerCount, int& intCount, int& intSum, int alphabetCount[], char alphabet[])
{
	char ch;
	
	// Read first character of file
	userTxt.get(ch);

	// While the file has not ended
	while(!userTxt.eof())
	{
		charCount++;	// Increment character counter

		if(isalpha(ch))	// If the character is a letter
		{
			letterCount++;	// Increment letter counter
					
			if(isupper(ch))	// If uppercase
				upperCount++;	// Increment uppercase counter
			if(islower(ch))	// If lowercase
				lowerCount++;	// Increment lowercase counter
			
			ch = tolower(ch);	// Set character to lowercase

			for(int i = 0; i < 26; i++)	// Loop that parses through alphabet array and checks which letter it matches
			{
				if(ch == alphabet[i])
				{
					alphabetCount[i]++;	// Increment appropriate letter counter
					break;
				}
			}
		}
		else if(isspace(ch))	// If character is white space
			spaceCount++;	// Increment space counter
		else if(isdigit(ch))	// If character is a digit
		{
			digitCount++;	// Increment digit counter
		
			int tempSum = ch - '0';		// Set a temporary sum = to integer value of character

			while(isdigit(userTxt.peek()))	// While the following character is also a digit
			{
				int tempChar = ch - '0';	// Set a temporary variable = integer value of first character
				userTxt.get(ch);		// Get next character from text

				if(tempSum >= 10)		// If the temporary sum variable is >= 10 (can only happen on second loop)
					tempSum = (tempSum * 10) + (ch - '0');		// Multiply temporary sum value by 10 and add new integer value to end
				else if(tempChar < 10)		// If temporary character variable is < 10 (can only happen on first iteration)
					tempSum = (tempChar * 10) + (ch - '0');		// Multiply temporary character by 10 and add new integer value to end (store in temporary sum variable)

				// Increment appropriate counters for each iteration
				digitCount++;
				charCount++;
			}
	
			// Add final temporary sum value to overall integer sum variable
			intSum += tempSum;

			// Increment integer counter
			intCount++;
		}
		else	// If character is not covered previously 
			otherCount++;	// Increment other counter

		// Get next character in file and restart loop (so long as file has not ended)
		userTxt.get(ch);
	}
}


// DISPLAYS THE RESULTS OF THE DATA RECORDING
void outputFile(ofstream& txtStats, int& charCount, int& letterCount, int& spaceCount, int& digitCount,
int& otherCount, int& upperCount, int& lowerCount, int& intCount, int& intSum, int alphabetCount[], char alphabet[], char userInFile[])
{
	// Set flags for formatting
	txtStats << fixed << showpoint;
	txtStats.precision(2);

	// Display results on output file in neat tables
	txtStats << "Statistics for file: " << userInFile << '\n';
	txtStats << "-------------------------------------------------\n";
	txtStats << "\nTotal # of characters in file:" << setw(10) << right << charCount << "\n\n";
	txtStats << "Category" << setw(32) << "How many in file" << setw(20) << "% of file" << '\n';
	txtStats << "----------------------------------------------------------------------\n";
	txtStats << setw(35) << left << "Letters" << setw(5) << right << letterCount << setw(20) << (static_cast<double>(letterCount) / charCount) * 100 << " %\n";
	txtStats << setw(35) << left << "White space" << setw(5) <<  right << spaceCount << setw(20) << (static_cast<double>(spaceCount) / charCount) * 100 << " %\n";
	txtStats << setw(35) << left << "Digits" << setw(5) << right << digitCount << setw(20) << (static_cast<double>(digitCount) / charCount) * 100 << " %\n";
	txtStats << setw(35) << left << "Other characters" << setw(5) << right << otherCount << setw(20) << (static_cast<double>(otherCount) / charCount) * 100 << " %\n";
	txtStats << "\n\nLETTER STATISTICS\n\n";
	txtStats << "Category" << setw(32) << "How many in file" << setw(20) << "% of all letters" << '\n';
	txtStats << "----------------------------------------------------------------------\n";
	txtStats << setw(35) << left << "Uppercase" << setw(5) << right << upperCount << setw(20) << (static_cast<double>(upperCount) / letterCount) * 100 << " %\n";
	txtStats << setw(35) << left << "Lowercase" << setw(5) << right << lowerCount << setw(20) << (static_cast<double>(lowerCount) / letterCount) * 100 << " %\n";
	
	// Loop to display entire alphabet with according statistics
	for(int i = 0; i < 26; i++)
	{
		txtStats << setw(35) << left << alphabet[i] << setw(5) << right << alphabetCount[i] << setw(20) << (static_cast<double>(alphabetCount[i]) / letterCount) * 100 << " %\n";
	}

	// Number-related statistics
	txtStats << "\n\nNUMBER ANALYSIS\n\n";
	txtStats << setw(30) << left << "Number of integers in file:" << setw(10) << right << intCount << '\n';
	txtStats << setw(30) << left << "Their sum:" << setw(10) << right << intSum << '\n';
	txtStats << setw(30) << left << "Their average:" << setw(10) << right << static_cast<double>(intSum) / intCount << "\n\n";
}
