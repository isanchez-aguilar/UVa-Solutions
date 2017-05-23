/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12554 - A Special "Happy Birthday" Song!!!
*/
#include <bits/stdc++.h>

using namespace std;

// Array to lyrics.
char song[9][10] = {"Happy\0", "birthday\0", "to\0", "you\0", "Happy\0", "birthday\0", "to\0", "Rujia\0"};
// Variable to save the number of people.
int numberPersons;
// Array to save the names.
vector<string> persons(100);
// Variable to know the person that must to sing.
int currentPerson = 0;

void sing(int times, int initial, int end)
{
	for(int i = 0; i < times; ++i)
	{
		for(int j = initial; j < end; ++j)
		{
			// If the current person is bigger than the maximum of persons then start with the first. 
			currentPerson %= numberPersons;
			// Print the name of person and the word that must to sing.
			cout << persons[currentPerson] << ": " << song[j] << "\n";
			// Select the next person.
			++currentPerson;
		}
	}
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Read the number of persons.
	cin >> numberPersons;
	// Read the persons to store on the array.
	for(int i = 0; i < numberPersons; ++i)
		cin >> persons[i];
	// Variable to know the times that they must to sing.
	int times = numberPersons / 16 + 1;
	// Print the lyrics.
	while(times--)
	{
		sing(2, 0, 4);
		sing(1, 4, 8);
		sing(1, 0, 4);
	}
	return 0;
}