/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10583 - Ubiquitous Religions
*/
#include <bits/stdc++.h>

using namespace std;

class DisjointSet
{
public:
	int n;
	vector<int> rank;
	vector<int> height;
	vector<int> parent;

	DisjointSet(int _n):n(_n), rank(_n), height(_n), parent(_n)
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
			}
			else
			{
				height[x] += height[y];
				parent[y] = x;
				if(rank[x] == rank[y])
					++rank[x];
			}
		}
	}
	inline int getReligions()
	{
		int religions = 0;
		for(int i = 0; i < n; ++i)
		{
			if(parent[i] == i)
				++religions;
		}
		return religions;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m;
	int n;
	int t = 1;
	while(cin >> n >> m && (n || m))
	{
		DisjointSet students(n);
		while(m--)
		{
			int a;
			int b;
			cin >> a >> b;
			students.unionSet(a - 1, b - 1);
		}

		cout << "Case " << t++ << ": " << students.getReligions() << "\n";
	}

	return 0;
}