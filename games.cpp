/*
Dylan Negvesky
COP 3363
HW4
Program that displays a menu with choices of games to user
and allows them to choose which game to play as well as track statistics
*/

/*Headers/Libraries*/
#include <iostream> 
#include <cstdlib>
#include <ctime>

using namespace std;

/*Function Declarations HERE... printRules' declaration is included already*/
void printRules();
int menu();
bool guessNumber();
bool highLow();
bool collectPairs();
void viewStats(int, int);

int main()
{
	srand(time(0));   // Seed rand
	
	int menuChoice;   // Store user's menu choice
	bool winCheck;    // Check if game function returned true (win) or false (loss)
	
	int wins = 0, losses = 0;   // Variables to track stats

	do
	{
		menuChoice = menu();   // Display menu

		switch(menuChoice)     // Check user's choice
		{
			case 1:        // If user chooses Guess Number game
				winCheck = guessNumber();
				if(winCheck)   // If user wins
					wins++;
				else           // If user loses
					losses++;
				break;
			case 2:        // If user chooses High Low game
				winCheck = highLow();
				if(winCheck)   // If user wins
					wins++;
				else           // If user loses
					losses++;
				break;
			case 3:       	// If user chooses Collect Pairs game 
				winCheck = collectPairs();
				if(winCheck)  // If user wins
					wins++;
				else          // If user loses
					losses++;
				break;
			case 4:         // If user chooses to view statistics
				viewStats(wins, losses);
				break;
			case 5:         // If user chooses to reset their statistics
				wins = 0;
				losses = 0;
				cout << "Statistics Reset!\n";
				break;
			case 6:         // If user chooses to see the rules
				printRules();
				break;
			case 0:         // If user chooses to exit the program
				viewStats(wins, losses);     // Display stats before terminating
				cout << "\nThanks for playing!\n";
				
		}
	


	}while(menuChoice != 0);
	    
	return 0;

}

/*Function definition for COLLECTPAIRS
this function is invoked whenever the user wants to play Collect Pairs.
this function returns true/false depending on if the user wins the game or not*/

bool collectPairs()
{

	int dice1, dice2;     // Variables to store each dice value
	bool onesFound, twosFound, threesFound, foursFound, fivesFound, sixesFound;    // Store true/false depending on whether pair has been found

	// Initialize all boolean variables to false
	onesFound = false;
	twosFound = false;
	threesFound = false;
	foursFound = false;
	fivesFound = false;
	sixesFound = false;

	cout << "\n\nRolling a pair of dice 100 times for pairs!\n";

	for(int rolls = 1; rolls <= 100; rolls++)     // For 100 dice rolls
	{
		dice1 = rand() % 6 + 1;     // Randomly generate a number 1-6 for both die
		dice2 = rand() % 6 + 1;

		if(dice1 == 1 && dice2 == 1 && onesFound == false)    // If both ones found
		{
			onesFound = true;
			cout << "PAIR OF ONES found\n";
		}
		else if(dice1 == 2 && dice2 == 2 && twosFound == false)    // If both twos found
		{
			twosFound = true;
			cout << "PAIR OF TWOS found\n";
		}
		else if(dice1 == 3 && dice2 == 3 && threesFound == false)    // If both threes found
		{
			threesFound = true;
			cout << "PAIRS OF THREES found\n";
		}
		else if(dice1 == 4 && dice2 == 4 && foursFound == false)     // If both fours found
		{
			foursFound = true;
			cout << "PAIR OF FOURS found\n";
		}
		else if(dice1 == 5 && dice2 == 5 && fivesFound == false)     // If both fives found
		{
			fivesFound = true;
			cout << "PAIR OF FIVES found\n";
		}
		else if(dice1 == 6 && dice2 == 6 && sixesFound == false)     // If both sixes found
		{
			sixesFound = true;
			cout << "PAIR OF SIXES found\n";
		}
	}

	if(onesFound && twosFound && threesFound && foursFound && fivesFound && sixesFound)      // If all pairs found
	{
		cout << "\nYOU WIN!\n";
		return true;
	}
	else       // If all pairs not found
	{
		cout << "\nSorry, you lose.\n";
		return false;
	}

}



/*Function definition for GUESSNUMBER
this function is invoked whenever the user wants to play Guess Number.
this function returns true/false depending on if the user wins the game or not*/

bool guessNumber()
{
	int magicNum;     // Variable for random number
	
	magicNum = rand() % 100 + 1;	// Generate random number 1-100

	cout << "\n\nGuess the Number, 1 --> 100!\n";

	int userAtmpt = 1;      // Variable for user attempts
	int userGuess;          // Store user's guess

	do
	{
		cout << "Attempt " << userAtmpt << "/6 : ";
		cin >> userGuess;    // Take in user's guess
		
		if(userGuess > magicNum && userGuess <= 100 && userGuess >= 1)    // If guess is in range and larger than magic number
		{
			cout << "TOO BIG\n"; 
			userAtmpt++;
		}
		else if(userGuess < magicNum && userGuess <= 100 && userGuess >= 1)    // If guess is in range and smaller than magic number
		{
			cout << "TOO SMALL\n";
			userAtmpt++;
		}
		else if(userGuess == magicNum)    // If user correctly guesses number
		{
			cout << "You WIN!\n";
			return true;    // User wins
		}
		else      // If user's guess is not in specified range
		{
			cout << "Your guess MUST be between 1 and 100...\n"; 
		}

	}while(userAtmpt <= 6);     // Allow user to have 6 attempts
	
	cout << "Sorry, you lose. The number was " << magicNum << '\n';
	return false;   // User loses

}



