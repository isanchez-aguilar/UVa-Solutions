/*
*	User: Isanchez_Aguilar
*	Problem: UVA 378 - Intersecting Lines
*/
#include <bits/stdc++.h>

using namespace std;

typedef double Double;

const Double INF = 1e20;
const Double EPS = 1e-8;

inline Double isZero(const Double a) { return fabs(a) < EPS; }

class Vector
{
public:
	Double x;
	Double y;

	Vector():x(0), y(0) {}

	Vector(Double _x, Double _y):x(_x), y(_y) {}

	inline Vector operator-(const Vector& a) const
	{
		Vector b(x - a.x, y - a.y);
		
		return b;
	}

	inline Double cross(const Vector& a) const { return x * a.y - y * a.x; }
};

/*
** Line with the general form Ax + By + C = 0.
** Segment with begining and ending points p and q. 
*/
class Line
{
public:
	Vector p;
	Vector q;
	Double a;
	Double b;
	Double c;

	Line() {}

	Line(Double x2, Double y2, Double x1, Double y1)
	{
		p = Vector(x1, y1);
		q = Vector(x2, y2);

		a = y1 - y2;
		b = x2 - x1;
		c = x1 * y2 - x2 * y1;
	}

	inline bool areParallel(const Line& l) { return isZero((l.q - l.p).cross(q - p)); }

	inline bool areSame(const Line& l)
	{
		return areParallel(l) and isZero((l.p - l.q).cross(l.p - q)) and isZero((q - p).cross(q - l.p));
	}
	
	/*
	** Return:
	**  1 If they are intersecting.
	**  0 If they are parallel.
	** -1 If they are the same.
	*/
	inline pair<int, Vector> areIntersecting(const Line& l)
	{
		Vector intersection(INF, INF);
		Double determinant = a * l.b - b * l.a;

		if (isZero(determinant))
		{
			if (areSame(l))
				return make_pair(-1, intersection);
			
			return make_pair(0, intersection);
		}

		intersection.x = (b * l.c - c * l.b) / determinant;
		intersection.y = (c * l.a - a * l.c) / determinant;

		return make_pair(1, intersection);
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	cout.precision(2);
	cout.setf(ios::fixed);
	cout << "INTERSECTING LINES OUTPUT\n";

	while (testCases--)
	{
		Double x1;
		Double x2;
		Double y1;
		Double y2;
		
		cin >> x1 >> y1 >> x2 >> y2;
		
		Line line1(x2, y2, x1, y1);

		cin >> x1 >> y1 >> x2 >> y2;

		Line line2(x2, y2, x1, y1);

		pair<int, Vector> intersection = line1.areIntersecting(line2);
		
		switch (intersection.first)
		{
			case -1:
				cout << "LINE\n";
			break;

			case 0:
				cout << "NONE\n";
			break;

			default:
				cout << "POINT " << intersection.second.x << " " << intersection.second.y << "\n";
		}
	}

	cout << "END OF OUTPUT\n";

	return 0;
}