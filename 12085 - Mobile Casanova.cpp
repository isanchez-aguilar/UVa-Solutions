/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12085 - Mobile Casanova
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int t = 0;
	int phoneNumbers[100001];

	while (cin >> n and n)
	{
		for (int i = 0; i < n; ++i)
			cin >> phoneNumbers[i];

		cout << "Case " << ++t << ":\n";

		for (int i = 0; i < n; ++i)
		{
			if (phoneNumbers[i] + 1 != phoneNumbers[i + 1])
				cout << "0" << phoneNumbers[i] << "\n";

			else
			{
				int currentI = i + 1;

				while (phoneNumbers[currentI] + 1 == phoneNumbers[currentI + 1])
					++currentI;

				int first = phoneNumbers[i];
				int last = phoneNumbers[currentI];

				int powerTen = 10;

				while (first - (first % powerTen) != last - (last % powerTen))
					powerTen *= 10;

				cout << "0" << phoneNumbers[i] << "-" << last % powerTen << "\n";
				
				i = currentI;
			}
		}

		cout << "\n";
	}

	return 0;
}