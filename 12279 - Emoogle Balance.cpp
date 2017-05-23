/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12279 - Emoogle Balance
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Variable to save the number of events.
	int numberEvents;
	// Variable to know the number of case.
	int i = 1;
	// Read the nummber of events.
	cin >> numberEvents;
	// Read while there are events.
	while(numberEvents)
	{
		// Variable to save the emoogle balance.
		int emoogleBalance = 0;
		// Variable to save the description of event.
		int descriptionEvent;
		// Read the description of events.
		for(int j = 0; j < numberEvents; ++j)
		{
			// Read the description of event.
			cin >> descriptionEvent;
			// If supposed to give a treat.
			if(descriptionEvent)
				++emoogleBalance;
			// If has given a treat.
			else
				--emoogleBalance;
		}
		// Print the emoogle balance.
		cout << "Case " << i++ << ": " << emoogleBalance << "\n";
		// Read the nummber of events.
		cin >> numberEvents;
	}
	return 0;
}	