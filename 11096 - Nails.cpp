/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11096 - Nails
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

	inline Double dist(const Vector &a) const { return hypot(x - a.x, y - a.y); }

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

	inline Double getPerimeter()
	{
		Double result = 0.0;
		vector<Vector> polygon = vertex;

		polygon.push_back(vertex[0]);
		
		for (int i = 0; i < polygon.size() - 1; ++i)
			result += polygon[i].dist(polygon[i + 1]);

		return result;
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

	cout.precision(5);
	cout.setf(ios::fixed);

	int testCases;
	cin >> testCases;

	while (testCases--)
	{
		int size;
		Double initialLength;
		cin >> initialLength >> size;

		vector<Vector> points(size);

		for (int i = 0; i < size; ++i)
			cin >> points[i].x >> points[i].y;

		if (size == 1)
			cout << initialLength << "\n";
		else
		{
			Polygon p(points);
			cout << max(initialLength, p.getConvexHull().getPerimeter()) << "\n";
		}
	}

	return 0;
}