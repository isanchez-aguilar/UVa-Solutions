/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11496 - Musical Loop
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int pointsNumber;

	while(cin >> pointsNumber && pointsNumber)
	{

		int peaks = 0;
		int currentPoint;
		int previousPoint;
		int previousSlope = 0;
		
		cin >> previousPoint;
		cin >> currentPoint;

		int firstPoint = previousPoint;
		int secondPoint = currentPoint;

		previousSlope = (currentPoint - previousPoint) / abs(currentPoint - previousPoint);
		previousPoint = currentPoint;

		for(int i = 2; i < pointsNumber; ++i)
		{
			cin >> currentPoint;
			
			int currentSlope = (currentPoint - previousPoint) / abs(currentPoint - previousPoint);

			if(currentSlope + previousSlope == 0)
				++peaks;

			previousSlope = currentSlope;
			previousPoint = currentPoint;
		}

		currentPoint = firstPoint;
		int currentSlope = (currentPoint - previousPoint) / abs(currentPoint - previousPoint);

		if(currentSlope + previousSlope == 0)
			++peaks;

		previousSlope = currentSlope;
		previousPoint = currentPoint;

		currentPoint = secondPoint;
		currentSlope = (currentPoint - previousPoint) / abs(currentPoint - previousPoint);

		if(currentSlope + previousSlope == 0)
			++peaks;

		previousSlope = currentSlope;
		previousPoint = currentPoint;

		cout << peaks << "\n";

	}

	return 0;
}