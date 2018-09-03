/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10385 - Duathlon
*/
#include <bits/stdc++.h>

#define ERROR 1e-8

using namespace std;

typedef pair<double, double> dd;

int n;
double road;
dd speed[20];

inline double getTime(dd speed, dd length)
{
	return length.first / speed.first + length.second / speed.second;
}

inline double getLargestDifferecne(double l)
{
	double lowestTime = 1e9;
	dd currentLength(l, road - l);
	double cheaterTime = getTime(speed[n - 1], currentLength);
	
	for (int i = 0; i < n - 1; ++i)
		lowestTime = min(lowestTime, getTime(speed[i], currentLength));

	return (cheaterTime - lowestTime) * 3600.00;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> road)
	{
		cin >> n;
		for  (int i = 0; i < n; ++i)
			cin >> speed[i].first >> speed[i].second;

		double l = 0;
		double r = road;

		while (ERROR < fabs(r - l))
		{
			double m1 = (r + r + l) / 3.0;
			double m2 = (r + l + l) / 3.0;

			if (getLargestDifferecne(m2) < getLargestDifferecne(m1))
				r = m1;
			else
				l = m2;
		}

		if (getLargestDifferecne(l) > 0)
			cout << "The cheater cannot win.\n";
		else
		{	
			cout << "The cheater can win by " << (int)round(-getLargestDifferecne(l)) << " seconds with r = ";
			cout << fixed << setprecision(2) << l << "km and k = " << road - l << "km.\n";
		}
	}

	return 0;
}