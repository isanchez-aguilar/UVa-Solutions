/*
*	User: Isanchez_Aguilar
*	Problem: UVA 443 - Humble Numbers
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int i2 = 0;
	int i3 = 0;
	int i5 = 0;
	int i7 = 0;
	vector<int> humbles(5842);

	humbles[0] = 1;
	for (int i = 1; i < 5842; ++i)
	{
		humbles[i] = min(humbles[i2] * 2, min(humbles[i3] * 3, min(humbles[i5] * 5, humbles[i7] * 7)));

		if (humbles[i] == (humbles[i2] * 2))
			++i2;
		if (humbles[i] == humbles[i3] * 3)
			++i3;
		if (humbles[i] == humbles[i5] * 5)
			++i5;
		if (humbles[i] == humbles[i7] * 7)
			++i7;
	}

	int n;
	while (cin >> n and n)
	{
		cout << "The " << n;

		if (n % 10 == 1 and (n / 10) % 10 != 1)
			cout << "st";
		else if (n % 10 == 2 and (n / 10) % 10 != 1)
			cout << "nd";
		else if (n % 10 == 3 and (n / 10) % 10 != 1)
			cout << "rd";
		else
			cout << "th";

		cout << " humble number is " << humbles[n - 1] << ".\n";
	}

	return 0;
}