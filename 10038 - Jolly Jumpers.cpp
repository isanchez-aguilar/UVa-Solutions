/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10038 - Jolly Jumpers
*/
#include <bits/stdc++.h>

using namespace std;

bool differences[3000];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while (cin >> n)
	{
		int previous = -3000;
		fill(differences, differences + n, false);
		
		for (int i = 0; i < n; ++i)
		{
			int current;
			cin >> current;
			int difference = abs(current - previous);

			if (difference > 0 and difference < n)
				differences[difference] = true;
			
			previous = current;
		}

		if (count(differences, differences + n, true) == n - 1)
			cout << "Jolly\n";
		else
			cout << "Not jolly\n";
	}

	return 0;
}