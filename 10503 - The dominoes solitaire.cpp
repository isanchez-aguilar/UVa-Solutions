/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10503 - The dominoes solitaire
*/
#include <bits/stdc++.h>

using namespace std;

int m;
bitset<14> used;
pair<int, int> pieces[14];

inline bool findSolution(int size, pair<int, int> values)
{
	if(!size)
		return (values.first == values.second);
	if(size == 1)
	{
		for(int i = 0; i  < m; ++i)
		{
			if(not used[i])
			{
				if((pieces[i].first == values.first and pieces[i].second == values.second) or
					(pieces[i].first == values.second and pieces[i].second == values.first))
					return true;
			}
		}

		return false;
	}
	
	bool possible = false;

	for(int i = 0; i  < m && not possible; ++i)
	{
		if(not used[i])
		{
			pair<int, int> temp;
			
			if(pieces[i].first == values.first)
				temp.first = pieces[i].second;
			else if(pieces[i].second == values.first)
				temp.first = pieces[i].first;
			else
				continue;
			
			used[i] = true;
			for(int j = 0; j < m && not possible; ++j)
			{
				if(not used[j])
				{
					if(pieces[j].first == values.second)
						temp.second = pieces[j].second;
					else if(pieces[j].second == values.second)
						temp.second = pieces[j].first;
					else
						continue;

					used[j] = true;
					possible = findSolution(size - 2, temp);
					used[j] = false;		
				}
			}
			used[i] = false;
		}
	}	

	return possible;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >> n && n)
	{
		int ignore;
		pair<int, int> values;

		cin >> m;
		cin >> ignore >> values.first;
		cin >> values.second >> ignore;

		for(int i = 0; i < m; ++i)
			cin >> pieces[i].first >> pieces[i].second;
	
		if(findSolution(n, values))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}