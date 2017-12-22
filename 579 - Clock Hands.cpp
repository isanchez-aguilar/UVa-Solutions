/*
*	User: Isanchez_Aguilar
*	Problem: UVA 579 - Clock Hands
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int h;
	int m;
	char dots;
	
	while(cin >> h >> dots >> m and (h or m))
	{
		double b = m * 6.0;
		double a = (h * 30 + m / 2.0);

		double angle = abs(b - a);

		if(angle > 180)
			angle = 360 - angle;

		cout << fixed << setprecision(3) << angle << "\n";


	}

	return 0;
}