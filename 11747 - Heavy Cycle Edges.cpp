/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11747 - Heavy Cycle Edges
*/
#include<bits/stdc++.h>

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
	
	int n;
	int m;
	
	while(cin >> n >> m and (n or m))
	{
		parent.resize(n);
		
		for(int i = 0; i < n; ++i)
			parent[i] = i;
		
		vector< pair< int, pair<int, int> > > weight;
		
		for(int i = 0; i < m; ++i)
		{
			int a;
			int b;
			int w;
			cin >> a >> b >> w;
			
			weight.push_back(make_pair(w, make_pair(a, b)));
		}
		
		queue<int> w;
		sort(weight.begin(), weight.end());
		
		for(int i = 0; i < (int)weight.size(); ++i)
		{
			pair< int, pair<int, int> > front = weight[i];
			
			int u = getParent(front.second.first);
			int v = getParent(front.second.second);
			
			if(u != v)
				parent[u] = v;
			
			else
				w.push(front.first);
		}
		
		if(w.empty())
			cout << "forest\n";
		else
		{
			while(not w.empty())
			{
				cout << w.front();
				w.pop();
				cout << (w.empty()?"\n":" ");
			}
		}
	}
	
	return 0;
}
