/*
*	User: Isanchez_Aguilar
*	Problem: UVA 837 - Light and Transparencies
*/
#include <bits/stdc++.h>

using namespace std;

typedef double Double;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	cout.precision(3);
	cout.setf(ios::fixed);

	while (testCases--)
	{
		int intervals;
		cin >> intervals;

		int size = 2 * intervals;
		Double weight[intervals];
		pair<Double, int> point[size];

		for (int i = 0; i < intervals; ++i)
		{
			Double y;
			cin >> point[2 * i].first >> y >> point[2 * i + 1].first >> y >> weight[i];

			point[2 * i].second = i;
			point[2 * i + 1].second = i;
		}

		set<int> pending;
		sort(point, point + size);

		cout << size + 1 << "\n";

		for (int i = 0; i <= size; ++i)
		{
			if (i == 0)
				cout << "-inf ";
			else
				cout << point[i - 1].first << " ";

			if (i == size)
				cout << "+inf ";
			else
				cout << point[i].first << " ";

			Double percentege = 1.0;

			if (i > 0 and i < size)
			{
				for (set<int>::iterator i = pending.begin(); i != pending.end(); ++i)
					percentege *= weight[*i];

			}

			if (pending.count(point[i].second) == 0)
				pending.insert(point[i].second);
			else
				pending.erase(point[i].second);

			cout << percentege << "\n";
		}

		if (testCases)
			cout << "\n";
	}

	return 0;
}