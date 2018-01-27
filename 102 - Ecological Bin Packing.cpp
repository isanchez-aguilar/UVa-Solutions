/*
*	User: Isanchez_Aguilar
*	Problem: UVA 102 - Ecological Bin Packing
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int bin[3][3];
	while(cin >> bin[0][0] >> bin[0][2] >> bin[0][1])
	{
		for(int i = 1; i < 3; ++i)
			cin >> bin[i][0] >> bin[i][2] >> bin[i][1];

		int c[3];
		int colours[3] = {0, 1, 2};
		char keyColour[4] = {'B', 'C' , 'G', '\0'};

		unsigned int minMovements = INT_MAX;
		do
		{
			unsigned int movements = 0;
			for(int i = 0; i < 3; ++i)
			{
				for(int j = 0; j < 3; ++j)
				{
					if(i != j)
						movements += bin[j][colours[i]];
				}
			}

			if(movements < minMovements)
			{
				minMovements = movements;
				//cout << movements << " ";
				for(int i = 0; i < 3; ++i)
				{
					//cout << keyColour[colours[i]];
					c[i] = colours[i];
				}
				//cout << "*\n";
			}
		}while(next_permutation(colours, colours + 3));
		
		for(int i = 0; i < 3; ++i)
			cout << keyColour[c[i]];

		cout << " " << minMovements << "\n";
	}

	return 0;
}