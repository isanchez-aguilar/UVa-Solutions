/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10600 - ACM Contest and Blackout
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> parent;

inline int getParent(int u)
{
	return (parent[u] == u?u:parent[u] = getParent(parent[u]));
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while(testCases--)
	{
		int n;
		int m;
		cin >> n >> m;

		parent.resize(++n);
		for(int i = 1; i < n; ++i)
			parent[i] = i;

		vector< pair< int, pair<int, int> > > w;

		for(int i = 0; i < m; ++i)
		{
			int a;
			int b;
			int weight;
			cin >> a >> b >> weight;
			w.push_back(make_pair(weight, make_pair(a, b)));
		}

		sort(w.begin(), w.end());

		int cheapest = 0;
		vector<int> tree;

		for(int i = 0; i < m; ++i)
		{
			pair< int, pair< int, int> > front = w[i];

			int u = getParent(front.second.first);
			int v = getParent(front.second.second);
			if(u != v)
			{
				cheapest += front.first;
				tree.push_back(i);
				parent[u] = v;
			}
		}

		int secondCheap = INT_MAX;
		for(int i = 0; i < (int)tree.size(); ++i)
		{
			int edge = tree[i];

			for(int i = 1; i < n; ++i)
				parent[i] = i;

			int cheap = 0;
			int components = 0;
			for(int i = 0; i < m; ++i)
			{

				if(i != edge)
				{	
					pair< int, pair< int, int> > front = w[i];
					int u = getParent(front.second.first);
					int v = getParent(front.second.second);
					if(u != v)
					{
						++components;
						parent[u] = v;
						cheap += front.first;
					}
				}
			}

			if(components == tree.size())
				secondCheap = min(secondCheap, cheap);
		}

		cout << cheapest << " " << secondCheap << "\n";
	}

	return 0;
}
