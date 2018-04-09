/*
*	User: Isanchez_Aguilar
*	Problem: UVA 616 - Coconuts, Revisited
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int coconuts;
	
	while (cin >> coconuts and coconuts > -1)
	{
		int p = -1;
		int sqrtCoconuts = ceil(sqrt(coconuts));
	
		for (int people = sqrtCoconuts; people > 0; --people)
		{
			bool correct = true;
			int currentCoconuts = coconuts;
			
			for (int currentPerson = 0; currentPerson < people; ++currentPerson)
			{
				if (currentCoconuts % people != 1)
				{
					correct = false;
					break;
				}

				currentCoconuts = currentCoconuts / people * (people - 1);
			}

			if (correct and currentCoconuts % people == 0)
			{
				p = people;
				break;
			}
		}

		cout << coconuts << " coconuts, ";

		if (p == -1)
			cout << "no solution\n";
		else
			cout << p << " people and 1 monkey\n";
	}
	return 0;
}