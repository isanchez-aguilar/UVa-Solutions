/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11530 - SMS Typing
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int testCases;
	const int keys[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
	
	cin >> testCases;
	cin.ignore();
	
	for (int t = 1; t <= testCases; ++t)
	{
		cout << "Case #" << t << ": ";
		
		string message;
		getline(cin, message);
		
		int total = 0;
		for (int i = 0; i < message.length(); ++i)
		{
			if (message[i] == ' ')
				++total;
			else
				total += keys[message[i] - 'a'];
		}
		
		cout << total << "\n";
	}
	
	return 0;
}
