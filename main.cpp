
#include "pch.h"
#include <iostream>
#include "Coin.h"
#include <string>
#include <ctime>
using namespace std;

//Initialize objects and variables

Coin nickel(5);
Coin dime(10);
Coin quarter(25);
char in;
int Balance = 0;
int qct;
int dct;
int nct;

//Function Definitions
void welcome();
void callStart();
bool startGame();
void goodbye();

int main()
{
	srand(time(NULL));

	welcome();
	in = cin.get();
	cin.ignore(100, '\n');
	in = toupper(in);

	if (in == 'Q') {
		goodbye();
		return 0;
	}
	callStart();

	goodbye();

	return 0;
}

void welcome() {

	cout << " The current side facing up for each coin is:" << endl << endl;
	cout << "   Quarter: " << quarter.getSideUp() << "." << endl;
	cout << "   Dime: " << dime.getSideUp() << "." << endl;
	cout << "   Nickel: " << nickel.getSideUp() << "." << endl << endl;
	cout << " Your balance is " << Balance << " cents." << endl << endl;
	cout << " Start the game....." << endl << endl;
	cout << " Press 'F' + [ENTER] to flip coin or type 'Q' + [ENTER] to quit.\n";
	cout << " > ";
}

void callStart() {
	bool restart = true;
	while (restart) {
		restart = startGame();
	}
}

bool startGame() {
	Balance = 0; //reset the total balance here.
	int roundCount = 0; // reset

	while (in != 'Q' && Balance < 100) {
		roundCount++;

		cout << " -\n";
		cout << "Round# " << roundCount << ": |\n";

		cout << " flipping all 3 coins..." << endl << endl;
		nickel.toss();
		quarter.toss();
		dime.toss();

		cout << " Here is the toss landing...:" << endl << endl;
		cout << "  Nickel: " << nickel.getSideUp() << "." << endl << endl;
		cout << " Quarter: " << quarter.getSideUp() << "." << endl;
		cout << " Dime: " << dime.getSideUp() << "." << endl;

		if (quarter.getSideUp() == "heads") {
			qct++;
			Balance += quarter.getValue();

		}

		if (dime.getSideUp() == "heads") {

			dct++;

			Balance += dime.getValue();
		}
		
		if (nickel.getSideUp() == "heads") {
			nct++;
			Balance += nickel.getValue();

		}
		cout << " Your new balance is " << Balance << " cents." << endl << endl;
		if (Balance == 100) {
			cout << "It is over!" << endl;
			cout << " Winner, Congratulations!" << endl << endl;
			cout << "u landed nickel total # of " << nct << "  times.." << endl;
			cout << "u landed quarter total # of " << qct << "  times.." << endl;
			cout << "u landed dime  total #  of " << dct << " times.." << endl;

		}
		else if (Balance > 100) {
			cout << " GAME OVER" << endl;
			cout << " You lost!" << endl << endl;
			cout << "u landed nickel total # of " << nct << "  times.." << endl;
			cout << "u landed quarter total # of " << qct << " times.." << endl;
			cout << "u landed dime  total #  of "<< dct<<"  times.."  << endl;

			Balance = 100;
			in = 'Q';
			goodbye();
			
		}
		else {
			cout << " Press 'F' + [ENTER] to flip coin or 'Q' + [ENTER] to quit." << endl;
			cout << " > ";
			in = cin.get();
			cin.ignore(100, '\n');
			in = toupper(in);

			if (in == 'Q')
				return false;
		}
	}//end while loop
}
void goodbye() {
	Balance == 100;
	
	cout << endl << " Thank you for playing! Goodbye!" << endl << endl;
	

}