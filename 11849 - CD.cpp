/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11849 - CD
*/
#include <bits/stdc++.h>

using namespace std;

typedef map<int, int> mi;
typedef map<int, int>::iterator mii;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m;
	int n;

	while(cin >> n >> m && (n || m))
	{
		mi cds;
		
		for(int i = 0; i < n; ++i)
		{
			int id;
			cin >> id;

			++cds[id];
		}

		for(int i = 0; i < m; ++i)
		{
			int id;
			cin >> id;

			++cds[id];
		}

		int extras = 0;
		for(mii i = cds.begin(); i != cds.end(); ++i)
		{
			if(i->second > 1)
				++extras;
		}

		cout << extras << "\n";
	}

	return 0;
}