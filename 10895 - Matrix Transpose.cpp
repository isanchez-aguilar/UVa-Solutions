/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10895 - Matrix Transpose
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m;
	int n;

	while(cin >> m >> n)
	{
		vector< list< pair<int,int > > > transpose(n);
		vector< vector<int> > matrix(m, vector<int>(n));
		
		for(int i = 0; i < m; ++i)
		{
			int r;
			cin >> r;
			vector<int> indexs(r);

			for(int j = 0; j < r; ++j)
			{
				int index;
				cin >> index;
				indexs[j] = index - 1;
			}

			for(int j = 0; j < r; ++j)
			{
				int element;
				cin >> element;
				matrix[i][indexs[j]] = element;
				transpose[indexs[j]].push_front(make_pair(element, i + 1));
			}
		}

		cout << n << " " << m << "\n";

		for(int i = 0; i < n; ++i)
		{
			cout << transpose[i].size();
			transpose[i].reverse();
			for(list< pair<int, int> >::iterator j = transpose[i].begin(); j != transpose[i].end(); ++j)
				cout << " " << j->second;
			cout << "\n";
			for(list< pair<int, int> >::iterator j = transpose[i].begin(); j != transpose[i].end();)
			{
				cout << j->first;
				if(++j != transpose[i].end())
					cout << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}