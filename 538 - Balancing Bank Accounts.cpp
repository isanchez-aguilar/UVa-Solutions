/*
*	User: Isanchez_Aguilar
*	Problem: UVA 538 - Balancing Bank Accounts
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, string> is;
typedef vector<is> vis;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	int people;
	int transactions;
	
	while (cin >> people >> transactions and people)
	{
		vis account(people);
		map<string, int> indexName;

		for (int i = 0; i < people; ++i)
		{
			string name;
			cin >> name;

			indexName[name] = i;
			account[i].first = 0;
			account[i].second = name;
		}

		for (int t = 0; t < transactions; ++t)
		{
			int amount;
			string personA;
			string personB;
			
			cin >> personA >> personB >> amount;

			account[indexName[personA]].first -= amount;
			account[indexName[personB]].first += amount;
		}

		sort(account.begin(), account.end());

		int i = 0;
		int j = people - 1;

		cout << "Case #" << ++t << "\n";

		while (i < j)
		{
			if (account[i].first == 0)
			{
				++i;
				continue;
			}

			if (account[j].first == 0)
			{
				--j;
				continue;
			}

			int difference = account[i].first + account[j].first;
			
			cout << account[j].second << " " << account[i].second << " ";

			if (difference < 0)
			{
				account[i].first = difference;
				cout << account[j--].first << "\n";
			}
			else if (difference > 0)
			{
				account[j].first = difference;
				cout << -account[i++].first << "\n";
			}
			else
			{
				++i;
				cout << account[j--].first << "\n";
			}
		}

		cout << "\n";
	}

	return 0;
}