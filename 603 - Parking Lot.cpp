/*
*	User: Isanchez_Aguilar
*	Problem: UVA 603 - Parking Lot
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;
	int parkingPlaceCar[21];

	while (testCases--)
	{
		int p;
		vii position;
		vi waitingCar;

		while (cin >> p and p != 99)
		{
			waitingCar.push_back(p);
			position.push_back(ii(p, p));
		}
		
		sort(position.begin(), position.end());
		memset(parkingPlaceCar, -1, sizeof parkingPlaceCar);
		
		string line;
		cin.ignore();

		while (getline(cin, line) and line.length())
		{
			int parkingPlace;
			istringstream in(line);
			int closestPosition = -1;

			in >> parkingPlace;

			for (int i = 0; i < position.size(); ++i)
			{
				int j = 0;
				if (position[i].first > parkingPlace)
				{
					if (i == 0)
						closestPosition = position.size() - 1;
					else
						closestPosition = i - 1;
					
					break;
				}

				if (i + 1 == position.size())
					closestPosition = position.size() - 1;
			}

			parkingPlaceCar[position[closestPosition].second] = parkingPlace;
			
			int parkingPlaceDist = 0; 

			if (position[closestPosition].first <= parkingPlace)
				parkingPlaceDist = parkingPlace - position[closestPosition].first;
			else
				parkingPlaceDist = parkingPlace + 20 - position[closestPosition].first;

			position.erase(position.begin() + closestPosition);

			for (int j = 0; j < position.size(); ++j)
			{
				position[j].first += parkingPlaceDist;

				if (position[j].first > 20)
					position[j].first %= 20;
			}

			sort(position.begin(), position.end());	
		}

		for (int i = 0; i < waitingCar.size(); ++i)
		{
			cout << "Original position " << waitingCar[i];

			if (parkingPlaceCar[waitingCar[i]] == -1)
				cout << " did not park\n";
			else
				cout << " parked in " << parkingPlaceCar[waitingCar[i]] << "\n";
		}

		if (testCases)
			cout << "\n";
	}

	return 0;
}