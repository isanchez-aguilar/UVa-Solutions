/*
*	User: Isanchez_Aguilar
*	Problem: UVA 361 - Cops and Robbers
*/
#include <bits/stdc++.h>

using namespace std;

typedef int Double;

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
		if (x == a.x)
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

	return (crossProduct == 0?0:(crossProduct < 0)?-1:1);
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

	inline Polygon getConvexHull()
	{
		int n = vertex.size();

		if (n < 3)
			return vertex;

		int k = 0;
		vector<Vector> points(2 * n);
		vector<Vector> auxVertex = vertex;

		sort(vertex.begin(), vertex.end());

		for (int i = 0; i < n; ++i)
		{
			while (k >= 2 and getDirection(points[k - 2], points[k - 1], vertex[i]) <= 0)
				--k;

			points[k++] = vertex[i];
		}

		for (int i = n - 2, t = k + 1; i >= 0; --i)
		{
			while (k >= t and getDirection(points[k - 2], points[k - 1], vertex[i]) <= 0)
				--k;

			points[k++] = vertex[i];
		}

		points.resize(k);
		vertex = auxVertex;

		return Polygon(points);
	}

	inline bool onPerimeter(Vector& p)
	{
		for (int i = 0; i < vertex.size(); ++i)
		{
			int j = (i + 1) % vertex.size();
			Line segment(vertex[i], vertex[j]);

			if(segment.onSegment(p))
				return true;
		}
		return false;
	}

	/*
	** Return:
	**  1 Inside.
	**  0 Outside.
	** -1 On perimeter.
	*/
	inline int isInsideConvex(Vector& p)
	{
		if (vertex.size() < 3)
			return 0;

		if (onPerimeter(p))
			return -1;

		for (int i = 1; i < vertex.size(); ++i)
		{
			if (getDirection(vertex[i - 1], p, vertex[i]) != -1)
				return 0;
		}
		
		return 1;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int c;
	int r;
	int o;
	int t = 0;

	while (cin >> c >> r >> o and (c or r or o))
	{
		vector<Vector> points(c);

		for (int i = 0; i < c; ++i)
			cin >> points[i].x >> points[i].y;

		Polygon cops = Polygon(points).getConvexHull();

		points.resize(r);

		for (int i = 0; i < r; ++i)
			cin >> points[i].x >> points[i].y;

		Vector p;
		Polygon robbers = Polygon(points).getConvexHull();

		cout << "Data set " << ++t << ":\n";

		for (int i = 0; i < o; ++i)
		{
			cin >> p.x >> p.y;
			
			cout << "     Citizen at (" << p.x << "," << p.y << ") is ";

			if (cops.isInsideConvex(p) != 0)
				cout << "safe.\n";
			else if (robbers.isInsideConvex(p) != 0)
				cout << "robbed.\n";
			else
				cout << "neither.\n";
		}

		cout << "\n";
	}

	return 0;
}
