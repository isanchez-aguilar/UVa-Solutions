/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11242 - Tour de France
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int f;
	cout.precision(2);
	while(cin >> f && f)
	{
		int r;
		cin >> r;
		vector<int> m(f);
		vector<int> n(r);

		for(int i = 0; i < f; ++i)
			cin >> m[i];

		for(int i = 0; i < r; ++i)
			cin >> n[i];

		multiset<double> d;

		for(int i = 0; i < r; ++i)
		{
			for(int j = 0; j < f; ++j)
				d.insert((double)n[i] / (double)m[j]);
		}

		int t = 0;
		double maxSpread = 0.0;

		for(set<double>::iterator i = d.begin(); i != --d.end(); ++i)
		{
			set<double>::iterator j = i;
			maxSpread = max(maxSpread, *(++j) / *i);
		}

		cout << fixed << maxSpread << endl;
	}

	return 0;
}