/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10978 - Let's Play Magic!
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int cards;
	while(cin >> cards && cards)
	{
		string name;
		string word;
		int currentIndex = -1;
		vector<string> deck(cards, "");

		for(int i = 0; i < cards; ++i)
		{
			cin >> name >> word;
			
			int length = word.length();
			
			while(length)
			{
				currentIndex = (currentIndex + 1) % cards;
				if(deck[currentIndex] == "")
					--length;
			}

			deck[currentIndex] = name;

		}

		for(int i = 0; i < cards; ++i)
			cout << deck[i] << (i + 1 < cards?" ":"\n");
	}

	return 0;
}