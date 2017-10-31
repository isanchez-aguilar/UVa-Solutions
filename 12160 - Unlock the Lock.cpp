/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12160 - Unlock the Lock
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int L;
	int U;
	int R;
	int t = 0;
	int number[10];
	bool visited[10000];

	while(cin >> L >> U >> R and (L or U or R))
	{
		for(int i = 0; i < R; ++i)
			cin >> number[i];

		memset(visited, false, sizeof visited);

		int moves = -1;
		queue< pair<int, int> > node;
		
		visited[L] = true;
		node.push(make_pair(L, 0));

		while(not node.empty())
		{
			pair<int, int> u = node.front();
			
			node.pop();
			if(u.first == U)
			{
				moves = u.second;
				break;
			}

			for(int i = 0; i < R; ++i)
			{
				int v = (u.first + number[i]) % 10000;

				if(not visited[v])
				{
					visited[v] = true;
					node.push(make_pair(v, u.second + 1));
				}
			}
		}

		if(moves == -1)
			cout << "Case " << ++t << ": Permanently Locked\n";
		else 
			cout << "Case " << ++t << ": " << moves << "\n";
	}
	
	return 0;
}