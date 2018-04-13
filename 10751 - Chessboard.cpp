/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10751 - Chessboard
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;
	
	while (testCases--)
	{
		int n;
		cin >> n;
		
		if (n == 1)
			cout << "0.000\n";
		else
		{
			int straightLines = (n - 1) << 2;
			int diagonals = n * n - straightLines;
			double ans = straightLines + diagonals * sqrt(2.0);
			cout << fixed << setprecision(3) << ans << "\n";
		}

		if (testCases)
			cout << "\n";
	}

	return 0;
}