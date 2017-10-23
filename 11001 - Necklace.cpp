/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11001 - Necklace
*/
#include <bits/stdc++.h>

#define EPS 1e-10

using namespace std;

double v;
double v0;

inline double p(double x)
{
	return 0.3L * x * sqrt(v / x - v0);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> v >> v0 and (v or v0))
	{
		if(v <= v0)
			cout << "0\n";
		else
		{
			int n = round(v / (v0 * 2.0L));

			if(fabs(p(n) - p(n + 1)) < EPS or fabs(p(n) - p(n - 1)) < EPS)
			 	cout << "0\n";
			else
				cout << n << "\n";
		}
	}

	return 0;
}