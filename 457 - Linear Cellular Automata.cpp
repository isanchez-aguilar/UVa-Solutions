/*
*	User: Isanchez_Aguilar
*	Problem: UVA 457 - Linear Cellular Automata
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int dna[10];
	int backup[40];
	int population[40];
	const char symbol[] = {' ', '.', 'x', 'W'};

	int testCases;
	cin >> testCases;

	while (testCases--)
	{
		for (int i = 0; i < 10; ++i)
			cin >> dna[i];

		memset(population, 0, sizeof population);

		population[19] = 1;

		for (int i = 0; i < 40; ++i)
			cout << symbol[population[i]];

		cout << "\n";

		for (int d = 1; d < 50; ++d)
		{
			memcpy(backup, population, sizeof population);

			for (int i = 0; i < 40; ++i)
			{
				int density = population[i];
				density += (i == 0?0:backup[i - 1]);
				density += (i + 1 == 40?0:backup[i + 1]);

				population[i] = dna[density];

				cout << symbol[population[i]]; 
			}

			cout << "\n";
		}

		if (testCases)
			cout << "\n";
	}

	return 0;
}