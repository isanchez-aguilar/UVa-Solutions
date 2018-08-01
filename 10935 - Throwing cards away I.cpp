/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10935 - Throwing cards away I
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while (cin >> n and n)
	{
		queue<int> deck;

		for (int i = 1; i <= n; ++i)
			deck.push(i);

		vector<int> discarded;

		while (deck.size() > 1)
		{
			discarded.push_back(deck.front());
			deck.pop();
			
			deck.push(deck.front());
			deck.pop();			
		}

		cout << "Discarded cards:";

		for (int i = 0; i < discarded.size(); ++i)
			cout << (i == 0?" ":", ") << discarded[i];

		cout << "\nRemaining card: " << deck.front() << "\n";
	}

	return 0;
}