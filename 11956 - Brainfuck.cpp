/*
*   User: Isanchez_Aguilar
*   Problem: UVA 11956 - Brainfuck
*/
#include <cstdio>

#define MAX_SIZE 100001
#define SIZE 100

int main(void)
{
    char commands[MAX_SIZE];
    int testCases;
    int current;
	int memory[SIZE];
	// Read the number of test cases.
    scanf("%d", &testCases);
	// Read the command of the cases.
    for (int i = 1; i <= testCases; ++i)
    {
		// Initialize the memory.
        for (int j = 0; j < SIZE; ++j)
            memory[j] = 0;
		// Current position of pointer.
        current = 0;
		// Read the commands.
        scanf("%s", commands);
		// Execute the commands.
        for (int j = 0; commands[j]; ++j)
        {
			// Evaluate the command.
			switch (commands[i])
            {
				// If It increments the pointer.
				case '>':
					// Increment the pointer position.
					++current;
					// If the position is on the SIZE then set on position 0.
					if (current == SIZE)
						current = 0;
					break;
				// If It decrements the pointer.
				case '<':
					// Decrement the pointer position.
					--current;
					// If the position is negative then set on position 99.
					if (current == -1)
						current = 99;
					break;
				// If It increments value of current byte.
				case '+':
					// Increment the value of the current byte.
					++memory[current];
					// If the value is equal to 256 then set 0.
					if (memory[current] == 256)
						memory[current] = 0;
					break;
				// If It decrements value of current byte.
				case '-':
					// Increment the value of the current byte.
					--memory[current];
					// If the value is negative then set 255.
					if (memory[current] == -1)
						memory[current] = 255;
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
