/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10242 - Fourth Point !!
*/
#include <bits/stdc++.h>

using namespace std;

typedef double Double;

const Double EPS = 1e-3;

inline Double isEqual(Double a, Double b) { return fabs(a - b) < EPS; }

class Vector
{
public:
	Double x;
	Double y;

	Vector():x(0), y(0) {}

	Vector(Double _x, Double _y):x(_x), y(_y) {}

	inline bool operator==(const Vector& a) const { return isEqual(x, a.x) and isEqual(y, a.y);	}

	inline Vector operator+(const Vector& a)
	{
		Vector b;
		b.x = x + a.x;
		b.y = y + a.y;
		
		return b;
	}

	inline Vector operator-(const Vector& a)
	{
		Vector b;
		b.x = x - a.x;
		b.y = y - a.y;
		
		return b;
	}
};

Vector points[4];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cout.precision(3);
	cout.setf(ios::fixed);

	while (cin >> points[0].x >> points[0].y)
	{
		for (int i = 1; i < 4; ++i)
			cin >> points[i].x >> points[i].y;

		int a = 1;
		int b = 0;
		int c = 2;

		if (points[0] == points[2])
		{
			a = 0;
			b = 1;
			c = 3;
		}
		else if (points[0] == points[3])
		{
			a = 0;
			b = 1;
			c = 2;

		}
		else if (points[1] == points[2])
			c = 3;

		Vector p = points[c] + points[b] - points[a];

		cout << p.x << " " << p.y << "\n";
	}

	return 0;
}