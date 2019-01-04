/*
*   User: Isanchez_Aguilar
*   Problem: UVA 11956 - Brainfuck
*/
#include <cstdio>
#include <cstring>

#define SIZE 100
#define MAX_SIZE 100001

short memory[SIZE];
char commands[MAX_SIZE];

int main(void)
{
	int testCases;
	// Read the number of test cases.
	scanf("%d", &testCases);
	// Read the command of the cases.
	for (int i = 1; i <= testCases; ++i)
	{
		if (i > 1)
			memset(memory, 0, sizeof memory);

		// Current position of pointer.
		int currentByte = 0;
		
		// Read the commands.
		scanf("%s", commands);
		
		// Execute the commands.
		for (int j = 0; commands[j] != '\0'; ++j)
		{
			// Evaluate the command.
			switch (commands[j])
			{
				// If It increments the pointer.
				case '>':
					// Increment the pointer position.
					++currentByte;
					// If the position is on the SIZE then set on position 0.
					if (currentByte == SIZE)
						currentByte = 0;
					break;
				// If It decrements the pointer.
				case '<':
					// Decrement the pointer position.
					--currentByte;
					// If the position is negative then set on position 99.
					if (currentByte == -1)
						currentByte = 99;
					break;
				// If It increments value of currentByte byte.
				case '+':
					// Increment the value of the currentByte byte.
					++memory[currentByte];
					// If the value is equal to 256 then set 0.
					if (memory[currentByte] == 256)
						memory[currentByte] = 0;
					break;
				// If It decrements value of currentByte byte.
				case '-':
					// Increment the value of the currentByte byte.
					--memory[currentByte];
					// If the value is negative then set 255.
					if (memory[currentByte] == -1)
						memory[currentByte] = 255;
			}
		}
		
		// Print the number of test case.
		printf("Case %d:", i);
		
		// Print the memory value of the array.
		for (int j = 0; j < SIZE; ++j)
			printf(" %02X", memory[j]);

		printf("\n");
	}
	return 0;
}
