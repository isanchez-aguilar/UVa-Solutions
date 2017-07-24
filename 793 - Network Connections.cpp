/*
*	User: Isanchez_Aguilar
*	Problem: UVA 793 - Network Connections
*/
#include <bits/stdc++.h>

using namespace std;

class DisjointSet
{
public:
	int n;
	vector<int> parent;
	vector<int> height;
	
	DisjointSet(int _n):n(_n),parent(_n), height(_n)
	{
		for(int i = 0; i < n; ++i)
		{
			parent[i] = i;
			height[i] = i;
		}
	}

	inline int findParent(int element)
	{
		if(parent[element] == element)
			return element;

		return (parent[element] = findParent(parent[element]));
	}

	inline bool isSameset(int element1, int element2) { return (findParent(element1) == findParent(element2)); }

	inline void unionSet(int element1, int element2)
	{
		if(!isSameset(element1, element2))
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

	int testCases;
	cin >> testCases;

	while(testCases--)
	{
		int n;
		int good = 0;
		int wrong = 0;
		
		cin >> n;
		cin.ignore();

		string data;
		DisjointSet network(n);

		while(getline(cin, data) && data.length() > 1)
		{
			char action;
			int computer1;
			int computer2;
			istringstream in(data);

			in >> action >> computer1 >> computer2;

			if(action == 'c')
				network.unionSet(--computer1, --computer2);
			else
			{
				if(network.isSameset(--computer1, --computer2))
					++good;
				else
					++wrong;
			}
		}

		cout << good << "," << wrong << "\n";
		if(testCases)
			cout << "\n";
	}

	return 0;
}