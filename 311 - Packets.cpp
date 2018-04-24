/*
*	User: Isanchez_Aguilar
*	Problem: UVA 311 - Packets
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int boxes[7];
	
	while (true)
	{
		bool endOfFile = true;
		for (int i = 1; i <= 6; ++i)
		{
			cin >> boxes[i];
			
			if (boxes[i])
				endOfFile = false;
		}
		
		if (endOfFile)
			break;
			
		int minParcels = boxes[6];
		
		boxes[1] -= boxes[5] * 11;
		minParcels += boxes[5];
		
		boxes[2] -= boxes[4] * 5;
		minParcels += boxes[4];
		
		minParcels += (boxes[3] >> 2);
		
		int module = boxes[3] & 3;
		if (module)
		{
			++minParcels;
			
			if (module == 1)
			{
				boxes[1] -= 7;
				boxes[2] -= 5;
			}
			else if (module == 2)
			{
				boxes[1] -= 6;
				boxes[2] -= 3;
			}
			else if (module == 3)
			{
				boxes[1] -= 5;
				boxes[2] -= 1;
			}
		}
		
		if (boxes[2] < 0)
			boxes[1] += (boxes[2] << 2);
		else
		{
			minParcels += (boxes[2] / 9);
			module = boxes[2] % 9;
			
			if (module)
			{
				++minParcels;
				boxes[1] -= (9 - module) * 4;
			}
		}
		
		if (boxes[1] > 0)
			minParcels += ceil((double)boxes[1]/36.0);
		
		cout << minParcels << "\n";
	}
	
	return 0;
}
