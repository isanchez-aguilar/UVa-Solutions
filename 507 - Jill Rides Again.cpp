#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	for (int t = 1; t <= testCases; ++t)
	{
		int n;
		cin >> n;

		int maxSum = 0;
		int endIndex = 2;
		int startIndex = 2;
		int currentSum = 0;
		int currentStart = 1;

		for (int i = 2; i <= n; ++i)
		{
			int value;
			cin >> value;
			currentSum += value;
			if (currentSum < 0)
			{
				currentSum = 0;
				currentStart = i;	
			}

			if (maxSum <= currentSum)
			{
				if (maxSum < currentSum or (maxSum == currentSum and endIndex - startIndex < i - currentStart))
				{
					endIndex = i;
					maxSum = currentSum;
					startIndex = currentStart;
				}
			}
		}

		if (maxSum <= 0)
			cout << "Route " << t << " has no nice parts\n";
		else
			cout << "The nicest part of route " << t << " is between stops " << startIndex << " and " << endIndex << "\n";
	}

	return 0;
}