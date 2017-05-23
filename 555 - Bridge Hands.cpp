/*
*	User: Isanchez_Aguilar
*	Problem: UVA 555 - Bridge Hands
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	char dealer;
	vector< bitset<52> > hands;
	vector< pair<int, int> > range;
	// Read while not EOF.
	while(cin >> dealer && dealer != '#')
	{
		int i;
		hands = vector< bitset<52> >(4);
		vector< pair<int, int> > range(4, pair<int, int>(52, 0));
		// Get the index value of the dealer.
		switch(dealer)
		{
			case 'S':
				i = 0;
			break;
			case 'W':
				i = 1;
			break;
			case 'N':
				i = 2;
			break;
			default:
				i = 3;
			break;
		}
		// Read the cards from the deck.
		for(int j = 51; j > -1; --j)
		{
			char suit;
			char value;
			// Change the player turn.
			i = (i + 1) % 4;
			// Read the suit and value of the card.
			cin >> suit >> value;
			// Get the value of the suit.
			switch(suit)
			{
					 case 'C':
						suit = 0;
					 break;
					 case 'D':
						suit = 1;
					 break;
					 case 'S':
						suit = 2;
					 break;
					 default:
						suit = 3;
					 break;
			}
			// Get the value of the card.
			switch(value)
			{
				case 'T':
					value = 8;
				break;
				case 'J':
					value = 9;
				break;
				case 'Q':
					value = 10;
				break;
				case 'K':
					value = 11;
				break;
				case 'A':
					value = 12;
				break;
				default:
					value = value - 50;
				break;
			}
			// Set true the index of the current card.
			hands[i][suit * 13 + value] = 1;
			// Compare the max and min value the hand of the player i.
			range[i].first = min(range[i].first, suit * 13 + value);
			range[i].second = max(range[i].second, suit * 13 + value);
		}
		// Print the hand of every single player.
		for(i = 0; i < 4; ++i)
		{
			// Get the name of i-th player.
			switch(i)
			{
				case 0:
					cout << "S:";
				break;
				case 1:
					cout << "W:";
				break;
				case 2:
					cout << "N:";
				break;
				default:
					cout << "E:";
				break;
			}
			// Print the player's cards i-th player. 
			for(int j = range[i].first, curentCards = 0; j <= range[i].second, curentCards < 13; ++j)
			{
				if(hands[i][j])
				{
					++curentCards;
					// Get the suit's name.
					switch(j / 13)
					{
						case 0:
							cout << " C";
						break;
						case 1:
							cout << " D";
						break;
						case 2:
							cout << " S";
						break;
						default:
							cout << " H";
						break;
					}
					// Get the card's name.
					switch(j % 13 + 2)
					{
						case 10:
							cout << "T";
						break;
						case 11:
							cout << "J";
						break;
						case 12:
							cout << "Q";
						break;
						case 13:
							cout << "K";
						break;
						case 14:
							cout << "A";
						break;
						default:
							cout << j % 13 + 2;
						break;
					}
				}
			}
			cout << '\n';
		}
	}
	return 0;
}