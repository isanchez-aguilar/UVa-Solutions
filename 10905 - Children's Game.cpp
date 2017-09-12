/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10905 - Children's Game
*/
#include <bits/stdc++.h>

using namespace std;

inline bool comp(const string a, const string b){ return (b + a) < (a + b); }

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >> n and n)
	{
		vector<string> numbers(n);
		
		for(int i = 0; i < n; ++i)
			cin >> numbers[i];

		sort(numbers.begin(), numbers.end(), comp);

		for(int i = 0; i < n; ++i)
			cout << numbers[i];

		cout << "\n";
	}

	return 0;
}