/*
*	User: Isanchez_Aguilar
*	Problem: UVA 1197 - The Suspects
*/
#include <bits/stdc++.h>

using namespace std;

class DisjointSet
{
public:
	int n;
	vector<int> rank;
	vector<int> parent;
	vector<int> height;

	DisjointSet(int _n):n(_n), parent(_n), height(_n), rank(_n)
	{
		for(int i = 0; i < n; ++i)
		{
			rank[i] = 0;
			height[i] = 1;
			parent[i] = i;
		}
	}
	inline int findParent(int element)
	{
		if(parent[element] == element)
			return element;
		return (parent[element] = findParent(parent[element]));
	}
	inline bool isSameSet(int element1, int element2){ return (findParent(element1) == findParent(element2)); }
	inline int unionSet(int element1, int element2)
	{
		int x = findParent(element1);
		int y = findParent(element2);

		if(x != y)
		{
			if(rank[x] < rank[y])
			{
				height[y] += height[x];
				parent[x] = y;
			}
			else
			{
				height[x] += height[y];
				parent[y] = x;
				if(rank[x] == rank[y])
					++rank[x];
			}
		}
	};
	inline int suspects() { return height[findParent(0)]; }
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m;
	int n;
	while(cin >> n >> m && (n || m))
	{
		DisjointSet groups(n);

		for(int i = 0; i < m; ++i)
		{
			int k;
			int first;
			cin >> k >> first;
			while(--k)
			{
				int id;
				cin >> id;
				groups.unionSet(first, id);
			}
		}
		cout << groups.suspects() << "\n";
	}

	return 0;
}