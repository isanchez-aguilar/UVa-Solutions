/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10315 - Poker Hands
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> values;
vector<int> hand(5);
vector<int> frequence(13, 0);

int cardValue(char value)
{
	// Return the value of card.
	switch(value)
	{
		case 'A':
			return 0;
		case 'T':
			return 9;
		case 'J':
			return 10;
		case 'Q':
			return 11;
		case 'K':
			return 12;
		default:
			return value - '1';
	}
}

int handValue(bool flush)
{
	int handValue;
	values.clear();
	int last = hand[0];
	bool straight = true;
	// If the first card of hand is Ace.
	if(!last)
	{
		// If the last card of hand is a King.
		if(hand[4] == 12)
		{
			// Scroll through the cards.
			for(int i = 4; i > 0; --i)
			{
				// If the next card is not the next value then check the possible cases.
				if(hand[i] - 1 != hand[i - 1])
				{
					// If the card number i - 1 is bigger than 8 then is not a straight.
					if(hand[i - 1] > 8)
						straight = false;
					/* 
					* If the card number i - 1 is lesser than 8 and the card number i is bigger or equal to 8
					* and i is not equal to card number i - 1 plus 1. 
					*/
					else if(hand[i - 1] < 8 && hand[i] >= 8 && i != hand[i - 1] + 1)
						straight = false;
				}
			}
		}
		// If the last card of hand is not a King.
		else
			straight = false;
	}
	// If the first card of hand is Ace.
	else
	{
		// Scroll through the cards.
		for(int i = 0; i < 4; ++i)
		{
			// If the next card is not the next value then is not a straight.
			if(hand[i] + 1 != hand[i + 1])
				straight = false;
		}
	}
	// If the hand is a straight and flush then map the value of cards and sort the cards and assign the handValue.
	if(straight && flush)
	{
		values.resize(5);
		for(int i = 0; i < 5; ++i)
		{
			if(hand[i] == 0)
				values[i] = 13;
			else
				values[i] = hand[i];
		}
		sort(values.begin(), values.end());
		handValue = 8;
	}
	// If the hand is not a straight and flush.	
	else
	{
		// Initialize the hands.
		int currentCards = 0;
		bool fourKind = false;
		bool fullHouse = false;
		bool third = false;
		bool pair = false;
		bool twoPair = false;
		// Check the frequence of cards and find the hand.
		for(int i = 0; i < 13 && !fourKind  && currentCards  < 5; ++i)
		{
			switch(frequence[i])
			{
				case 4:
					fourKind = true;
				break;
				case 3:
					if(pair)
						fullHouse = true;
					else
						third = true;
					currentCards += 3;
				break;
				case 2:
					if(third)
						fullHouse = true;
					else if(pair)
						twoPair = true;
					else
						pair = true;
					currentCards += 2;
				break;
			}
		}
		currentCards = 0;
		// Evaluate the hands, sort and map the cards values.
		if(fourKind)
		{
			values.resize(2);
			for(int i = 0; i < 13 && currentCards < 5; ++i)
			{
				if(frequence[i] == 4)
				{
					currentCards += 4;
					values[1] = (!i?13:i);
				}
				else if(frequence[i] == 1)
				{
					++currentCards;
					values[0] = (!i?13:i);
				}

			}
			handValue = 7;
		}
		else if(fullHouse)
		{
			values.resize(2);
			for(int i = 0; i < 13 && currentCards < 5; ++i)
			{
				if(frequence[i] == 3)
				{
					currentCards += 3;
					values[1] = (!i?13:i);
				}
				else if(frequence[i] == 2)
				{
					currentCards += 2;
					values[0] = (!i?13:i);
				}
			}
			handValue = 6;
		}
		else if(flush)
		{
			values.resize(5);
			for(int i = 0; i < 5; ++i)
			{
				if(hand[i] == 0)
					values[i] = 13;
				else
					values[i] = (!hand[i]?13:hand[i]);
			}
			sort(values.begin(), values.end());
			handValue = 5;
		}
		else if(straight)
		{
			values.resize(5);
			for(int i = 0; i < 5; ++i)
			{
				if(hand[i] == 0)
					values[i] = 13;
				else
					values[i] = (!hand[i]?13:hand[i]);
			}
			sort(values.begin(), values.end());
			handValue = 4;
		}
		else if(third)
		{
			int j = 0;
			values.resize(3);
			for(int i = 0; i < 13 && currentCards < 5; ++i)
			{
				if(frequence[i] == 3)
				{
					currentCards += 3;
					values[2] = (!i?13:i);
				}
				else if(frequence[i] == 1)
				{
					++currentCards;
					values[j++] = (!i?13:i);
				}
			}
			sort(values.begin(), values.begin() + 1);
			handValue = 3;
		}
		else if(twoPair)
		{
			int j = 1;
			values.resize(3);
			for(int i = 0; i < 13 && currentCards < 5; ++i)
			{
				if(frequence[i] == 2)
				{
					currentCards += 2;
					values[j++] = (!i?13:i);
				}
				else if(frequence[i] == 1)
				{
					++currentCards;
					values[0] = (!i?13:i);
				}
			}
			sort(values.begin(), values.begin() + 1);
			handValue = 2;
		}
		else if(pair)
		{
			int j = 0;
			values.resize(4);
			for(int i = 0; i < 13 && currentCards < 5; ++i)
			{
				if(frequence[i] == 2)
				{
					currentCards += 2;
					values[3] = (!i?13:i);
				}
				else if(frequence[i] == 1)
				{
					++currentCards;
					values[j++] = (!i?13:i);
				}
			}
			sort(values.begin(), values.begin() + 1);
			handValue = 1;
		}
		else
		{
			values.resize(5);
			for(int i = 0; i < 5; ++i)
			{
				if(hand[i] == 0)
					values[i] = 13;
				else
					values[i] = (!hand[i]?13:hand[i]);
			}
			sort(values.begin(), values.end());
			handValue = 0;
		}
	}
	return handValue;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	bool flush;
	string card;
	vector<int> player1;
	vector<int> player2;
	// While not EOF.
	while(cin >> card)
	{
		int hand1;
		int hand2;
		flush = true;
		frequence = vector<int>(13, 0);
		char currenColor = card[1];
		// Get the value of card and add the frequence.
		hand[0] = cardValue(card[0]);
		++frequence[hand[0]];
		// Read the next 4 cards.
		for(int i = 1; i < 5; ++i)
		{
			cin >> card;
			// Get the value of card and add the frequence.
			hand[i] = cardValue(card[0]);
			++frequence[hand[i]];
			// If the current color is different to the readed. 
			if(currenColor != card[1])
				flush = false;
		}
		// Sort the hand of player 1.
		sort(hand.begin(), hand.end());
		// Research the hand.
		hand1 = handValue(flush);
		player1 = values;
		// Read the first card.
		cin >> card;
		// Assume that the hand is a flush.
		flush = true;
		frequence = vector<int>(13, 0);
		currenColor = card[1];
		hand[0] = cardValue(card[0]);
		++frequence[hand[0]];
		// Read the next 4 cards. 
		for(int i = 1; i < 5; ++i)
		{
			cin >> card;
			// Get the value of card and add the frequence.
			hand[i] = cardValue(card[0]);
			++frequence[hand[i]];
			// If the current color is different to the readed. 
			if(currenColor != card[1])
				flush = false;
		}
		// Sort the hand of player 1.
		sort(hand.begin(), hand.end());
		// Research the hand.
		hand2 = handValue(flush);
		player2 = values;
		// If the value of one's hand player is lesser than the second's hand player.
		if(hand1 < hand2)
			cout << "White wins.\n";
		// If the value of second's hand player is lesser than the one's hand player.
		else if(hand1 > hand2)
			cout << "Black wins.\n";
		// If the value of one's hand player is equal to the second's hand player.
		else
		{
			// Assume that is a tie.
			bool tie = true;
			// Check the card's value.
			for(int i = player1.size() - 1; i >= 0; --i)
			{
				// If the card's value of player 1 is bigger tha the player 2 then White wins.
				if(player1[i] < player2[i])
				{
					cout << "White wins.\n";
					tie = false;
					break;
				}
				// If the card's value of player 2 is bigger tha the player 1 then White wins.
				if(player1[i] > player2[i])
				{
					cout << "Black wins.\n";
					tie = false;
					break;
				}
			}
			// If the card´s value of players are the same then is a tie.
			if(tie)
				cout << "Tie.\n";
		}
	}
	return 0;
}