/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10172 - The Lonesome Cargo Distributor
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int sets;
	cin >> sets;

	while(sets--)
	{
		int n;
		int s;
		int q;
		cin >> n >> s >> q;

		stack<int> carrier;
		vector< queue<int> > stations(n);
		
		for(int i = 0; i < n; ++i)
		{
			int boxes;
			cin >> boxes;

			while(boxes--)
			{
				int temp;
				cin >> temp;
				stations[i].push(temp - 1);
				
			}
		}
		int time = 0;
		bool empty = 0;
		int position = 0;

		while(!empty)
		{
			while(!carrier.empty() && (carrier.top() == position || stations[position].size() < q))
			{
				if(carrier.top() != position)
					stations[position].push(carrier.top());
			
				++time;
				carrier.pop();
			}

			while(carrier.size() < s && !stations[position].empty())
			{
				carrier.push(stations[position].front());

				++time;
				stations[position].pop();
			}

			empty = carrier.empty();

			if(empty)
			{
				for(int i = 0; i < n; ++i)
				{
					if(!stations[i].empty())
					{
						empty = 0;
						break;	
					}
				}
			}

			if(!empty)
			{
				time += 2;
				position = (position + 1) % n;
			}
		}

		cout << time << "\n";
	}

	return 0;
}