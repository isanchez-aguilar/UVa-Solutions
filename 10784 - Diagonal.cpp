/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10784 - Diagonal
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	long long diagonals;

	while(cin >> diagonals and diagonals)
	{
		long long n = ceil((3.0 + sqrt( 8 * diagonals + 9)) / 2.0);
		cout << "Case " << ++t << ": " << n << "\n";
	}

	return 0;
}