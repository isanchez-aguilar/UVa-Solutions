/*
*	User: Isanchez_Aguilar
*	Problem: UVA 191 - Intersection
*/
#include <bits/stdc++.h>

using namespace std;

typedef double Double;

const Double EPS = 1e-8;

inline Double areEqual(const Double a, const Double b) { return fabs(a - b) < EPS; }

class Vector
{
public:
	Double x;
	Double y;

	Vector():x(0), y(0) {}

	Vector(Double _x, Double _y):x(_x), y(_y) {}

	Vector(Vector p, Vector q) { *this = p - q; }
	
	inline bool operator<(const Vector& a) const
	{
		if (areEqual(x, a.x))
			return y < a.y;

		return x < a.x;
	}

	inline Vector operator-(const Vector& a) const
	{
		Vector b(x - a.x, y - a.y);
		
		return b;
	}

	inline Double cross(const Vector& a) const { return x * a.y - y * a.x; }
};

/* Return:
** CCW = 1.
** Collinear = 0.
** CW = -1.
*/
inline int getDirection(const Vector& o, const Vector& p, const Vector& q)
{
	Double crossProduct = (p - o).cross(q - o);

	return areEqual(crossProduct, 0)?0:(crossProduct < 0)?-1:1;
}

/*
** Return:
** 1 if It is inside.
** 0 if It is outside.
** -1 if It is on one side.
*/
inline int isInsideBox(const Vector p, const Vector lowerLeft, const Vector upperRight)
{
	if (p.x > lowerLeft.x and p.y > lowerLeft.y and p.x < upperRight.x and p.y < upperRight.y)
		return 1;

	if (p.x < lowerLeft.x or p.y < lowerLeft.y or p.x > upperRight.x or p.y > upperRight.y)
		return 0;

	return -1;
}

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

	inline bool onSegment(Vector& a)
	{
		return getDirection(a, p, q) and not (a < p or q < a);
	}

	inline int areIntersectingSegments(Line& l)
	{
		int direction1 = getDirection(p, q, l.p);
		int direction2 = getDirection(p, q, l.q);

		if (direction1 == direction2)
		{
			if (direction1 != 0)
				return 0;

			return (l.onSegment(p) or l.onSegment(q) or onSegment(l.p) or onSegment(l.q))?-1:0;
		}

		return (getDirection(l.p, l.q, p) != getDirection(l.p, l.q, q))?1:0;
	}
};

inline int isInsideBox(const Line segment, const Vector lowerLeft, const Vector upperRight)
{
	return isInsideBox(segment.p, lowerLeft, upperRight) != 0 and isInsideBox(segment.q, lowerLeft, upperRight) != 0;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Line edge[4];
	int testCases;
	
	cin >> testCases;

	while (testCases--)
	{
		Double x1;
		Double y1;
		Double x2;
		Double y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		if (Vector(x2, y2) < Vector(x1, y1))
		{
			swap(x1, x2);
			swap(y1, y2);
		}

		Line segment(x1, y1, x2, y2);
		cin >> x1 >> y1 >> x2 >> y2;

		if (x2 < x1)
			swap(x1, x2);

		if (y2 < y1)
			swap(y1, y2);

		edge[0] = Line(x1, y1, x2, y1);
		edge[1] = Line(x2, y1, x2, y2);
		edge[2] = Line(x1, y2, x2, y2);
		edge[3] = Line(x1, y1, x1, y2);

		bool possible = isInsideBox(segment, Vector(x1, y1), Vector(x2, y2));
		
		for (int i = 0; i < 4 and not possible; ++i)
		{
			if (segment.areIntersectingSegments(edge[i]) != 0)
				possible = true;
		}

		if (possible)
			cout << "T\n";
		else
			cout << "F\n";
	}

	return 0;
}