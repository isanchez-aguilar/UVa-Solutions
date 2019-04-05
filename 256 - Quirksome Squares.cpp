/*
*	User: Isanchez_Aguilar
*	Problem: UVA 256 - Quirksome Squares
*/
#include <bits/stdc++.h>

using namespace std;

inline bool isPerfectSquare(int n)
{
	int sqrtN = sqrt(n);

	return n == sqrtN * sqrtN;
}

inline int findNumber(int a, int lengthOfA)
{
	const int c = ceil(pow(10, lengthOfA)) - 1;
	const int r = 1 + 4 * a * c;

	int n = -1;

	if (isPerfectSquare(r))
	{
		int d = 1 + (int)sqrt(r);

		if (d % 2 == 0)
			n = a * c + d / 2;
	}

	return n;
}

inline int findLength(int n)
{
	if (n == 0)
		return 1;

	int length = 0;

	while (n > 0)
	{
		n /= 10;
		++length;
	}

	return length;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector< set<int> > quirkNumbers(9);

	for (int i = 2; i <= 8; i += 2)
		quirkNumbers[i].insert(0);

	for (int a = 0; a < 10000; ++a)
	{
		int length = findLength(a);

		while (length <= 4)
		{
			int n = findNumber(a, length);

			if (n >= 0)
				quirkNumbers[2 * length].insert(n);

			++length;
		}
	}

	int quirckLength;

	while (cin >> quirckLength)
	{
		for (int quirckNumber : quirkNumbers[quirckLength])
			cout << setw(quirckLength) << setfill('0') << quirckNumber << "\n";
	}

	return 0;
}