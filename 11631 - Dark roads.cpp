/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11631 - Dark roads
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
	
	int m;
	int n;
	
	while(cin >> m >> n and (m or n))
	{
		parent.resize(m);
		for(int i = 0; i < m; ++i)
			parent[i] = i;
		
		vector< pair< int, pair<int, int> > > weight;
		for(int i = 0; i < n; ++i)
		{
			int x;
			int y;
			int z;
			cin >> x >> y >> z;
			
			weight.push_back(make_pair(z, make_pair(x, y)));
		}
		
		sort(weight.begin(), weight.end());
			
		unsigned int saved = 0;
		for(int i = 0; i < (int)weight.size(); ++i)
		{
			pair< int, pair<int, int> > front = weight[i];
			
			int u = getParent(front.second.first);
			int v = getParent(front.second.second);
		
			if(u != v)
				parent[u] = v;
			else
				saved += front.first;
		}
		
		cout << saved << "\n";
	}
	
	return 0;
}
