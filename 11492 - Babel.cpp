/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11492 - Babel
*/
#include <bits/stdc++.h>

using namespace std;

#define d first
#define node second.first
#define character second.second

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >> n and n)
	{
		string s;
		string t;
		map<string, int> index;
		vector< vector<iii> > adj;
		int gIndex = 0;
		cin >> s >> t;
		for(int i = 0; i < n; ++i)
		{
			string u;
			string v;
			string w;
			cin >> u >> v >> w;

			if(index.find(u) == index.end())
			{
				index[u] = gIndex++;
				adj.push_back(vector<iii>());
			}

			if(index.find(v) == index.end())
			{
				index[v] = gIndex++;
				adj.push_back(vector<iii>());
			}

			int indexU = index[u];
			int indexV = index[v];
			
			adj[indexU].push_back(iii(w.length(), ii(indexV, w[0] - 'a')));
			adj[indexV].push_back(iii(w.length(), ii(indexU, w[0] - 'a')));
		}

		if(index.find(s) == index.end() or index.find(t) == index.end())
			cout << "impossivel\n";
		else
		{
			int minPath = 1e6;
			int indexS = index[s];
			int indexT = index[t];
			vector<int> distance[27];
			priority_queue< iii, vector<iii>, greater<iii> > pq;


			for(int i = 0; i < 27; ++i)
				distance[i] = vector<int>(index.size(), 1e6);
			
			distance[26][indexS] = 0;	
			pq.push(iii(0, ii(indexS, 26)));

			while(not pq.empty())
			{
				iii current = pq.top();
				pq.pop();

				int u = current.node;
				int dist = current.d;
				int initialCharacter = current.character;

				if(distance[initialCharacter][u] < dist)
					continue;

				if(u == indexT)
					minPath = min(minPath, dist);

				for(int i = 0; i < adj[u].size(); ++i)
				{
					iii v = adj[u][i];

					if(v.character != initialCharacter and v.d + dist < distance[v.character][v.node])
					{
						distance[v.character][v.node] = v.d + dist;
						pq.push(iii(v.d + dist, ii(v.node, v.character)));	
					}	
				}
			}
			if(minPath < 1e6)
				cout << minPath << "\n";
			else
				cout << "impossivel\n";
		}
	}

	return 0;
}