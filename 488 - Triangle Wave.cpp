/*
*	User: Isanchez_Aguilar
*	Problem: UVA 488 - Triangle Wave
*/
#include <bits/stdc++.h>

int main(void)
{
	int testCases;
	const char a[][10] = {"", "1", "22", "333", "4444", "55555", "666666", "7777777", "88888888", "999999999"};
	
	scanf("%d", &testCases);
	while(testCases--)
	{
		int amplitude;
		int frequency;
		scanf("%d%d", &amplitude, &frequency);

		while(frequency--)
		{
			int i = 1;
			for(; i < amplitude; ++i)
				puts(a[i]);
			for(int k = i; k; --k)
				puts(a[k]);
			if(frequency || testCases)
				printf("\n");
		}
	}
	return 0;
}