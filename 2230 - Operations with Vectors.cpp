/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10489 - Boxes of Chocolates
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int minSum = 0;
	vector<int> a(n);
	vector<int> b(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
		minSum += a[i] * b[i];
	}

	sort(b.begin(), b.end());

	do
	{
		int currentSum = 0;

		for (int i = 0; i < n; ++i)
			currentSum += a[i] * b[i];

		minSum = min(minSum, currentSum); 
	} while (next_permutation(b.begin(), b.end()));

	cout << minSum << "\n";

	return 0;
}
