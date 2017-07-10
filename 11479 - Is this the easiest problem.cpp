/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11479 - Is this the easiest problem?
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long sides[3];
	int testCases;
	cin >> testCases;

	for(int t = 1; t <= testCases; ++t)
	{
		bool invalid = 0;
		for(int i = 0; i < 3; ++i)
		{
			cin >> sides[i];
			if(sides[i] < 0)
				invalid = 1;
		}
		// If sides comply with the inequality a + b < c to prove the sides form a triangle.
		for(int i = 0; i < 3 && !invalid; ++i)
		{
			long long sum = 0;
			for(int j = 0; j < 3; ++j)
			{
				if(j != i)
					sum += sides[j];
			}
			if(sum <= sides[i])
			{
				invalid = 1;
				break;
			}
		}
		// If the sides are valid to form a triangle, then check what type of triangle it is.
		if(!invalid)
		{	
			sort(sides, sides + 3);
			if(sides[0] == sides[2])
				cout << "Case " << t << ": Equilateral\n";
			else if(sides[0] == sides[1] || sides[1] == sides[2])
				cout << "Case " << t << ": Isosceles\n";
			else
				cout << "Case " << t << ": Scalene\n";
		}
		else
			cout << "Case " << t << ": Invalid\n";
	}

	return 0;
}
