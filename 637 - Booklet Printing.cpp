/*
*	User: Isanchez_Aguilar
*	Problem: UVA 637 - Booklet Printing
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >> n and n)
	{
		if(n == 1)
			cout << "Printing order for 1 pages:\n" << "Sheet 1, front: Blank, 1\n";
		else
		{
			cout << "Printing order for " << n << " pages:\n";
		
			int sheet = ceil(n / 4.0);
		
			int front = 1;
			int back = sheet << 2;
		
			for(int j = 1; j <= sheet; ++j)
			{
				cout << "Sheet " << j << ", front: ";
				
				if(n < back)
					cout << "Blank";
				else
					cout << back;

				cout << ", " << front << "\n";

				--back;
				++front;

				cout << "Sheet " << j << ", back : " << front << ", ";
				
				if(n < back)
					cout << "Blank";
				else
					cout << back;
				
				cout << "\n";

				--back;
				++front;
			}
		}
	}

	return 0;
}