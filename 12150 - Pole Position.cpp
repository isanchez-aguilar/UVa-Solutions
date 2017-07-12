/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12150 - Pole Position
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	

	int carsNumber;
	while(cin >> carsNumber && carsNumber)
	{
		bool possible = 1;
		vi cars(carsNumber, 0);
		for(int i = 0; i < carsNumber; ++i)
		{
			int id;
			int position;

			cin >> id >> position;
			int tempPos = position + i;
			
			if(possible)
			{
				if(tempPos < 0 || tempPos > carsNumber - 1)
					possible = 0;
				else if(!cars[tempPos])
					cars[tempPos] = id;
				else
					possible = 0;
			}
		}

		if(possible)
		{
			for(int i = 0; i < carsNumber; ++i)
				cout << cars[i] << (i + 1 < carsNumber?" ":"\n");
		}
		else
			cout << "-1\n";
	}

	return 0;
}