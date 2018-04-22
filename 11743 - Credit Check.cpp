/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11743 - Credit Check
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int testCases;
	int numbers[4];
	cin >> testCases;
	
	while (testCases--)
	{
		for (int i = 3; i >= 0; --i)
			cin >> numbers[i];
			
		int sum = 0;
		for (int i = 0; i < 4; ++i)
		{
			bool isEven = false;
			
			int currentNumber = numbers[i];
			
			while (currentNumber)
			{
				if (isEven)
				{
					int n = (currentNumber % 10) << 1;
					sum += n % 10;
					n /= 10;
					sum += n % 10;
				}
				else
					sum += currentNumber % 10;
					
				currentNumber /= 10;
				
				isEven = not isEven; 
			}
		}
		
		cout << (sum % 10?"Invalid":"Valid") << "\n";
	}
	
	return 0;
}
