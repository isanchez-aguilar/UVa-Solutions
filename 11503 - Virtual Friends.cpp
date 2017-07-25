/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11503 - Virtual Friends
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
			{
				parent[x] = y; 
				height[y] += height[x];
			}
			else
			{
				parent[y] = x;
				height[x] += height[y];
			}
		}
	}
	inline int getSize(int element)
	{
		return height[findParent(element)];
	}
};

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while(testCases--)
	{
		int index = 0;
		int friendships;
		map<string, int> names;
		DisjointSet socialNetwork(100002);
		
		cin >> friendships;
		for(int i = 0; i < friendships; ++i)
		{
			string name1;
			string name2;
			cin >> name1 >> name2;

			if(!names[name1])
				names[name1] = ++index;
			if(!names[name2])
				names[name2] = ++index;
			
			int j = names[name1];
			int k = names[name2];

			socialNetwork.unionSet(j, k);
			cout << socialNetwork.getSize(k) << "\n";			
		}
	}

	return 0;
}