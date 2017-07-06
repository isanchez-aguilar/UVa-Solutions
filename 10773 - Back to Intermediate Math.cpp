/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10773 - Back to Intermediate Math
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	float d;
	float v;
	float u;
	int testCases;
	cin >> testCases;
	for(int i = 1; i <= testCases; ++i)
	{
		cin >> d >> v >> u;
		// If v is greater than v or v is zero then It is impossible to determine both paths.
		if(v >= u || !v)
			cout << "Case " << i << ": can't determine\n";
		else
		{
			// Compute both paths.
			double path1 = d / u;
			double path2 = d / sqrt((u - v) * (u + v));
			cout << fixed;
			cout << setprecision(3) << "Case " << i << ": "<<  path2 - path1 << endl;
		}
	}

	return 0;
}