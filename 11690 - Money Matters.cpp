/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11690 - Money Matters
*/
#include <bits/stdc++.h>

using namespace std;

class DisjointSet
{
public:
	int n;
	vector<int> sum;	
	vector<int> rank;
	vector<int> checked;
	vector<int> parent;

	DisjointSet(int _n):n(_n), sum(_n), rank(_n), checked(_n), parent(_n)
	{
		for(int i = 0; i < n; ++i)
		{
			sum[i] = 0;
			rank[i] = 0;
			checked[i] = 0;
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
			
			checked[x] = 1;
			sum[y] += sum[x];
			parent[x] = y;
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

		DisjointSet friends(n);
		
		for(int i = 0; i < n; ++i)
			cin >> friends.sum[i];

		for(int i = 0; i < m ; ++i)
		{
			int a;
			int b;
			cin >> a >> b;
			friends.unionSet(a, b);
		}

		for(int i = 0; i < n; ++i)
		{
			if(!friends.checked[i] && friends.sum[i])
			{
				cout << "IM";
				break;
			}
		}
		cout << "POSSIBLE\n";
	}

	return 0;
}