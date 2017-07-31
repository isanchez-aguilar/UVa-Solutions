/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11550 - Demanding Dilemma
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
		int m;
		int n;
		cin >> n >> m;

		vector< vector<int> > edges(m);		
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				int a;
				cin >> a;
				if(a)
					edges[j].push_back(i);
			}
		}

		bool yes = 1;
		for(int j = 0; j < m; ++j)
		{
			if(edges[j].size() != 2)
			{
				yes = 0;
				break;
			}
		}

		if(yes)
		{
			set< pair<int, int> > verticesPair;
			
			for(int j = 0; j < m; ++j)
				verticesPair.insert(make_pair(edges[j][0], edges[j][1]));
			
			if(verticesPair.size() != m)
				cout << "No\n";
			else
				cout << "Yes\n";
		}
		else
			cout << "No\n";
	}

	return 0;
}