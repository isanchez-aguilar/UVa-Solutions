/*
*	User: Isanchez_Aguilar
*	Problem: UVA 514 - Rails
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int t = 0;
	while(cin >> n && n)
	{		
		int temp;
		while(cin >> temp && temp)
		{
			queue<int> in;
			in.push(temp);

			for(int i = 1; i < n; ++i)
			{
				cin >> temp;
				in.push(temp);
			}

			bool possible = 1;
			int nextLarger = 1;
			stack<int> order;

			while(!in.empty())
			{
				int current = in.front();
			
				in.pop();
				if(nextLarger <= current)
				{
					for(int i = nextLarger; i < current; ++i)
						order.push(i);

					nextLarger = current + 1;
					continue;
				}
				if(!order.empty() && order.top() == current)
					order.pop();
				else
				{
					possible = 0;
					break;
				}
			}

			if(possible)
				cout << "Yes\n";
			else
				cout << "No\n";
		}
		cout << "\n";
	}
	return 0;
}