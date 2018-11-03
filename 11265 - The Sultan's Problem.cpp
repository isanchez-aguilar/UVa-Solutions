/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11265 - The Sultan's Problem
*/
#include <bits/stdc++.h>

using namespace std;

typedef double Double;

const Double E = M_E;
const Double PI = M_PI;
const Double INF = 1e20;
const Double EPS = 1e-9;

inline Double isZero(const Double a) { return fabs(a) < EPS; }

inline Double areEqual(const Double a, const Double b) { return fabs(a - b) < EPS; }

class Vector
{
public:
	Double x;
	Double y;

	Vector() {}

	Vector(Double _x, Double _y):x(_x), y(_y) {}

	Vector(Vector p, Vector q) { *this = p - q; }

	inline bool operator==(const Vector& a) const { return areEqual(x, a.x) and areEqual(y, a.y); }

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

	inline bool isCutting(const Line& l) const
	{
		for (int i = 0, first = 0; i < vertex.size(); ++i)
		{
			int direction = getDirection(l.p, l.q, vertex[i]);

			if (direction == 0)
				continue;
			
			if (first == 0)
				first = direction;
			
			else if (direction != first)
				return true;
		}
		
		return false;
	}

	inline vector<Polygon> cutPolygon(Line& r)
	{
		if (not isCutting(r))
			return vector<Polygon>(1, *this);
		
		int index = 0;
		vector<Vector> polygons[2];
		vector<Vector> auxVertex = vertex;

		vertex.push_back(vertex[0]);

		for (int i = 1; i < vertex.size(); ++i)
		{
			Line s(vertex[i - 1], vertex[i]);
			
			if (s.areIntersectingSegments(r))
			{
				Vector p = r.areIntersecting(Line(s.p, s.q)).second;

				if (vertex[i - 1] == p)
					continue;
				
				polygons[index].push_back(vertex[i - 1]);
				polygons[1 - index].push_back(p);
				polygons[index].push_back(p);

				index = 1 - index;
			}
			else
				polygons[index].push_back(vertex[i - 1]);
		}

		vertex = auxVertex;
		vector<Polygon> ans;

		ans.push_back(Polygon(polygons[0]));
		ans.push_back(Polygon(polygons[1]));

		return ans;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cout.precision(3);
	cout.setf(ios::fixed);
	
	int n;
	Double w;
	Double h;
	Double x0;
	Double y0;
	Double x1;
	Double y1;
	int t = 0;
	Vector fountain;
	vector<Vector> points(4);

	while (cin >> n >> w >> h >> fountain.x >> fountain.y)
	{
		points[0] = Vector(0, 0);
		points[1] = Vector(0, h);
		points[2] = Vector(w, h);
		points[3] = Vector(w, 0);

		Polygon garden(points);

		cout << "Case #" << ++t << ": ";
		
		while (n--)
		{
			cin >> x0 >> y0 >> x1 >> y1;

			Vector p(x0, y0);
			Vector q(x1, y1);
			
			Line l(p, q);
			vector<Polygon> polygons = garden.cutPolygon(l);

			if (polygons.size() == 1 or polygons[0].isInsideRayCasting(fountain))
				garden = polygons.front();
			else
				garden = polygons.back();
		}

		cout << garden.getArea() << "\n";
	}

	return 0;
}