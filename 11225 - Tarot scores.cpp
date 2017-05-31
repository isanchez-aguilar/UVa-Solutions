/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11225 - Tarot scores
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int testCases;
	cin >> testCases;
	// Read the test cases.
	for(int i = 1; i <= testCases; ++i)
	{
		int cards;
		string card;
		string of;
		string suit;
		// Read the number of test cases.
		cin >> cards;
		// Initialize the points of game.
		int oudlers = 0;
		float currentPoints = 0;
		// Read the cards.
		while(cards--)
		{
			// Read the name of card.
			cin >> card;
			// If the card is not a fool then read the missing data.
			if(card != "fool")
			{
				// Read the suit of card.
				cin >> of >> suit;
				// Check the type of card.
				if(card == "king")
					currentPoints += 4.5;
				else if(card == "queen")
					currentPoints += 3.5;
				else if(card == "knight")
					currentPoints += 2.5;
				else if(card == "jack")
					currentPoints += 1.5;
				else if(card == "twenty-one" || card == "one")
				{
					++oudlers;
					currentPoints += 4.5;
				}
				else
					currentPoints += 0.5;
			}
			// If the current card is a fool then increase the read oudlers and the points.
			else
			{
				++oudlers;
				currentPoints += 4.5;
			}

		}
		// Get the final score with the oudlers.
		switch(oudlers)
		{
			case 0:
				currentPoints -= 56;
			break;
			case 1:
				currentPoints -= 51;
			break;
			case 2:
				currentPoints -= 41;
			break;
			default:
				currentPoints -= 36;
		}
		// If It is not the first hand then print a blank line.
		if(i > 1)
			cout << "\n";
		// Print data of hand.
		cout << "Hand #" << i << '\n';
		cout << "Game ";
		// If the final score is positive or 0 then you win the game.
		if(currentPoints >= 0)
			cout << "won by " << currentPoints << " point(s).\n";
		// If the final score is negative then you lost the game.
		else
			cout << "lost by " << -currentPoints << " point(s).\n";
	}
	return 0;
}