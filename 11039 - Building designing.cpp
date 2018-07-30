/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11039 - Building designing
*/
#include <bits/stdc++.h>

using namespace std;

int p;
pair<int, int> floors[500000];

inline int searchLongest(int colour)
{
	int length = 0;
	int currentColour = 1 - colour;

	for (int i = 0; i < p; ++i)
	{	
		if (floors[i].second == currentColour)
		{
			++length;
			currentColour = 1 - currentColour;
		}
	}

	return length;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while (testCases--)
	{
		cin >> p;

		for (int i = 0; i < p; ++i)
		{
			int value;
			cin >> value;
			floors[i] = make_pair(abs(value), value < 0);
		}
		
		sort(floors, floors + p, greater< pair<int, int> >());

		cout << max(searchLongest(0), searchLongest(1)) << "\n";
	}

	return 0;
}