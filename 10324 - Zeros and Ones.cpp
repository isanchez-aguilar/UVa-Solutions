/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10324 - Zeros and Ones
*/
#include <bits/stdc++.h>

#define MAX_SIZE 1000000

int main(void)
{
	// Variables to save the data of string.
	int i;
	int j;
	int queries;
	char character;
	int lastPosition;
	char lastCharacter;
	int testCase = 1;
	int repetitions[MAX_SIZE];
	// Read while not EOF.
	while((character = getchar()) != EOF)
	{
		// Repeat character data. 
		i = 1;
		lastPosition = 0;
		repetitions[0] = 0;
		lastCharacter = character;
		// Read while character is not '\n'.
		while(character = getchar())
		{
			// If the characters are not equal then set the new last character and position.
			if(character != lastCharacter)
			{
				if(character == '\n')
					break;
				lastCharacter = character;
				++lastPosition;
			}
			// Set the lastPosition equal.
			repetitions[i++] = lastPosition;
		}
		// Print the number of test case.
		printf("Case %d:\n", testCase++);
		// Read the number of queries.
		scanf("%d", &queries);
		// Read the queries.
		while(queries--)
		{
			// Read the interval.
			scanf("%d %d\n", &i, &j);
			// If i is bigger then swap the value.
			switch(repetitions[j] == repetitions[i])
			{
				case 1:
					printf("Yes\n");
					break;
				default:
					printf("No\n");
			}
		}
	}
	return 0;
}