/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10961 - Chasing After Don Giovanni
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

inline void moveStep(ii& pos, ii destination)
{
	if (pos.first != destination.first)
	{
		if (pos.first < destination.first)
			++pos.first;
		else
			--pos.first;
	}

	else
	{
		if (pos.second < destination.second)
			++pos.second;
		else
			--pos.second;
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while (testCases--)
	{
		int x;
		int y;
		vii giovanni;
		vii leporello;

		cin >> x >> y;

		giovanni.push_back(ii(x, y));
		
		cin >> x >> y;
		leporello.push_back(ii(x, y));

		int n;
		cin >> n;
		
		for (int i = 0; i < n; ++i)
		{
			cin >> x >> y;
			leporello.push_back(ii(x, y));
		}

		cin >> n;
		
		for (int i = 0; i < n; ++i)
		{
			cin >> x >> y;
			giovanni.push_back(ii(x, y));
		}

		int i = 0;
		int j = 0;
		ii posGiovanni = giovanni[0];
		ii posLeporello = leporello[0];

		while (posLeporello != posGiovanni and i + 1 < leporello.size() and j + 1 < giovanni.size())
		{
			moveStep(posLeporello, leporello[i + 1]);
			moveStep(posGiovanni, giovanni[j + 1]);

			if (posLeporello == leporello[i + 1])
				++i;

			if (posGiovanni == giovanni[j + 1])
				++j;
		}

		if (posLeporello == posGiovanni and i + 1 != leporello.size())
			cout << "No\n";
		else
			cout << "Yes\n";

		if (testCases)
			cout << "\n";
	}

	return 0;
}