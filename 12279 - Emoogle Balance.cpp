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
	// Variable to know the number of case.
	int caseNumber = 1;
	// Variable to save the number of events.
	int numberEvents;
	// Read while there are events.
	while(cin >> numberEvents and numberEvents != 0)
	{
		// Variable to save the emoogle balance.
		int emoogleBalance = 0;
		// Variable to save the description of event.
		int descriptionEvent;
		// Read the description of events.
		for(int i = 0; i < numberEvents; ++i)
		{
			// Read the description of event.
			cin >> descriptionEvent;
			// If supposed to give a treat.
			if(descriptionEvent != 0)
				++emoogleBalance;
			// If has given a treat.
			else
				--emoogleBalance;
		}
		// Print the emoogle balance.
		cout << "Case " << caseNumber++ << ": " << emoogleBalance << "\n";
	}
	return 0;
}
