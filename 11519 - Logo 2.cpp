/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11519 - Logo 2
*/
#include <bits/stdc++.h>

using namespace std;

typedef double Double;

const Double PI = M_PI;
const Double EPS = 1e-2;

inline Double isEqual(Double a, Double b) { return fabs(a - b) < EPS; }

inline Double toRadians(Double angle) { return PI * angle / 180.0; }

class Vector
{
public:
	Double x;
	Double y;

	Vector():x(0), y(0) {}

	Vector(Double _x, Double _y):x(_x), y(_y) {}

	inline bool operator==(const Vector& a) const { return isEqual(x, a.x) and isEqual(y, a.y);	}

	// Displace vector given the direction(degrees) and magnitude.
	inline void move(Double magnitude, Double direction)
	{	
		x += magnitude * cos(toRadians(direction));
		y += magnitude * sin(toRadians(direction));
	}

	inline Double norm() const { return hypot(x, y); }
};


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	const Vector zero(0, 0);
	
	cin >> testCases;

	while (testCases--)
	{
		int instructions;
		cin >> instructions;

		Double angle = 0.0;
		Vector position(0.0, 0.0);

		bool left = false;
		bool right = false;
		bool forward = false;
		bool backward = false;

		vector< pair<string, Double> > unknownInstruction;

		while (instructions--)
		{
			Double value;
			string parameter;
			string instruction;
			cin >> instruction >> parameter;

			if (parameter == "?")
			{
				switch (instruction[0])
				{
					case 'l':
						left = true;
					break;
					
					case 'r':
						right = true;
					break;

					case 'f':
						forward = true;
					break;
					
					default:
						backward = true;
				}

				while (instructions--)
				{
					cin >> instruction >> value;
					unknownInstruction.push_back(make_pair(instruction, value));
				}

				break;
			}
			
			istringstream in(parameter);

			in >> value;

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

		if (left or right)
		{
			Double auxAngle = angle;
			Vector auxPosition = position;

			for (int alpha = 0; alpha < 360; ++alpha)
			{
				position = auxPosition;
				angle = (left?1:-1) * alpha + auxAngle;

				for (int i = 0; i < unknownInstruction.size(); ++i)
				{
					Double value = unknownInstruction[i].second;
					char instruction = unknownInstruction[i].first[0];

					switch (instruction)
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
				
				if (zero == position)
				{
					angle = alpha;
					break;
				}
			}

			cout << (int)angle << "\n";
		}
		else
		{
			for (int i = 0; i < unknownInstruction.size(); ++i)
			{
				Double value = unknownInstruction[i].second;
				char instruction = unknownInstruction[i].first[0];

				switch (instruction)
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
	}

	return 0;
}