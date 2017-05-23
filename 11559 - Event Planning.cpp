/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11559 - Event Planning
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Variable to save the data of excursion.
	int persons;
	int budget;
	int hotels;
	int weeks;
	// Read while not EOF.
	while(cin >> persons >> budget >> hotels >> weeks)
	{
		// Initializing the minimum cost to impossible cost.
		int minimumCost = budget + 1;
		for(int i = 0; i < hotels; ++i)
		{
			// Initializing the number of available beds.
			int availableBeds = 0;
			// Price per person.
			int personPrice;
			cin >> personPrice;
			// Read the information about the occupational of weekend for the next weeks.
			for(int j = 0; j < weeks; ++j)
			{
				// Read the occupational of current j week.
				int beds;
				cin >> beds;
				// Get the max of available beds between the previous weeks and the current.
				availableBeds = max(availableBeds, beds);
			}
			// If there are enough beds then get minimum cost between the previous hotels.
			if(availableBeds >= persons)
				minimumCost = min(persons * personPrice, minimumCost);
		}
		// If the budget is enough to pay then print the minimum cost.
		if(minimumCost <= budget)
			cout << minimumCost << "\n";
		// If the budget is not enough to stay in a hotel then print stay home.
		else
			cout << "stay home\n";
	}
	return 0;
}