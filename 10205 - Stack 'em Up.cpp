/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10205 - Stack 'em Up
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int shuffles;
	int testCases;
	int shuffle[100];
	int deck[100][52];
	string line = "\0";
	string suit[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
	string value[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
	cin >> testCases;
	// While test cases is not zero.
	while(testCases--)
	{
		// Print the blank line.
		cout << line;
		line = "\n";
		// Read the number of shuffles.
		cin >> shuffles;
		// Read the decks of shuffles.
		for(int i = 0; i < shuffles; ++i)
		{
			// Read the deck.
			for(int j = 0; j < 52; ++j)
			{
				cin >> deck[i][j];
				--deck[i][j];
			}
		}
		// Ignore the new line.
		cin.ignore();
		
		int j = 0;
		string number;
		// Read the number of shuffle if It is not a blank line.
		while(getline(cin, number) && number.length())
		{
			// Create a new stream to number.
			istringstream ss(number);
			// Convert the string to integer.
			ss >> shuffle[j];
			--shuffle[j++];
		}
		// Print the deck.
		for(int i = 0; i < 52; ++i)
		{
			// Initialize the position of card.
			int k = i;
			// Change the position of i-th card.
			for(j = shuffles - 1; j > -1; --j)
				k = deck[shuffle[j]][k];
			// Print the new shuffle card.
			cout << value[k % 13] << " of " << suit[k / 13] << '\n';
		}
	}
	return 0;
}