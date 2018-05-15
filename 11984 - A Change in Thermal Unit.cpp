/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11984 - A Change in Thermal Unit
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int testCases;
	cin >> testCases;
	
	for (int t = 1; t <= testCases; ++t)
	{
		double c;
		double d;
		cin >> c >> d;
		
		double f = 9.0 * c / 5.0 + 32.0 + d;
		
		cout << "Case " << t << ": " << fixed << setprecision(2) << (f - 32) * 5 / 9 << "\n";
	}
	
	return 0;
}
