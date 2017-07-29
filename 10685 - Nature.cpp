/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10685 - Nature
*/
#include <bits/stdc++.h>

using namespace std;

class DisjointSet
{
public:
	int n;
	int maxHeight;
	vector<int> rank;
	vector<int> parent;
	vector<int> height;

	DisjointSet(int _n):n(_n), rank(_n), parent(_n), height(_n), maxHeight(1)
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
	inline bool isSameSet(int element1, int element2) { return (findParent(element1) == findParent(element2)); }
	inline void unionSet(int element1, int element2)
	{
		if(!isSameSet(element1, element2))
		{
			int x = findParent(element1);
			int y = findParent(element2);

			if(rank[x] < rank[y])
			{
				height[y] += height[x];
				parent[x] = y;
				maxHeight = max(maxHeight, height[y]);
			}
			else
			{
				height[x] += height[y];
				parent[y] = x;
				maxHeight = max(maxHeight, height[x]);

				if(rank[x] == rank[y])
					++rank[x];
			}
		}
	}
	inline int getMax() { return maxHeight; }
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int c;
	int r;
	while(cin >> c >> r && (c || r))
	{
		DisjointSet chain(c);
		map<string, int> indexs;
		for(int i = 0; i < c; ++i)
		{
			string name;
			cin >> name;
			indexs[name] = i;
		}

		for(int i = 0; i < r; ++i)
		{
			string big;
			string small;

			cin >> small >> big;

			chain.unionSet(indexs[small], indexs[big]);
		}

		cout << chain.getMax() << "\n";
	}

	return 0;
}