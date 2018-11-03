/*
*	User: Isanchez_Aguilar
*	Problem: UVA 1111 - Trash Removal
*/
#include <bits/stdc++.h>

using namespace std;

typedef double Double;

const Double INF = 1e20;
const Double EPS = 1e-9;

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

	inline Vector operator+(const Vector& a) const
	{
		Vector b;
		b.x = x + a.x;
		b.y = y + a.y;
		
		return b;
	}

	inline Vector operator-(const Vector& a) const
	{
		Vector b(x - a.x, y - a.y);
		
		return b;
	}

	inline Vector operator*(const Double k) const
	{
		return Vector(k * x, k * y);
	}

	inline Double normSq() const { return x * x + y * y; }

	inline Double dist(const Vector &a) const { return hypot(x - a.x, y - a.y); }

	inline Double dot(const Vector& a) const { return x * a.x + y * a.y; }

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

	/*
	** Returns the distance from a to the line defined by
	** two points p and q (p and q must be different)
	** the closest point is returned as second parameter.
	*/
	inline pair<Double, Vector> distToLine(const Vector& a)
	{
		// Formula: c = p + u * pq.
		Vector pa = Vector(a, p);
		Vector pq = Vector(q, p);

		Double u = pa.dot(pq) / pq.normSq();
		
		Vector c = p + pq * u; // Translate a to c.
		
		return make_pair(a.dist(c), c);
	}

	/*
	** Returns the distance from a to the segment pq
	** (still OK if p == q) the closest point is returned
	** as second parameter.
	*/
	inline pair<Double, Vector> distToSegment(const Vector& a)
	{
		Vector c;
		Vector pa = Vector(a, p);
		Vector pq = Vector(q, p);

		Double u = pa.dot(pq) / pq.normSq();

		if (u < 0.0)
		{
			c = p; // closer to p.
			return make_pair(a.dist(p), c);
		}

		if (u > 1.0)
		{
			c = q; // closer to q.
			return make_pair(a.dist(q), c);
		}

		return distToLine(a);
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

	cout.precision(2);
	cout.setf(ios::fixed);

	int n;
	int t = 0;

	while (cin >> n and n)
	{
		vector<Vector> point(n);

		for (int i = 0; i < n; ++i)
			cin >> point[i].x >> point[i].y;

		Polygon figure = Polygon(point).getConvexHull();
		
		Double width = INF;
		point = figure.vertex;

		for (int i = 0; i < point.size() - 1; ++i)
		{
			Double maxDistance = -1.0;

			for (int j = 0; j < point.size(); ++j)
			{
				if (j == i or j == i + 1)
					continue;

				Line side(point[i], point[i + 1]);
				Double dist = side.distToLine(point[j]).first;

				maxDistance = max(maxDistance, dist);
			}

			width = min(width, maxDistance);
		}

		cout << "Case " << ++t << ": " << width << "\n";
	}

	return 0;
}