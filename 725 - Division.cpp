/*
*	User: Isanchez_Aguilar
*	Problem: UVA 725 - Division
*/
#include <bits/stdc++.h>

int main(void)
{
	int n;
	int t = 0;
	
	while(scanf("%d", &n) && n)
	{
		if(t++)
			printf("\n");

		bool fraction = 0;
		
		for(int q = 1234; q <= 98765 / n; ++q)
		{
			int p = n * q;
			int used = (q < 10000);
			
			int temp = p;
			while(temp)
			{
				used |= 1 << (temp % 10);
				temp /= 10;
			}
			
			temp = q;
			while(temp)
			{
				used |= 1 << (temp % 10);
				temp /= 10;
			}

			if(used == (1 << 10) - 1)
			{
				fraction = 1;
				printf("%0.5d / %0.5d = %d\n", p, q, n);
			}
		}

		if(!fraction)
			printf("There are no solutions for %d.\n", n);
	}

	return 0;
}