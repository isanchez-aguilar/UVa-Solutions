/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11236 - Grocery store
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	for(int i = 8; i <= 125; ++i)
	{
		for(int j = i; i * j * j * j <= 2000000000; ++j)
		{
			for(int k = j; i * j * k * k <= 2000000000; ++k)
			{
				int product = i * j * k;
				if(product > 1000000)
				{
					int sum = i + j + k;
					int l = 1000000 * sum / (product - 1000000);

					if(k <= l && sum + l <= 2000 && fabs((sum + l) / 100.0 - product * l / 100000000.0) < 1e-9)
						printf("%0.2f %0.2f %0.2f %0.2f\n", i / 100.0, j / 100.0, k / 100.0, l / 100.0);

				}
			}
		}
	}

	return 0;
}