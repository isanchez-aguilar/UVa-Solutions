/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11752 - The Super Powers
*/
#include <bits/stdc++.h>

#define MAX 18446744073709551615ULL

typedef unsigned long long ull;

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	set<ull> superPowerNumber;
	const int primePowers[18] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};

	bitset<65> indivisible;

	for (int i = 17; i > -1; --i)
		indivisible[primePowers[i]] = true;

	superPowerNumber.insert(1);

	ull i = 2;
	while (true)
	{
		ull currentNumber = MAX;

		int power = -1;
		while (currentNumber)
		{
			currentNumber /= i; 
			++power;
		}

		if (power < 4)
			break;

		currentNumber = i;

		for (int p = 2; p <= power; ++p)
		{
			currentNumber *= i;

			if (not indivisible[p])
				superPowerNumber.insert(currentNumber);
		}

		++i;
	}

	for (set<ull>::iterator n = superPowerNumber.begin(); n != superPowerNumber.end(); ++n)
		cout << *n << "\n";

	return 0;
}