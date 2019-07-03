/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10489 - Boxes of Chocolates
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int testCases;
	cin >> testCases;
	
	while (testCases--)
	{
		int boxes;
		int friends;
		cin >> friends >> boxes;
		
		int result = 0;
		while (boxes--)
		{
			int smallBoxes;
			int residue = 1;
			cin >> smallBoxes;
			
			while (smallBoxes--)
			{
				int box;
				cin >> box;
				
				residue = residue * box % friends;
			}
			
			result = (result + residue) % friends;
		}
		
		cout << result << "\n";
	}

	return 0;
}
