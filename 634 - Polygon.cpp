/*
*	User: Isanchez_Aguilar
*	Problem: UVA 634 - Polygon
*/
#include <bits/stdc++.h>

using namespace std;

typedef double Double;

const Double EPS = 0;
const Double E = M_E;
const Double PI = M_PI;

inline Double areEqual(const Double a, const Double b) { return fabs(a - b) < EPS; }

class Vector
{
public:
	Double x;
	Double y;

	Vector() {}

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

	Line(Vector& _p, Vector& _q)
	{
		p = _p;
		q = _q;

		if (q < p)
			swap(p, q);

		a = _p.y - _q.y;
		b = _q.x - _p.x;
		c = _p.x * _q.y - _q.x * _p.y;
	}

	Line(Double x2, Double y2, Double x1, Double y1)
	{
		p = Vector(x1, y1);
		q = Vector(x2, y2);

		a = y1 - y2;
		b = x2 - x1;
		c = x1 * y2 - x2 * y1;
	}

	inline bool onLine(const Vector& a) { return getDirection(p, q, a) == 0; }

	inline bool onSegment(Vector& a) { return onLine(a) and not (a < p or q < a); }

	/*
	** Return:
	**  1 If they are intersecting. 
	**  0 If they are not intersecting.
	** -1 If they are overlaping. 
	*/
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

class Polygon
{
public:
	vector<Vector> vertex;

	Polygon() {}

	Polygon(const vector<Vector>& points):vertex(points) {}

	inline bool onPerimeter(Vector& p)
	{
		for (int i = 0; i < vertex.size(); ++i)
		{
			int j = (i + 1) % vertex.size();

			if(Line(vertex[i], vertex[j]).onSegment(p))
				return true;
		}

		return false;
	}

	/*
	** Ray casting algorithm.
	** Return:
	**  1 Inside.
	**  0 Outside.
	** -1 On perimeter.
	*/
	inline int isInsideRayCasting(Vector& p)
	{
		if (vertex.size() < 3)
			return 0;

		if (onPerimeter(p))
			return -1;

		Vector origin = *min_element(vertex.begin(), vertex.end());

		vector<Vector> polygon = vertex;
		Vector q(origin.x - PI, origin.y - E);

		Line ray(p, q);
		int crosses = 0;
		polygon.push_back(polygon[0]);
		
		for (int i = 1; i < polygon.size(); ++i)
		{
			Line side(polygon[i - 1], polygon[i]);
							
			if (ray.areIntersectingSegments(side) != 0)
				++crosses;
		}

		return crosses % 2;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while (cin >> n and n)
	{
		vector<Vector> point(n);

		for (int i = 0; i < n; ++i)
			cin >> point[i].x >> point[i].y;

		Vector p;
		Polygon figure(point);

		cin >> p.x >> p.y;

		if (figure.isInsideRayCasting(p))
			cout << "T\n";
		else
			cout << "F\n";
	}

	return 0;
}