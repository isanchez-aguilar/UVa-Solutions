/*
*	User: Isanchez_Aguilar
*	Problem: UVA 489 - Hangman Judge
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int round;
	char letter;
	// While there is a round.
	while(scanf("%d", &round) && round != -1)
	{
		int letters = 0;
		bitset<26> word;
		bitset<26> attempts;
		getchar();
		printf("Round %d\n", round);
		// Read the word.
		while((letter = getchar()) != '\n')
		{
			// If the letter has not yet been read then increase the letters.
			if(!word[letter - 'a'])
				++letters;
			// Set the read letter.
			word[letter - 'a'] = 1;
		}
		// Initialize the errors that are still missing.
		int mistakes = 7;
		// Read the guessing letters.
		while((letter = getchar()) != '\n')
		{
			// If the letter has not yet benn use.
			if(!attempts[letter - 'a'])
			{			
				// If the letter is not at word then decrease the mistakes.
				if(!word[letter - 'a'] && letters > 0)
					--mistakes;
				// If the letter is at word then decrease the missing letters.
				else
					--letters;
				// Set the guessing letter,
				attempts[letter - 'a'] = 1;
			}
		}
		// If the misatkes has already been use then you lose.
		if(mistakes <= 0)
			printf("You lose.\n");
		// If the letters has already been use then you win.
		else if(letters < 1)
			printf("You win.\n");
		// If the guessing letters was not enough then You chickened out.
		else
			printf("You chickened out.\n");
	}
	return 0;
}