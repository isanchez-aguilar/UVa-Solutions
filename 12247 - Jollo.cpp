/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12247 - Jollo
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> prince(2);
	vector<int> princess(3);
	// Read while the card is not zero.
	while(cin >> princess[0] && princess[0])
	{
		int card = 0;
		// Read the princess's card.
		for(int i = 1; i < 3; ++i)
			cin >> princess[i];
		// Sort the princess's card.
		sort(princess.begin(), princess.end());
		// Read the prince's card.
		cin >> prince[0] >> prince[1];
		// Sort the prince's card.
		sort(prince.begin(), prince.end());
		// If the maximum card of princess is lesser than the maximum card of prince.
		if(princess[2] < prince[1])
		{
			// If the middle card of the princess is lesser than the minimum of prince.
			if(princess[1] < prince[0])
			{
				/* 
				* If the maximum card of princess is lesser than the
				* minimum of prince then the card's value is 1.
				*/
				if(princess[2] < prince[0])
					card = 1;
				/* 
				* If the maximum card of princess is bigger or equal than the
				* minimum card of prince then the card's value is the value of the
				* middle card of princess.
				*/
				else
					card = princess[1] + 1;
			}
			/* If the middle card of the princess is bigger or equal than the minimum
			* of prince the the card's value is the value of the maximum card of the 
			* princess plus one.
			*/
			else
				card = princess[2] + 1;
			// While the card's value is not available then increase the value.
			while(binary_search(princess.begin(), princess.end(), card) || binary_search(prince.begin(), prince.end(), card))
				++card;
			// If the card is bigger than 52(maximum value) or is not available then is impossible win.
			if(card > 52 || binary_search(princess.begin(), princess.end(), card) || binary_search(prince.begin(), prince.end(), card))
				cout << -1 << '\n';
			// If the card is lesser than 52(maximum value) or is available then print the lowest card to win.
			else
				cout << card << '\n';
		}
		// If the maximum card of princess is bigger or equal than the maximum card of prince.
		else
		{
			// If the minimum card of princess is bigger than the maximum card of prince then is impossible win.
			if(prince[1] < princess[0])
				cout << -1 << '\n';
			// If the minimum card of princess is bigger than the maximum card of prince then is impossible win.
			else
			{
				// If the middle card of princess is bigger than the maximum card of prince or minimum card then is impossible win.
				if(prince[1] < princess[1] || prince[0] < princess[1])
					card = -1;
				/* If the middle card of princess is not bigger than the maximum card of prince or minimum card the
				* card's value is the value of the middle card of princess. 	
				*/
				else
					card = princess[1] + 1;
				// While the card's value is not available then increase the value.
				while(binary_search(princess.begin(), princess.end(), card) || binary_search(prince.begin(), prince.end(), card))
					++card;
				// If the card is bigger than 52(maximum value) or is not available then is impossible win.
				if(card > 52 && binary_search(princess.begin(), princess.end(), card) || binary_search(prince.begin(), prince.end(), card))
					cout << -1 << '\n';
				// If the card is lesser than 52(maximum value) or is available then print the lowest card to win.
				else
					cout << card << '\n';
			}
		}
	}
	return 0;
}