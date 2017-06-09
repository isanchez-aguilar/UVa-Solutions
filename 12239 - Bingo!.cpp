/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12239 - Bingo!
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	int balls;
	int bag[91];
	// Read while N and balls are not 0.
	while(cin >> N >> balls && N && balls)
	{
		// Read the value of balls.
		for(int i = 0; i < balls; ++i)
			cin >> bag[i];
		// Initialize the index of comparison.
		int j = balls - 1;
		int k = 0;
		int kLast = 0;
		bool possible = true;
		bitset<91> differences;
		// Check all numbers from 1 to N;
		for(int i = 1; i < N + 1 && possible; ++i)
		{
			// If the difference has not been recorded. 
			if(!differences[i])
			{
				int outcome = -1;
				// Start j with the last index to not repeat the comparison.
				for(; j > -1 && outcome != i; --j)
				{
					// Initialize the last index of k.
					for(k = kLast; k > -1; --k)
					{
						kLast = 0;
						// Get the abs value of two balls.
						outcome = abs(bag[j] - bag[k]);
						// Record the difference.
						differences[outcome] = 1;
						if(outcome == i)
						{
							// Add j and initialize the last k.
							++j;
							kLast = k;
							break;
						}
					}
				}
				// If the outcome is not equal to i then is impossible.
				if(outcome != i)
				{
					possible = false;
					break;
				}
			}
		}
		// If is possible then print Y.
		if(possible)
			cout << "Y\n";
		else
			cout << "N\n";
	}
	return 0;
}