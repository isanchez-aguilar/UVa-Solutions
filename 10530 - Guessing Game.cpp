/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10530 - Guessing Game
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int number;
	// Read the number.
	while(cin >> number && number)
	{
		string answer;
		int lowest = -1;
		int highest = 11;
		cin.ignore();
		// Read the answer.
		while(getline(cin, answer) && answer[0] != 'r')
		{
			// If is too high then compare de maximum with current number.
			if(answer[4] == 'h')
				highest = min(number, highest);
			else
				lowest = max(number, lowest);
			// }read the next nummber.
			cin >> number;
			cin.ignore();
		}
		// Check If Stan is dishonest.
		if(lowest >= highest || lowest >= number || highest <= number)
			cout << "Stan is dishonest\n";
		else
			cout << "Stan may be honest\n";
	}
	return 0;
}