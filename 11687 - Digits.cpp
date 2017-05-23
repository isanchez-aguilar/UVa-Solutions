/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11687 - Digits
*/
#include <bits/stdc++.h>

int main(void)
{
	char number[1000000];
	// Read while not EOF.
	while(scanf("%s", number) != EOF)
	{
		// If the string is END then finish the execution.
		if(number[0] == 'E')
			return 0;
		// The previous number is the number read.
		int previous = atoi(number);
		// Get the numbr of digits.
		int digits = strlen(number);	
		// Initialize the iterations to 1.
		int i = 1;
		// While the number of digits are not equal to the current execute.
		while(digits != previous)
		{
			previous = digits;
			digits = (int)log10((double)digits) + 1;	
			++i;
		}
		// Print the number of iterations.
		printf("%d\n", i);
	}
	return 0;
}