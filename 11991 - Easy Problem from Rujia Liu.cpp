/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11991 - Easy Problem from Rujia Liu?
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m;
	int n;
	while(cin >> n >> m)
	{
		vector< vector<int> > numberList(1000001);
		for(int i = 0; i < n; ++i)
		{
			int number;
			cin >> number;
			numberList[number].push_back(i + 1);
		}

		for(int i = 0; i < m; ++i)
		{
			int number;
			int repetition;
			cin >> repetition >> number;
			if(numberList[number].size() < repetition)
				cout << "0\n";
			else
				cout << numberList[number][repetition - 1] << "\n";
		}
	}

	return 0;
}