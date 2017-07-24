/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10507 - Waking up brain
*/
#include <bits/stdc++.h>

using namespace std;

class DisjointSet
{
public:
	int n;
	vector<int> parent;
	vector<int> height;

	DisjointSet(int _n):n(_n), parent(_n), height(_n)
	{
		for(int i = 0; i < _n; ++i)
		{
			parent[i] = i;
			height[i] = 1;
		}
	}
	inline int findParent(int element)
	{
		if(parent[element] == element)
			return element;

		return (parent[element] = findParent(parent[element]));
	}
	inline bool isSameSet(int element1, int element2){ return (findParent(element1) == findParent(element2)); }
	inline void unionSet(int element1, int element2)
	{
		if(!isSameSet(element1, element2))
		{
			int x = findParent(element1);
			int y = findParent(element2);

			if(height[x] < height[y])
				parent[x] = y;
			else
			{
				parent[y] = x;

				if(height[x] == height[y])
					++height[x];
			}
		}
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	vector<int> adj[27];
	
	while(cin >> n)
	{
		int connections;
		cin >> connections;

		DisjointSet awake(27);
		map<char, int> indexs;

		string awakeAreas;
		cin >> awakeAreas;

		awake.unionSet(1, 2);
		awake.unionSet(2, 3);

		for(int i = 0; i < 3; ++i)
			indexs[awakeAreas[i]] = i + 1;

		for(int i = 0; i < 27; ++i)
			adj[i].clear();

		for(int i = 0, currentIndex = 4; i < connections; ++i)
		{
			char a;
			char b;
			cin >> a >> b;

			int j;
			int k;

			if(!indexs[a])
				indexs[a] = currentIndex++;
			if(!indexs[b])
				indexs[b] = currentIndex++;

			j = indexs[a];
			k = indexs[b];

			adj[j].push_back(k);
			adj[k].push_back(j);
		}

		int years = -1;
		int previousAwake = 1;
		int currentAwake  = 3;

		while(previousAwake < currentAwake)
		{
			++years;
			previousAwake = currentAwake;
			vector<int> neighborsOfAwake;

			for(int i = 4; i <= n; ++i)
			{
				if(awake.isSameSet(i, 1))
					continue;

				int size = adj[i].size();
				int awakeNeighbors = 0;

				for(int j = 0; j < size; ++j)
				{
					if(awake.isSameSet(adj[i][j], 1))
						++awakeNeighbors;
				}
				if(3 <= awakeNeighbors)
					neighborsOfAwake.push_back(i);
			}

			int size = neighborsOfAwake.size();
			
			for(int i = 0; i < size; ++i)
				awake.unionSet(neighborsOfAwake[i], 1);

			neighborsOfAwake.clear();
			currentAwake = 0;
			for(int i = 1; i <= n; ++i)
			{
				if(awake.isSameSet(i, 1))
					++currentAwake;
			}

		}

		if(currentAwake == n)
			cout << "WAKE UP IN, " << years << ", YEARS\n";
		else
			cout << "THIS BRAIN NEVER WAKES UP\n";
	}

	return 0;
}