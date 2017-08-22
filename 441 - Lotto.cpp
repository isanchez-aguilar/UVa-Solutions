/*
*	User: Isanchez_Aguilar
*	Problem: UVA 441 - Lotto
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int t = 0;
	while(cin >> n && n)
	{
		vector<int> numbers(n);

		for(int i = 0; i < n; ++i)
			cin >> numbers[i];

		if(t++)
			cout << "\n";

		for(int i = 0; i < n - 5; ++i)
		{
			for(int j = i + 1; j < n - 4; ++j)
			{
				for(int k = j + 1; k < n - 3; ++k)
				{
					for(int l = k + 1; l < n - 2; ++l)
					{
						for(int m = l + 1; m < n - 1; ++m)
						{
							for(int o = m + 1; o < n; ++o)
								cout << numbers[i] << " " << numbers[j] << " " << numbers[k] << " " << numbers[l] << " " << numbers[m] << " " << numbers[o] << "\n"; 
						}
					}
				}
			}
		}
	}

	return 0;
}