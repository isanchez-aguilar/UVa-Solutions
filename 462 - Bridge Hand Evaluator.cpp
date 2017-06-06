/*
*	User: Isanchez_Aguilar
*	Problem: UVA 462 - Bridge Hand Evaluator
*/
#include <bits/stdc++.h>

using namespace std;

string card;
bitset<4> ace;
bitset<4> jack;
bitset<4> king;
bitset<4> queen;
bitset<4> stopped;

inline int getSuit()
{
	switch(card[1])
	{
		case 'S':
			return 0;
		break;
		case 'H':
			return 1;
		break;
		case 'D':
			return 2;
		break;
		default:
			return 3;
	}	
}

inline int getValue()
{
	switch(card[0])
	{
		case 'A':
			ace[getSuit()] = 1;
			return 4;
		case 'K':
			king[getSuit()] = 1;
			return 3;
		case 'Q':
			queen[getSuit()] = 1;
			return 2;
		case 'J':
			jack[getSuit()] = 1;
			return 1;
		default:
			return 0;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Read while there is a card.
	while(cin >> card)
	{
		// Reset status of important cards.
		ace.reset();
		jack.reset();
		king.reset();
		queen.reset();
		stopped.reset();
		// Get the value of the current card.
		int currentValue = getValue();
		vector< vector<char> > suit(4, vector<char>(0));
		// Insert the card at it suit.
		suit[getSuit()].push_back(card[0]);
		// Read the remaining cards.
		for(int i = 1; i < 13; ++i)
		{
			// Read the card, insert and add the value.
			cin >> card;
			suit[getSuit()].push_back(card[0]);
			currentValue += getValue();
		}
		int maxIndex = 0;
		int maxCards = -1;
		int extraValue = 0;
		// Check the value of 4 suits.
		for(int i = 0; i < 4; ++i)
		{
			// Get the number of cards of i-th suit.
			int size = suit[i].size();
			// If the maxCards is smaller than size.
			if(maxCards < size)
			{
				maxIndex = i;
				maxCards = size;
			}
			// If the size is zero then increase extra value.
			if(!size)
				extraValue += 2;
			// If there is one card at suit.
			else if(size == 1)
			{
				// For each king decrease one point.
				if(king[i])
					--currentValue;
				// For each queen decrease one point.
				if(queen[i])
					--currentValue;
				// For each jack decrease one point.
				if(jack[i])
					--currentValue;
				// Add two points because the number of cards at suit is one.
				extraValue += 2;
			}
			// If there is two cards at suit.
			else if(size == 2)
			{
				// For each queen decrease one point.
				if(queen[i])
					--currentValue;
				// For each jack decrease one point.
				if(jack[i])
					--currentValue;	
				// Add one points because the number of cards at suit is two.
				++extraValue;
			}
			// If the size is one and there is a jack then decrease one point.
			else if(size == 3 && jack[i])
				--currentValue;
			// If there is a ace hand is stopped.
			if(ace[i])
				stopped[i] = 1;
			// If there is a king and the size is bigger or equal than 2 suit is stopped.
			else if(king[i] && size >= 2)
				stopped[i] = 1;
			// If there is a queen and the size is bigger or equal than 3 suit is stopped.
			else if(queen[i] && size >= 3)
				stopped[i] = 1;
		}
		// If all suits are stopped and the current value is bigger or equal to sixteen.
		if(stopped.count() == 4 && currentValue >= 16)
			cout << "BID NO-TRUMP\n";
		// If the current value plus extravalue is bigeer or equal than fourteen.
		else if(currentValue + extraValue >= 14)
		{
			// Set the maximum suit.
			char s;
			switch(maxIndex)
			{
				case 0:
					s = 'S';
				break;
				case 1:
					s = 'H';
				break;
				case 2:
					s = 'D';
				break;
				default:
					s = 'C';
			}
			cout << "BID " << s << '\n';
		}
		// If the current value is smaller than fourteen.
		else
			cout << "PASS\n";	
	}
	return 0;
}