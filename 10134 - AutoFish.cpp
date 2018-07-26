/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10134 - AutoFish
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;
	
	cin.ignore();
	cin.ignore();

	while (testCases--)
	{
		string action;

		int bait = 0;
		int totalFish = 0;
		int baitUnits = 0;
		int fishInstruction = 0;
		int instructionsAfterFish = 0;

		while (getline(cin, action) and action.length())
		{
			if (action == "lunch" or (baitUnits == 3 and action == "bait") or (baitUnits == 0 and action == "fish"))
			{
				if (totalFish > 0)
					++instructionsAfterFish;
			}

			else if (action == "bait")
			{
				if (++bait == 2)
				{
					bait = 0;
					++baitUnits;
				}

				if (totalFish > 0)
					++instructionsAfterFish;
			}

			else if (action == "fish")
			{
				if (totalFish == 0)
				{
					--baitUnits;
					++totalFish;
				}

				else
				{
					++fishInstruction;
					++instructionsAfterFish;

					if (fishInstruction > 2 and instructionsAfterFish > 6)
					{
						--baitUnits;
						++totalFish;
						fishInstruction = 0;
						instructionsAfterFish = 0;
					}
				}
			}
		}

		cout << totalFish << "\n";

		if (testCases)
			cout << "\n";
	}

	return 0;
}