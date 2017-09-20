/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11100 - The Trip, 2007
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int knapsacks;
	int dimension[10001];

	while(cin >> knapsacks and knapsacks)
	{
		for(int i = 0; i < knapsacks; ++i)
			cin >> dimension[i];

		int maxRepetitions = 0;
		int currentRepetitions = 1;
		sort(dimension, dimension + knapsacks);

		dimension[knapsacks] = 0;
		for(int i = 0; i < knapsacks; ++i)
		{
			if(dimension[i] == dimension[i + 1])
			{
				++currentRepetitions;
				continue;
			}

			maxRepetitions = max(maxRepetitions, currentRepetitions);
			currentRepetitions = 1;
		}

		cout << maxRepetitions << "\n";

		for(int i = 0; i < maxRepetitions; ++i)
		{
			for(int j = i; j < knapsacks; j += maxRepetitions)
			{
				if(j != i)
					cout << " ";
				cout << dimension[j];
			}
			cout << "\n";
		}

	}

	return 0;
}