/*
*	User: Isanchez_Aguilar
*	Problem: UVA 127 - "Accordian" Patience
*/
#include <bits/stdc++.h>

using namespace std;

typedef stack<string> ss;
typedef vector<ss> vss;

inline bool isValidCard(string c1, string c2)
{
	return c1[0] == c2[0] or c1[1] == c2[1];
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string current;
	while (cin >> current and current != "#")
	{
		vss piles(1);
		piles[0].push(current);

		for (int i = 1; i < 52; ++i)
		{
			cin >> current;
			
			ss p;
			p.push(current);
			piles.push_back(p);
			bool change = false;
			
			do
			{
				change = false;
				
				for (int j = 1; j < piles.size(); ++j)
				{
					current = piles[j].top();
					int currentIndex = j - 1;
					
					if (j > 2 and isValidCard(current, piles[j - 3].top()))
						currentIndex -= 2;

					string card = piles[currentIndex].top();
					if (isValidCard(card, current))
					{
						piles[currentIndex].push(current);
						piles[j].pop();

						if (piles[j].empty())
							piles.erase(piles.begin() + j);

						change = true;
						break;
					}
				}

			} while(change);
		}

		cout << piles.size() << " pile" << (piles.size() == 1?" ":"s ") <<"remaining: ";

		for (int i = 0; i < piles.size(); ++i)
		{
			cout << piles[i].size();
			
			if (i + 1 != piles.size())
				cout << " ";
		} 

		cout << "\n";
	}

	return 0;
}
