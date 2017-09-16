/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10341 - Solve It
*/
#include <bits/stdc++.h>

using namespace std;

int p;
int q;
int r;
int s;
int t;
int u;

inline double f(double x)
{
	return (p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(4);
	while(cin >> p >> q >> r >> s >> t >> u)
	{
		double a = 0;
		double b = 1;
		if(f(a) * f(b) > 0)
			cout << "No solution\n";
		else
		{
			double m = (a + b) / 2.0;
			double fm = f(m);

			while(fabs(fm) > 1.0e-7)
			{
				if(fm * f(b) > 0)
					b = m;
				else
					a = m;

				m = (a + b) / 2.0;
				fm = f(m);
			}

			cout << fixed << m << "\n"; 
		}
	}

	return 0;
}