/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10684 - The jackpot
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int n;
	while(cin >> n and n)
	{
		int maxSum = -1000;
		int currentSum = 0;

		for(int i = 0; i < n; ++i)
		{
			int number;
			cin >> number;
			
			currentSum += number;

			if(currentSum < 0)
				currentSum = 0;

			maxSum = max(maxSum, currentSum);
		}

		if(maxSum <= 0)
			cout << "Losing streak.\n";
		else
			cout << "The maximum winning streak is " << maxSum << ".\n";


	}

	return 0;
}