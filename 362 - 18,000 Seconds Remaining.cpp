/*
*	User: Isanchez_Aguilar
*	Problem: UVA 362 - 18,000 Seconds Remaining
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 0;
	int bytes;
	while (cin >> bytes and bytes)
	{
		int time = 0;
		int currentBytes;
		int last5Seconds = 0;
			
		cout << "Output for data set " << ++t << ", " << bytes << " bytes:\n";
		while (bytes and cin >> currentBytes)
		{
			bytes -= currentBytes;
			last5Seconds += currentBytes;
			
			if (++time % 5 == 0)
			{
				if (last5Seconds)
				{
					cout << "   Time remaining: " << (int)ceil((double)bytes / (last5Seconds) * 5.0) << " seconds\n";
					last5Seconds = 0;
				}
				else
					 cout << "   Time remaining: stalled\n";
			}
		}
		
		cout << "Total time: " << time << " seconds\n\n";
	}
	
	return 0;
}
