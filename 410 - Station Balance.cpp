/*
*	User: Isanchez_Aguilar
*	Problem: UVA 410 - Station Balance
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int c;
	int s;
	int testCase = 0;
	while (cin >> c >> s)
	{
		double average = 0.0;
		vector<int> specimens;
			
		specimens.assign(c << 1, 0);

		for (int i = 0; i < s; ++i)
		{
			cin >> specimens[i];
			average += specimens[i];
		}

		double imbalance = 0.0;		
		sort(specimens.begin(), specimens.end());
		
		cout << "Set #" << ++testCase << "\n";
		for (int i = 0; i < c; ++i)
		{
			int j = (c << 1) - i - 1;
			cout << " " << i << ":";
			
			if (specimens[i])
				cout << " " << specimens[i];
			
			if (specimens[j])
				cout << " " << specimens[j];
			
			cout << "\n";

			imbalance += fabs((specimens[i] + specimens[j]) * c - average);
		}
		cout << setprecision(5) << fixed;
		cout << "IMBALANCE = " << (double)(imbalance / c) << "\n\n";
	}

	return 0;
}