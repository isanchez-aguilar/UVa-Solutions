/*
*	User: Isanchez_Aguilar
*	Problem: UVA 467 - Synching Signals
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Variable to read the time of signal.
	int signal;
	// Variable to know the number of test case.
	int numberTest = 1;
	// Read while not EOF
	while(cin >> signal)
	{
		// Variables to data of signals.
		char next;
		int minTime = signal;
		vector<int> signals;
		// Insert the first time signal.
		signals.push_back(signal);
		cin.read(&next, 1);
		// Read the time of every single signal while there is not a \n.
		while(next != '\n')
		{
			// Read the signal.
			if(!(cin >> signal))
				break;
			// Read the blank space or \n.
			cin.read(&next, 1); 
			// Insert the new time of signal
			signals.push_back(signal);
			// Get the minimum time.
			minTime = min(minTime, signal);
		}
		// Variable to know the time.
		int currenTime = minTime * 2;
		bool isGreen = false;
		// While is lower than the maximum time.
		while(currenTime <= 3600)
		{
			// Assume the signals are green.
			isGreen = true;
			// Check the current cycle to each signal. 
			for(int i = 0; i < signals.size(); ++i)
			{
				// If the signal is not on cycle of green then there is not relation with others.
				if(currenTime % (signals[i] * 2) >= signals[i] - 5)
				{
					isGreen = false;
					break;
				}
			}
			// If all the signals are green then break the cycle.
			if(isGreen)
				break;
			// Add a second.
			++currenTime;
		}
		// Print the number of test case.
		cout << "Set " << numberTest++;
		// If there is synchronization.
		if(isGreen)
			cout << " synchs again at " << currenTime / 60 << " minute(s) and " << currenTime % 60 << " second(s) " << "after all turning green.\n";
		else
			cout << " is unable to synch after one hour.\n";
	}
	return 0;
}