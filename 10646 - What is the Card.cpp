/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10646 - What is the Card?
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Read the number of test cases.
	int testCases;
	cin >> testCases;
	// Read the test cases.
	for(int j = 1; j <= testCases; ++j)
	{
		vector<string> deck(52);
		// Read the cards from the deck.
		for(int i = 0; i < 52; ++i)
			cin >> deck[i];
		// After executing three times the steps the Y-th letter is the 33.
		cout << "Case " << j << ": " << deck[32] << endl;
	}
	return 0;
}