/*Function definition for HIGHLOW
this function is invoked whenever the user wants to play high low.
this function returns true/false depending on if the user wins the game or not*/

bool highLow()
{	
	int magicNum = rand() % 1000 + 1;      // Generate random number from 1-1000
	int tempMagicNum;    // Temporarily store previous number for testing purposes
	int userAtmpt = 1;   // Variable for user attempts
	char userGuess;	     // Variable for user's guess

	cout << "\n\nHigh or Low! Stay alive for 5 rounds to win! (Numbers range from 1 to 1,000)\n";

	do
	{
		cout << "Round " << userAtmpt << " of 5. The number is " << magicNum << '\n';
		cout << "        ... is the next number [H]igher or [L]ower?: ";
		cin >> userGuess;      // Take in user's guess for higher or lower
		
		while(userGuess != 'H' && userGuess != 'h' && userGuess != 'L' && userGuess != 'l')     // If user's guess is not valid
		{
			cout << "        Enter H or L: ";
			cin >> userGuess;     // Take in guess again
		}

		tempMagicNum = magicNum;      // Temporarily store previous value
		magicNum = rand() % 1000 + 1; // Generate new value 1-1000

		cout << "The next number is: " << magicNum << '\n';

		switch(userGuess)    // Test truth of user's guess
		{
			case 'H':
			case 'h':
				if(magicNum > tempMagicNum)    // If user correctly guesses higher
				{
					cout << "Correct!\n";
					userAtmpt++;
				}
				else if(magicNum < tempMagicNum)   // If user incorrectly guesses higher
				{
					cout << "Sorry, you lose.\n";
					return false;   // Loss
				}
				else if(magicNum == tempMagicNum)   // If new number is same as old
					cout << "Both numbers are the same! Go again...\n";
				break;
			case 'L':
			case 'l':
				if(magicNum < tempMagicNum)     // If user correctly guesses lower
				{
					cout << "Correct!\n";
					userAtmpt++;
				}
				else if(magicNum > tempMagicNum)    // If user incorrectly guesses lower
				{
					cout << "Sorry, you lose.\n";
					return false;   // Loss
				}
				else if(magicNum == tempMagicNum)    // If new number is same as old
					cout << "Both numbers are the same! Go again...\n";
				break;
		}
		


	}while(userAtmpt <= 5);    // Allow user to have 5 attempts

	cout << "YOU WIN!\n";	
	return true;    // If user "survives" 5 attempts: win

}



/*Function definition for VIEWSTATS
this function takes in the number of wins, and losses that the user had while playing their games
this function then prints the win and loss stats neatly to the screen, and returns no value*/

void viewStats(int wins, int losses)
{
	double winRatio = ((wins) / (static_cast<double>(wins) + static_cast<double>(losses))) * 100;    // 

	// Display stats in neat menu
	cout << "\nSTATISTICS:\n";
	cout << "-------------------------\n";
	cout << "Wins: " << wins << "         Losses: " << losses << '\n';
	cout << fixed << showpoint;
	cout.precision(1);
	if(wins == 0 && losses == 0)    // Avoids division by 0 in cases where wins + losses == 0
		cout << "Total Win Percent:  0.0%\n";   
	else    // Otherwise, display calculated value for ratio
		cout << "Total Win Percent:  " << winRatio << "%\n";

	return;

}



/*Function definition for MENU 
this function should print the menu for the user and ask/obtain their menu choice.
this function will return the user's menu choice after verifying it's a valid choice on the menu.*/

int menu()
{
	// Display menu
	cout << "\nGAME MENU:\n";
	cout << "--------------------------\n";
	cout << "1: PLAY Guess the Number\n";
	cout << "2: PLAY High Low\n";
	cout << "3: PLAY Collect Pairs\n";
	cout << "4: VIEW Statistics\n";
	cout << "5: RESET Statistics\n";
	cout << "6: RULES\n";
	cout << "0: QUIT\n";
	cout << "--------------------------\n";
	cout << ">";

	int userEntry;   // User menu choice

	do
	{
		cin >> userEntry;   // Take in choice

		if(userEntry < 0 || userEntry >6)    // If user entry is invalid, try again
			cout << "Enter an item on the Menu: ";

	}while(userEntry < 0 || userEntry > 6);

	return userEntry;    // Return user's choice to main

}


/*Function definition for PRINTRULES
this function prints the rules of all of the games available to the user in this program
that is all this function is responsible for. DO NOT CHANGE this function.*/
void printRules()
{
    cout << "\nRULES:\n\nGuess the Number Game:\nYou'll only get 6 tries to guess a number between 1 and 100!\nGuess Wisely!\n\n";
    cout << "High/Low Game:\nMake it through 5 rounds of guessing whether the next random number\n";
    cout << "between 1 and 1,000 is higher or lower than the previous, and you win!\n\n";
    cout << "Collect the Pairs Game:\nRoll two dice 100 times. If in the 100 times you roll a pair\n";
    cout << "of each type (1's, 2's, 3's, 4's, 5's, 6's) at least once, then YOU WIN!\n\n";
    return;
}
