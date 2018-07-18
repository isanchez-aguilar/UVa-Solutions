/*
*	User: Isanchez_Aguilar
*	Problem: UVA 144 - Student Grants
*/
#include <bits/stdc++.h>

#define id first
#define amount second

using namespace std;

typedef pair<int, int> ii;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int k;
	while (cin >> n >> k and (n or k))
	{
		queue<ii> people;
		for (int i = 1; i <= n; ++i)
			people.push(make_pair(i, 40));

		while (not people.empty())
		{
			for (int i = 1; i <= k and not people.empty(); ++i)
			{
				int coins = i;

				while (coins and not people.empty())
				{	
					ii person = people.front();

					people.pop();

					if (person.amount > coins)
					{
						person.amount -= coins;
						people.push(person);

						break;
					}
					else
					{
						cout.setf(ios::right);
						cout << setw(3) << person.id;

						coins -= person.amount;
					}
				}
			}
		}

		cout << "\n";
	}

	return 0;
}