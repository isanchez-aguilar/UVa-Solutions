/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11461 - Square Numbers
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a;
	int b;
	while (cin >> a >> b and a and b)
	{
		int squareNumbers = 0;

		for (int i = (a == 0?1:a); i <= b; ++i)
		{
			int sqRoot = sqrt(i);
			if (sqRoot * sqRoot == i)
				++squareNumbers;
		}

		cout << squareNumbers << '\n';
	}
	return 0;
}