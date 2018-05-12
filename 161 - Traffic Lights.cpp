/*
*	User: Isanchez_Aguilar
*	Problem: UVA 161 - Traffic Lights
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vi duration;

inline bool areGreen(int time)
{
	for (int i = 0; i < duration.size(); ++i)
	{
		int sequences = time / duration[i];
		// If It is the red interval then all are not green.
		if (sequences & 1)
			return false;
		int t = time % duration[i];
		// If It is the orange interval then all are not green.
		if (duration[i] - 5 <= t)
			return false;
	}
	
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	while (cin >> t and t)
	{
		int minDuration = t;
		duration.assign(1, t);
		while (cin >> t and t)
		{
			minDuration = min(minDuration, t);
			duration.push_back(t);
		}
		
		bool impossible = true;
		int time = minDuration << 1;
		int greenTime = minDuration - 5;
		
		while (time <= 18000)
		{
			for (t = 0; t <= greenTime; ++t)
			{
				if (time + t > 18000)
				{
					time = 18001;
					break;
				}
				if (areGreen(time + t))
				{
					time += t;
					impossible = false;
					break;
				}
			}
			if (not impossible)
				break;
			
			time += (minDuration << 1);
		}
		
		if (impossible)
			cout << "Signals fail to synchronise in 5 hours\n";
		else
		{
			int hours = time / 3600;
			int minutes = (time - hours * 3600) / 60;
			int seconds = time - hours * 3600 - minutes * 60;
			
			cout << setfill('0') << setw(2) << hours << ":";
			cout << setfill('0') << setw(2) << minutes << ":";
			cout << setfill('0') << setw(2) << seconds << "\n";
		}
	}
	
	return 0;
}
