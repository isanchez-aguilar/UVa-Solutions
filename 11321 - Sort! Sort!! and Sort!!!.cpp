/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11321 - Sort! Sort!! and Sort!!!
*/
#include <bits/stdc++.h>

using namespace std;

int m;
inline bool compare(int a, int b)
{
	if(a % m == b % m)
	{
		bool aIsOdd = 0;
		bool bIsOdd = 0;

		aIsOdd = a & 1;
		bIsOdd = b & 1;

		if(aIsOdd)
		{
			if(bIsOdd)
				return a > b;
			return 1;
		}
		if(bIsOdd)
			return 0;
		return a < b;
	}
	return (a % m) < (b % m);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >> n >> m && (m || n))
	{
		vector<int> numbers(n);
		for(int i = 0; i < n; ++i)
			 cin >> numbers[i];

		sort(numbers.begin(), numbers.end(), compare);

		cout << n << " " << m << "\n";
		for(int i = 0; i < n; ++i)
			cout << numbers[i] << "\n";
	}
	cout << "0 0\n";

	return 0;
}