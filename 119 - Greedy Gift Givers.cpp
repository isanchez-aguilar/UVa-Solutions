/*
*	User: Isanchez_Aguilar
*	Problem: UVA 119 - Greedy Gift Givers
*/
#include <bits/stdc++.h>

using namespace std;

string wanted;

bool isEqual(const pair<string, int> &a) { return (a.first == wanted); }

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Variable to save the number of people.
	int numberPeople;
	// Number of test cases.
	int testCases = 0;
	// Read while not EOF.
	while(cin >> numberPeople)
	{
		if(testCases++)
			cout << "\n";
		// Array to save the information of every single person.
		vector< pair<string, int> > people(numberPeople);
		// Read the names of persons.
		for(int i = 0; i < numberPeople; ++i)
		{
			// Read the name of person.
			string name;
			cin >> name;
			// Initialize the value and add the name of the person.
			people[i] = make_pair (name, 0);
		}
		// Read the situation every person.
		for(int i = 0; i < numberPeople; ++i)
		{
			// Read the name of person.
			cin >> wanted;
			// Read the money to spent.
			int money;
			cin >> money;
			// Read the number of people who gave them a gift.
			int gifts;
			cin >> gifts;
			// If the person gave gifts.
			if(gifts)
			{	
				// Compute the value of every single gift.
				int giftValue = money / gifts;
				// Set the money spent on gifts.
				vector< pair<string, int> >::iterator dataPerson = find_if(people.begin(), people.end(), isEqual);
				dataPerson->second -= giftValue * gifts;
				// Read the names of people who gave them a gift.
				for(int j = 0; j < gifts; ++j)
				{
					// Read the name of person who received a gift.
					cin >> wanted;
					// Search and set the money spent to this person.
					vector< pair<string, int> >::iterator dataPerson = find_if(people.begin(), people.end(), isEqual);
					dataPerson->second += giftValue;
				}
			}
		}
		// Print the information of every single person.
		for(int i = 0; i < numberPeople; ++i)
			cout << people[i].first << " " << people[i].second << "\n";
	}
	return 0;
}