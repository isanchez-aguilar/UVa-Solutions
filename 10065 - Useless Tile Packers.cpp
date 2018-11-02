/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10065 - Useless Tile Packers
*/
#include <bits/stdc++.h>

using namespace std;

typedef double Double;

const Double EPS = 1e-8;

inline Double isZero(const Double a) { return fabs(a) < EPS; }

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

class Polygon
{
public:
	vector<Vector> vertex;

	Polygon() {}

	Polygon(const vector<Vector>& points):vertex(points) {}

	inline Double getArea()
	{
		int n = vertex.size();
		Double area = 0.0;
		int j = n - 1;
		
		for (int i = 0; i < n; ++i)
		{
			area += (vertex[j].x + vertex[i].x) * (vertex[j].y - vertex[i].y);
			j = i;
		}

		return fabs(area / 2.0);		
	}
	
	inline Polygon getConvexHull()
	{
		int n = vertex.size();

		if (n <= 3)
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
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int t = 0;
	cout.precision(2);
	cout.setf(ios::fixed);

	while (cin >> n and n)
	{
		vector<Vector> points(n);

		for (int i = 0; i < n; ++i)
			cin >> points[i].x >> points[i].y;

		Polygon p1(points);
		Polygon p2 = p1.getConvexHull();

		Double area1 = p1.getArea();
		Double area2 = p2.getArea();

		cout << "Tile #" << ++t << "\n";
		cout << "Wasted Space = " << (1.0 - area1 / area2) * 100.0 << " %\n\n";
	}

	return 0;
}