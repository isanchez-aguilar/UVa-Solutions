/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12468 - Zapping
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Variable to save the channels.
	int initialChannel;
	int targetChannel;
	// Read while not EOF.
	while(cin >> initialChannel >> targetChannel && initialChannel + targetChannel != -2)
	{
		// Get the absolute value of the difference.
		int difference = abs(targetChannel - initialChannel);
		// If the difference is bigger than 50 then compute the difference to reverse.
		if(difference >  50)
			difference = 100 - difference;
		// Print the minimum moves.
		cout << difference << "\n";
	}
	return 0;
}