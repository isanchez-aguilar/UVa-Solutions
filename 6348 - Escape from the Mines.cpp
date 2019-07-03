#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair<int, int> Point;

const int MAX_SIZE = 100000;

class Event
{
public:
	int x;
	int index;
	bool leftSide;

	Event() {}

	Event(int _x, int _index, bool _leftSide):x(_x), index(_index), leftSide(_leftSide) {}

	inline bool operator<(const Event& e)
	{
		if (x == e.x)
			return not leftSide;

		return x < e.x;
	}
};

Point p1[MAX_SIZE];
Point p2[MAX_SIZE];
int roomParent[MAX_SIZE];
Event sides[2 * MAX_SIZE];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	set<Point> lowerCorner;
	set<Point> upperCorner;
	
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> p1[i].x >> p1[i].y >> p2[i].x >> p2[i].y;

		sides[2 * i] = Event(p1[i].x, i, true);
		sides[2 * i + 1] = Event(p2[i].x, i, false);
	}

	sort(sides, sides + 2 * n);

	for (int i = 0; i < 2 * n; ++i)
	{
		int index = sides[i].index;
		const int y1 = p1[index].y;
		const int y2 = p2[index].y;

		if (sides[i].leftSide)
		{
			int parent = -1;

			if (not lowerCorner.empty())
			{
				set<Point>::iterator i = lowerCorner.lower_bound(Point(y1, -1));
				
				if (i != lowerCorner.begin())
				{
					int parentIndex = (--i)->second;

					if (p1[parentIndex].y < y1 and y2 < p2[parentIndex].y)
						parent = parentIndex;
					else
					{
						i = upperCorner.lower_bound(Point(y1, -1));

						if (i != upperCorner.begin())
							parent = roomParent[(--i)->second];
					}
				}
			}

			roomParent[index] = parent;
			lowerCorner.insert(Point(y1, index));
			upperCorner.insert(Point(y2, index)); 
		}
		else
		{
			lowerCorner.erase(Point(y1, index));
			upperCorner.erase(Point(y2, index)); 
		}
	}

	for (int i = 0; i < n; ++i)
		cout << roomParent[i] << "\n";

	return 0;
}