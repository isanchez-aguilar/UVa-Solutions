/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11505 - Logo
*/
#include <bits/stdc++.h>

using namespace std;

typedef double Double;

const Double PI = M_PI;
const Double EPS = 1e-2;

inline Double isZero(Double a) { return fabs(a) < EPS; }

inline Double toRadians(Double angle) { return PI * angle / 180.0; }

class Vector
{
public:
	Double x;
	Double y;

	Vector():x(0), y(0) {}

	Vector(Double _x, Double _y):x(_x), y(_y) {}

	inline void move(Double hypotenuse, Double angle)
	{	
		x += hypotenuse * cos(toRadians(angle));
		y += hypotenuse * sin(toRadians(angle));
	}

	inline Double norm() const { return hypot(x, y); }
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while (testCases--)
	{
		int instructions;
		cin >> instructions;

		Double angle = 0.0;
		Vector position(0.0, 0.0);

		while (instructions--)
		{
			Double value;
			string instruction;
			cin >> instruction >> value;

			switch (instruction[0])
			{
				case 'l':
					angle = fmod(angle + value, 360.0);
				break;
				
				case 'r':
					angle = fmod(angle - value, 360.0);
				break;

				case 'f':
					position.move(value, angle);
				break;
				
				default:
					position.move(-value, angle);
			}
		}

		cout << (int)round(position.norm()) << "\n";
	}

	return 0;
}