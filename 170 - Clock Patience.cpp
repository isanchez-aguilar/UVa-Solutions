/*
*	User: Isanchez_Aguilar
*	Problem: UVA 170 - Clock Patience
*/
#include <bits/stdc++.h>

using namespace std;

inline int getValueCard(const string& c)
{
	if (isdigit(c[0]))
		return c[0] - '0';

	switch(c[0])
	{
		case 'A':
			return 1;
		case 'T':
			return 10;
		case 'J':
			return 11;
		case 'Q':
			return 12;
		case 'K':
			return 13;
	}

	return 0;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	while (cin >> s and s != "#")
	{
		queue<string> stackCard[13];
		
		stackCard[12].push(s);

		for (int i = 50; i >= 0; --i)
		{
			cin >> s;
			stackCard[i % 13].push(s);
		}

		int currentCard = 12;
		int exposedCards = 0;

		do
		{
			++exposedCards;
			s = stackCard[currentCard].front();

			stackCard[currentCard].pop();
			currentCard = getValueCard(s) - 1;
		} while (not stackCard[currentCard].empty());

		cout << setw(2) << setfill('0') << exposedCards << "," << s << "\n";
	}	
}