/*
*	User: Isanchez_Aguilar
*	Problem: UVA 162 - Beggar My Neighbour
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string card;
	while(1)
	{
		// Initialize variables.
		int turn = 0;
		vector< list<int> > players(2);
		// Read the 52 cards.
		for(int i = 0; i < 52; ++i, turn = !turn)
		{
			// Read the card.
			cin >> card;
			// If It is a # then finish the program.
			if(card[0] == '#')
				return 0;
			// Evaluate the card.
			switch(card[1])
			{
				//If It is a J the value to cover it is 1.
				case 'J':
					players[turn].push_front(1);
					break;
				//If It is a J the value to cover it is 2.
				case 'Q':
					players[turn].push_front(2);
					break;
				//If It is a J the value to cover it is 3.
				case 'K':
					players[turn].push_front(3);
					break;
				//If It is a J the value to cover it is 4.
				case 'A':
					players[turn].push_front(4);
					break;
				//If It is not a face card the value to cover it is 0.
				default:
					players[turn].push_front(0);
			}
		}
		// Deck of game
		list<int> game;
		bool cycle = false;
		// While the current payer has cards continue the game.
		while(!players[turn].empty())
		{
			// Get the value of current card.
			int currentCard = players[turn].front();
			// Delete the card of the player's deck. 
			players[turn].pop_front();
			// Insert the current card on the game's deck.
			game.push_back(currentCard);
			// Change the turn.
			turn = !turn;
			// While the value of the current card is nonzero.
			while(currentCard)
			{
				// If the current player does not cards finish the game.
				if(players[turn].empty())
				{
					cycle = false;
					break;
				}
				// If the current player has cards the cycle
				else
					cycle = true;
				// Get the card of current player.
				int card = players[turn].front();
				// Delete the card of the player's deck. 
				players[turn].pop_front();
				// Insert the current card on the game's deck.
				game.push_back(card);
				// If It is a face card change the current player and card.
				if(card)
				{			
					turn = !turn;
					currentCard = card;
				}
				// If It is a normal card just decrease the value of current card.
				else
					--currentCard;
			}
			// If It was a cycle insert the cards of game to last player to play a face card.
			if(cycle)
			{
				cycle = false;
				turn = !turn;
				while(!game.empty())
				{
					players[turn].push_back(game.front());
					game.pop_front();
				}
			}
		}
		// If the nondealer is empty then the winner is the dealer.
		if(players[0].empty())
			cout << "1 " << setw(2) << players[1].size() << "\n"; 
		// If the nondealer is not empty tenh the winner is the nondealer. 
		else
			cout << "2 " << setw(2) << players[0].size() << "\n";
	}
	return  0;
}