/*
Dylan Negvesky	
COP 3363
HW 3
Create a menu function that displays menu items and prices
Take user's order and send values to function to calculuate order's total
*/

#include <iostream>
using namespace std;

double OrderTotal(int, int, int, int);
void menu();

int main()
{
	// Keeps track of total amount of each that are ordered
	int sumPatties = 0;
	int sumFries = 0;
	int sumDrinks = 0;
	int sumPizzas = 0;
	
	// Temporary variables to store user's initial choice (added to sum)
	int pattyChoice, fryChoice, drinkChoice, pizzaChoice;
	
	// Stores user's menuChoice
	int menuChoice;
	
	// Stores final total on receipt
	double totalCost = 0.00;

	cout << "\nWelcome to the Krusty Krab!\n";

	// Loop that will continue as long as user does not enter 0
	do
	{
		menu();   // Call menu
	
		cout << "\nWhat would you like? (Enter 0 to finish order!): ";
		cin >> menuChoice;   // Take in the user's menu choice

		switch(menuChoice)    // Check user's menu choice
		{
			case 1:   // Patty
				cout << "How many: ";
				cin >> pattyChoice;
				
				// While user entry is invalid
				while(pattyChoice < 0)
				{
					cout << "You can't order a negative amount of food!\n";
					cout << "Try again: ";
					cin >> pattyChoice;     // Have user re-enter choice
 				}
	
				sumPatties += pattyChoice;	// Add amount to sum variable
				break;
	
			case 2:   // Fries 
				cout << "How many: ";
				cin >> fryChoice;

				// While user's entry is invalid
				while(fryChoice < 0)
				{
					cout << "You can't order a negative amount of food!\n";
					cout << "Try again: ";
					cin >> fryChoice;   // Have user re-enter choice
				}

				sumFries += fryChoice;   // Add amount to sum variable
				break;
	
			case 3:   // Drinks
				cout << "How many: ";
				cin >> drinkChoice;
	
				// While user's entry invalid
				while(drinkChoice < 0)
				{
					cout << "You can't order a negative amount of food!\n";
					cout << "Try again: ";
					cin >> drinkChoice;   // Have user re-enter choice
				}

				sumDrinks += drinkChoice;    // Add amount to sum variable
				break;
	
			case 4:   // Pizza
				cout << "How many: ";
				cin >> pizzaChoice;

				// While user's entry is invalid
				while(pizzaChoice < 0)
				{
					cout << "You can't order a negative amount of food!\n";
					cout << "Try again:";
					cin >> pizzaChoice;   // Have user re-enter choice
				}

				sumPizzas += pizzaChoice;   // Add amount to sum variable
				break;
	
			case 0:   // Order over
				totalCost = OrderTotal(sumPatties, sumFries, sumDrinks, sumPizzas);    // When user is done entering values send them to order total function
				break;
	
			default:  // Invalid menu choice 
				cout << "That isn't on the menu! Try again.\n";	

		}


	}while(menuChoice != 0);  // Continue loop as long as user has not entered sentinel value

	if(sumPatties == 0 && sumFries == 0 && sumDrinks == 0 && sumPizzas == 0)   // If user has not entered a value for any of the options
	{
		cout << "Guess you aren't hungry.\n";
		return 0;
	}

	// Display the receipt
	cout << "\nYour Order:\n";
	
	// If user has not entered 0 for an option, display the amount they have chosen
	if(sumPatties != 0)
		cout << sumPatties << " krabby patties.\n";
	if(sumFries != 0)
		cout << sumFries << " barnacle fries.\n";
	if(sumDrinks != 0)
		cout << sumDrinks << " kelp shakes.\n";
	if(sumPizzas != 0)
		cout << sumPizzas << " krusty krab pizzas.\n";
	
	// totalCost = OrderTotal(sumPatties, sumFries, sumDrinks, sumPizzas);

	// Display total for receipt
	cout << fixed << showpoint;
	cout.precision(2);
	cout << "\nYour total is $" << totalCost;
	cout << "\nEnjoy the food!\n";	

	cout << endl;

	return 0;
}

// Display menu
void menu()
{

	cout << "\n----------- Menu -----------\n";
	cout << "1. Krabby Patty ...... $3.50\n";
	cout << "2. Barnacle Fries .... $1.50\n";
	cout << "3. Kelp Shake ........ $1.00\n";
	cout << "4. Krusty Krab Pizza . $5.00\n";

}

// Calculate order total
double OrderTotal(int pat, int fry, int drink, int pizza)
{
	double pattyCost = 3.50;
	double fryCost = 1.50;
	double drinkCost = 1.00;
	double pizzaCost = 5.00;

	return (pat * pattyCost) + (fry * fryCost) + (drink * drinkCost) + (pizza * pizzaCost);    // Return the order total based on food prices
	
}
