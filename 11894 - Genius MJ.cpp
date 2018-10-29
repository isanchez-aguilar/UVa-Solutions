/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11894 - Genius MJ
*/
#include <bits/stdc++.h>

using namespace std;

typedef int Double;

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
		if (x == a.x)
			return y < a.y;

		return x < a.x;
	}

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

	inline void rotate90()
	{
		swap(x, y);
		x *= -1;

		return;
	}
};

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

Vector lowestPoint;
Vector originPoint;
Vector plug[100000];
const int MAX = 2001;
bool socket[MAX][MAX];
const Vector upperRight(1000, 1000);
const Vector lowerLeft(-1000, -1000);

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	bool matched;
	int testCases;

	cin >> testCases;

	while (testCases--)
	{
		int pins;
		cin >> pins;

		memset(socket, false, sizeof socket);
		
		lowestPoint.x = MAX;
		originPoint.x = MAX;
		lowestPoint.y = MAX;
		originPoint.y = MAX;
		
		for (int i = 0; i < pins; ++i)
		{
			cin >> plug[i].x >> plug[i].y;
			lowestPoint = min(lowestPoint, plug[i]);
		}

		for (int i = 0; i < pins; ++i)
		{
			Double x;
			Double y;
			cin >> x >> y;

			Vector p(x, y);
			
			originPoint = min(originPoint, p);
			socket[x + 1000][y + 1000] = true;
		}

		for (int i = 0; i < 4; ++i)
		{
			if (i > 0)
			{
				lowestPoint.x = MAX;
				lowestPoint.y = MAX;
				
				for (int j = 0; j < pins; ++j)
				{	
					plug[j].rotate90();
					lowestPoint = min(lowestPoint, plug[j]);
				}
			}

			matched = true;
			Vector displacement(originPoint, lowestPoint);
			
			for (int j = 0; j < pins; ++j)
			{
				Vector p = plug[j] + displacement;

				if (isInsideBox(p, lowerLeft, upperRight) == 0 or not socket[p.x + 1000][p.y + 1000])
				{
					matched = false;
					break;
				}
			}

			if (matched)
				break;
		}

		if (not matched)
			cout << "NOT ";

		cout << "MATCHED\n";
	}

	return 0;
}