/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10660 - Citizen attention offices
*/
#include <bits/stdc++.h>

using namespace std;

int city[26];
int offices[5];
int tempOffices[5];
int minimumDistance;
int currentOffices = 0;

void findOptimalSolution(int area)
{
	if(currentOffices < 5)
	{
        for(int i = area; i < 25; ++i)
		{
			tempOffices[currentOffices++] = i;
			findOptimalSolution(i + 1);
			--currentOffices;
		}
	}
	else
	{
		int distance = 0;

		for(int i = 0; i < 25; ++i)
		{
			if(city[i] > 0)
			{
				int minDistance = INT_MAX;

				for(int j = 0; j < 5; ++j)
					minDistance = min(minDistance, city[i] * (abs(i % 5 - tempOffices[j] % 5) + abs(i / 5 - tempOffices[j] / 5)));			
				distance += minDistance;
			}
		}

		if(distance < minimumDistance)
		{
			minimumDistance = distance;
			memcpy(offices, tempOffices, sizeof(int) * 5);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while(testCases--)
	{
		int population;
		memset(city, 0, sizeof(int) * 25);
		
		cin >> population;
		while(population--)
		{
			int i;
			int j;
			
			cin >> j;
			cin >> i;
			cin >> city[j * 5 + i];
		}
		
		minimumDistance = INT_MAX;
		findOptimalSolution(0);

		for(int i = 0; i < 5; ++i)
			cout << offices[i] << (i == 4?'\n':' ');
	}

	return 0;
}