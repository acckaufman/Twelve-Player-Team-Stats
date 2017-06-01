#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Player
{
	string name;
	int idNumber;
	int pointsScored;
};

void getPlayerInfo(Player&);
void showInfo(Player);
int getTotalPoints(Player[], int);
void showHighest(Player[], int);

int main()
{
	const int NUM_PLAYERS = 12;
	Player roster[NUM_PLAYERS];

	cout << "Please input information for each of the players now." << endl;

	for (int count = 0; count < NUM_PLAYERS; count++)
	{
		cout << endl;
		cout << "PLAYER #" << (count + 1) << endl;
		cout << "---------" << endl;
		getPlayerInfo(roster[count]);
	}

	cout << endl;
	cout << setw(20) << left << "NAME";
	cout << setw(10) << left << "NUMBER";
	cout << setw(20) << left << "POINTS SCORED";
	cout << endl;

	for (int count = 0; count < NUM_PLAYERS; count++)
		showInfo(roster[count]);

	int teamPoints;
	teamPoints = getTotalPoints(roster, NUM_PLAYERS);

	cout << "TOTAL POINTS: " << teamPoints << endl;

	showHighest(roster, NUM_PLAYERS);

	system("pause");
	return 0;
}

void getPlayerInfo(Player &player)
{
	cout << "Player name: ";
	getline(cin, player.name);
	cout << "Player's number: ";
	cin >> player.idNumber;
	while (player.idNumber < 0)		//Input validation, check for negative numbers
	{
		cout << endl;
		cout << "Error! You must input a positive ID number. Please try again." << endl << endl;
		cout << "Player's number: ";
		cin >> player.idNumber;
	}
	cout << "Points scored: ";
	cin >> player.pointsScored;
	while (player.pointsScored < 0)		//Input validation, check for negative numbers
	{
		cout << endl;
		cout << "Error! You must input a positive number of points. Please try again." << endl << endl;
		cout << "Player's number: ";
		cin >> player.pointsScored;
	}
	cin.ignore();
}

void showInfo(Player player)
{
	cout << setw(20) << left << player.name;
	cout << setw(10) << left << player.idNumber;
	cout << setw(20) << left << player.pointsScored;
	cout << endl;
}

int getTotalPoints(Player roster[], int size)
{
	int total = 0;		//Accumulator variable

	for (int count = 0; count < size; count++)		//For each player on the team
		total += roster[count].pointsScored;		//Add their points scored to the total

	return total;
}

void showHighest(Player roster[], int size)
{
	int maxValue = 0;
	int maxIndex = 0;

	for (int count = 0; count < size; count++)		//For each player on the team
	{
		if (roster[count].pointsScored > maxValue)	//If the amount of points they scored is higher than what maxValue is currently set to
		{
			maxValue = roster[count].pointsScored;	//Set max value to hold their number of points
			maxIndex = count;						//Temporarily hold the index (subscript) of the highest scorer
		}
	}

	//Use the index (subscript) of the person with the most points to display their name for the user.
	cout << "The player who scored the most points is: " << roster[maxIndex].name << endl;
}