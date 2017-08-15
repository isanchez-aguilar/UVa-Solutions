/*
*	User: Isanchez_Aguilar
*	Problem: UVA 1237 - Expert Enough?
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while(testCases--)
	{
		int c;
		cin >> c;
		vector< pair<string, pair<int, int> > > data(c);

		for(int i = 0; i < c; ++i)
		{
			int l;
			int h;
			string s;
			cin >> s >> l >> h;
			data[i] = make_pair(s, make_pair(l, h)); 
		}

		int q;
		cin >> q;
		for(int i = 0; i < q; ++i)
		{
			int price;
			int j = -1;

			cin >> price;
			for(int k = 0; k < c; ++k)
			{
				pair<int, int> temp(data[k].second);
				if(temp.first <= price && price <= temp.second)
				{
					if(j != -1)
					{
						j = -1;
						break;
					}

					j = k;
				}
			}
			if(j == -1)
				cout << "UNDETERMINED\n";
			else
				cout << data[j].first << "\n";
		}
		if(testCases)
			cout << "\n";
	}

	return 0;
}