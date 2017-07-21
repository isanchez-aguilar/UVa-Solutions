/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10901 - Ferry Loading III
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while(testCases--)
	{
		int cars;
		int travelTime;
		int capacity;
		cin >> capacity >> travelTime >> cars;

		vector<int> totalTime(cars);
		vector< queue<int> > sides(2);
		
		for(int i = 0; i < cars; ++i)
		{
			int t;
			string side;
			cin >> t >> side;
			if(side[0] == 'l')
				sides[0].push(i);
			else
				sides[1].push(i);

			totalTime[i] = t;
		}

		int side = 0;
		int time = 0;

		while(!sides[0].empty() || !sides[1].empty())
		{
			int nextArrive;
			if(sides[0].empty())
				nextArrive = totalTime[sides[1].front()];
			else
			{
				if(sides[1].empty())
					nextArrive = totalTime[sides[0].front()];
				else
					nextArrive = min(totalTime[sides[0].front()], totalTime[sides[1].front()]);
			}

			int currentCapacity = 0;
			time = max(time, nextArrive);

			while(!sides[side].empty() && totalTime[sides[side].front()] <= time && currentCapacity < capacity)
			{
				++currentCapacity;
				totalTime[sides[side].front()] = time + travelTime;
				sides[side].pop();
			}

			time += travelTime;
			side = (side + 1) % 2;
		}

		for(int i = 0; i < cars; ++i)
			cout << totalTime[i] << "\n";

		if(testCases)
			cout << "\n";
	}	

	return 0;
}