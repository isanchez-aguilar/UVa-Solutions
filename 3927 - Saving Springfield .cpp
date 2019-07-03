/*
*	User: IsanchezAguilar
*	Problem: COJ 3927 - Saving Springfield 
*/
#include <bits/stdc++.h>

using namespace std;

typedef double Double;

int n;
Double l;
Double r;
Double dx;
Double dy;
Double m1;
Double m2;
Double r1;
Double r2;
Double maxX = -1;
Double minX = 1e10;
Double minRadius = 1e10;
const Double EPS = 1e-6;
pair<Double, Double> building[10000];

inline Double getRadius(const Double& xCenter)
{
	Double radius = -1;

	for (size_t i = 0; i < n; ++i)
	{
		dy = building[i].second;
		dx = fabs(xCenter - building[i].first - 0.5);

		radius = max(radius, dx * dx + dy * dy);
		dx = fabs(xCenter - building[i].first + 0.5);

		radius = max(radius, dx * dx + dy * dy);
	}

	return radius;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (size_t i = 0; i < n; ++i)
	{
		cin >> building[i].first >> building[i].second;

		if (building[i].first < minX)
			minX = building[i].first;
		if (maxX < building[i].first)
			maxX = building[i].first;
	}


	l = minX - 1;
	r = maxX + 1;

	while (fabs(l - r) > EPS)
	{
		m1 = (l + l + r) / 3.0;
		m2 = (l + r + r) / 3.0;

		r1 = getRadius(m1);

		r2 = getRadius(m2);

		if (r1 < r2)
			minRadius = r1;
		else
			minRadius = r2;

		if(r1 < r2)
			r = m2;
		else if(r2 < r1)
			l = m1;
		else
		{
			l = m1;
			r = m2;
		}
	}

	cout << fixed << setprecision(5) << sqrt(minRadius) << "\n";

	return 0;
}