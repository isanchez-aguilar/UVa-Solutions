/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10158 - War
*/
#include <bits/stdc++.h>

using namespace std;

class DisjointSet
{
public:
	int n;
	vector<int> rank;
	vector<int> parent;

	DisjointSet(int _n):n(_n), rank(_n), parent(_n)
	{
		for(int i = 0; i < n; ++i)
		{
			rank[i] = 0;
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
				parent[x] = y;
			else
			{
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

	int n;
	cin >> n;

	int c;
	int x;
	int y;
	DisjointSet people(n << 1);
	while(cin >> c >> x >> y && (c || x || y))
	{
		switch(c)
		{
			case 1:
				if(people.isSameSet(x, y + n))
					cout << "-1\n";
				else
				{
					people.unionSet(x, y);
					people.unionSet(x + n, y + n);
				}
			break;
			case 2:
				if(people.isSameSet(x, y))
					cout << "-1\n";
				else
				{
					people.unionSet(x, y + n);
					people.unionSet(x + n, y);
				}
			break;
			case 3:
				cout << people.isSameSet(x, y) << "\n";
			break;
			default:
				cout << people.isSameSet(x, y + n) << "\n";

		}
	}
	return 0;
}