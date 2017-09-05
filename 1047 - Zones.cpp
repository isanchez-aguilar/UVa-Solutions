/*
*	User: Isanchez_Aguilar
*	Problem: UVA 1047 - Zones
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int build;
	int t = 0;

	while(cin >> n >> build and (n or build))
	{
		int combination = 0;
		vector<int> poles(n);
		int maximumCustomers = -1;

		for(int i = 0; i < n; ++i)
			cin >> poles[i];

		int relations;
		cin >> relations;

		vector< pair<int, int> > intersection(relations);
		for(int i = 0; i < relations; ++i)
		{
			int value;
			int neighbors;
			int status = 0;

			cin >> neighbors;
			for(int j = 0; j < neighbors; ++j)
			{
				int index;
				cin >> index;
				status |= (1 << --index);
			}
			
			cin >> value;
			intersection[i] = make_pair(status, value);
		}

		int size = 1 << n;
		for(int i = 0; i < size; ++i)
		{
			int currentPoles = 0;
			for(int j = 0; j < n; ++j)
			{
				if(i & (1 << j))
					++currentPoles;
			}

			if(currentPoles != build)
				continue;

			int ans = 0;
			for(int j = 0; j < n; ++j)
			{
				if(i & (1 << j))
					ans += poles[j];
			}

			for(int j = 0; j < relations; ++j)
			{
				int intersections = 0;
				int match = intersection[j].first & i;
				
				for(int k = 0; k < n; ++k)
				{
					if(match & (1 << k))
						++intersections;
				}

				if(intersections - 1 > 0)
					ans -= (intersections - 1) * intersection[j].second;
			}

			if(maximumCustomers < ans)
			{
				combination = i;
				maximumCustomers = ans;
			}
			else if(maximumCustomers == ans)
			{
				for(int j = 0; j < n; ++j)
				{
					int a = i & (1 << j);
					int b = combination & (1 << j);
					
					if(a != b)
					{
						if(a)
						{
							combination = i;
							maximumCustomers = ans;
						}
						break;
					}
				}
			}
		}

		cout << "Case Number  " << ++t << "\n";
		cout << "Number of Customers: " << maximumCustomers << "\n";
		cout << "Locations recommended:";
		for(int i = 0; i < n; ++i)
		{
			if(combination & (1 << i))
				cout << " " << i + 1;
		}
		cout << "\n\n";
	}

	return 0;
}