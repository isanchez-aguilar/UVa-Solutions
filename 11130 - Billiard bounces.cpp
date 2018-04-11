#include <bits/stdc++.h>

#define PI acos(-1)

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a;
	int b;
	int v;
	int A;
	int s;

	while (cin >> a >> b >> v >> A >> s and a > 0)
	{
		// Distances covered in x and y along the s seconds plus the half of table.
		int distanceY = (v * s * sin(A * PI / 180.0) + b) / 2;
		int distanceX = (v * s * cos(A * PI / 180.0) + a) / 2;
		// Times it traversed in x and y the vertical and horizontal distance.
		cout << distanceX / a << " " << distanceY / b << "\n";
	}

	return 0;
}