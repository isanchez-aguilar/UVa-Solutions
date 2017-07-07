/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11608 - No Problem
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	int ready;
	int problemsPrepared[12];
	int problemsRequested[12];
	
	while(cin >> ready && ready > -1)
	{
		for(int i = 0; i < 12; ++i)
			cin >> problemsPrepared[i];
	
		cout << "Case " << ++t << ":\n";
	
		for(int i = 0; i < 12; ++i)
		{
			cin >> problemsRequested[i];

			if(problemsRequested[i] <= ready)
			{
				cout << "No problem! :D\n";
				ready -= problemsRequested[i]; 
			}
			else
				cout << "No problem. :(\n";
			
			ready += problemsPrepared[i]; 
		}

	}

	return 0;
}