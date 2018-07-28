/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12608 - Garbage Collection
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while (testCases--)
	{
		int n;
		int maxWeight;
		cin >> maxWeight >> n;

		pair<int, int> points[n];

		for (int i = 0; i < n; ++i)
			cin >> points[i].first >> points[i].second;
		
		int currentWeight = 0;;	
		int totalDistance = points[0].first;

		for (int i = 0; i < n; ++i)
		{
			if (currentWeight + points[i].second > maxWeight)
			{
				currentWeight = 0;
				totalDistance += (points[i].first << 1);
			}

			currentWeight += points[i].second;

			if (currentWeight == maxWeight)
			{
				totalDistance += points[i].first;
				
				if (i + 1 == n)
					break;
				
				currentWeight = 0;
				totalDistance += points[i].first;
			}

			if (i + 1 == n)
				totalDistance += points[i].first;
			else
				totalDistance += (points[i + 1].first - points[i].first);
		}

		cout << totalDistance << "\n";
	}

	return 0;
}