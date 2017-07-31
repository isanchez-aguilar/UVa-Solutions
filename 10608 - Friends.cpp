/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10608 - Friends
*/
#include <bits/stdc++.h>

using namespace std;

class DisjointSet
{
public:
	int n;
	int maxHeight;
	vector<int> rank;
	vector<int> height;
	vector<int> parent;

	DisjointSet(int _n):n(_n), maxHeight(1), rank(_n), height(_n), parent(_n)
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
	inline bool isSameSet(int element1, int element2){ return(findParent(element1) == findParent(element2)); }
	inline void unionSet(int element1, int element2)
	{
		if(!isSameSet(element1, element2))
		{
			int x = findParent(element1);
			int y = findParent(element2);

			if(rank[x] < rank[y])
			{
				height[y] += height[x];
				maxHeight = max(maxHeight, height[y]);
				parent[x] = y; 
			}
			else
			{
				height[x] += height[y];
				maxHeight = max(maxHeight, height[x]);
				parent[y] = x;
				if(rank[x] == rank[y])
					++rank[x];
			}
		}
	}
};

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
		DisjointSet people(n);

		while(m--)
		{
			int a;
			int b;
			cin >> a >> b;

			people.unionSet(a - 1, b - 1);
		}

		cout << people.maxHeight << "\n";
	}

	return 0;
}