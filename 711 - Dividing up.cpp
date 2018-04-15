/*
*	User: Isanchez_Aguilar
*	Problem: UVA 711 - Dividing up
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	int memo[60001];
	int frequency[7];
	
	while(true)
	{
		int sum = 0;

		for (int i = 1; i <= 6; ++i)
		{
			cin >> frequency[i];
			sum += frequency[i] * i;
		}
		
		if (not sum)
			break;
		
		memset(memo, 0, sizeof(memo));
		
		if(not (sum & 1))
		{
			sum >>= 1;

			for (int i = 0; i <= frequency[1]; ++i)
				memo[i] = 1;
			
			for (int i = 2; i <= 6; ++i)
			{
				for (int j = sum; j >= 0; --j)
				{
					if (memo[j])
					{
						for (int k = 0; k <= frequency[i]; ++k)
						{
							int currentSum = j + i * k;
							
							if (sum < currentSum)
								break;
							
							if (i <= memo[currentSum])
								break;
							
							memo[currentSum] = i;
						}
					}
				}
			}
		}
		else
			sum >>= 1;

		cout << "Collection #" << ++t << ":" << "\n";

		if (memo[sum])
			cout << "Can be divided.\n";
		else
			cout << "Can't be divided.\n";
		
		cout << "\n";
	}

	return 0;
}