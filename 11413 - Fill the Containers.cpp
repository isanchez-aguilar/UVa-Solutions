/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11413 - Fill the Containers
*/
#include <bits/stdc++.h>

using namespace std;

int n;
int m;
vector<int> vessel(10e3);

bool isPossible(int capacity)
{
	int usedContainers = 1;
	int currentCapacity = 0;

	for(int i = 0; i < n; ++i)
	{
		if(capacity < vessel[i] + currentCapacity)
		{
			++usedContainers;
			
			if(usedContainers > m)
				return false;

			currentCapacity = 0;
		}
		currentCapacity += vessel[i];
	}

	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> n >> m)
	{
		int left = 0;
		int right = 0;

		for(int i = 0; i < n; ++i)
		{
			cin >> vessel[i];
			right += vessel[i];
			left = max(left, vessel[i]);
		}
		if(n < m)
			cout << left << "\n";
		else
		{
			int minSize = right;
			int m = (left + right) >> 1;

			while(left < right)
			{
				if(isPossible(m))
				{
					right = m;
					minSize = m;
				}		
				else
					left = m + 1;

				m = (left + right) >> 1;
			}

			cout << minSize << "\n";
		}
	}

	return 0;
}