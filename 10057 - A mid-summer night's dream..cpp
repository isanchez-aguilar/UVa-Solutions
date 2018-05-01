/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10057 - A mid-summer night's dream.
*/
#include <bits/stdc++.h>

#define MAX 65537

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int data[MAX];
	while (cin >> n)
	{
		fill(data, data + MAX, 0);
		for (int i = 0; i < n; ++i)
		{
			int m;
			cin >> m;
			++data[m];
		}

		int m = (n >> 1);
		int numbers = 0;
		vector<int> median;
		bool insert = true;
		bool isOdd = (n & 1) != 0;
		
		for (int i = 0, j = 0; i < MAX; ++i)
		{
			if (not data[i])
				continue;
			j += data[i];

			if (insert and j >= m)
			{
				insert = false;
				median.push_back(i);
				
				if (not isOdd)
					numbers += data[i];
			}
			if (j >= m + 1)
			{
				if (isOdd or i != median[0])
					numbers += data[i];
				median.push_back(i);
				break;
			}
		}

		if (isOdd)
			cout << median[1] << " " << numbers << " 1\n";
		else
			cout << median[0] << " " << numbers << " " << (median[0] == median[1]?1:median[1] - median[0] + 1) << "\n";
	}

	return 0;
}