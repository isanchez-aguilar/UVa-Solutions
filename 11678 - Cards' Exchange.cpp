/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11678 - Cards' Exchange
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int cardsA;
	int cardsB;
	bitset<100001> cards;
	// Read the number of cards while not EOF.
	while(cin >> cardsA >> cardsB && cardsA && cardsB)
	{
		// Initializing variables.
		cards.reset();
		int currentCard;
		int maxCardsA = 0;
		int maxCardsB = 0;
		int lastCard = 0;
		// Read the cards of player A.
		while(cardsA--)
		{
			// Read the card's id.
			cin >> currentCard;
			// If the card is not repeated then add maxCardA and set the card true.
			if(!cards[currentCard])
			{
				++maxCardsA;
				cards[currentCard] = 1;
			}
		}
		// Read the cards of player A.
		while(cardsB--)
		{
			// Read the card's id.
			cin >> currentCard;
			// If the last card is not same as the last.
			if(currentCard != lastCard)
			{
				// If the card is repeated then decrease the value of maxCardsA.
				if(cards[currentCard])
					--maxCardsA;
				// If the card is not repeated then add maxCardB and set the card true.
				else
					++maxCardsB;
				// Update the last card with the currentCard.
				lastCard = currentCard;
			}

		}
		// Get and print the minimum number of cards between playerA and player B.
		cout << min(maxCardsA, maxCardsB) << '\n';
	}
	return 0;
}