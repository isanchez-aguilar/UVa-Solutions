/*
*	User: Isanchez_Aguilar
*	Problem: UVA 661 - Blowing Fuses
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Data about electrical situation.
	int numberDevices;
	int numberSequences;
	int limitFuse;
	int currentSequence = 1;
	// Read while not EOF.
	while(cin >> numberDevices >> numberSequences >> limitFuse)
	{
		// If there is not more devices.
		if(!numberDevices)
			return 0;
		// Array to save the data of devices.
		vector<int> devices(numberDevices);
		// Read the data of devices.
		for(int i = 0; i < numberDevices; ++i)
			cin >> devices[i];
		// Variable to know the current.	
		int current = 0;
		// Variable to know the maximum current.
		int maximumCurrent = 0;
		// Variable to know the status of fuse.
		bool isBlown = false;
		// Read the sequence of devices.
		for(int i = 0; i < numberSequences; ++i)
		{
			// Read the device to be turn it.
			int device;
			cin >> device;
			if(!isBlown)
			{
				--device;
				// Add the status of device.
				current += devices[device];
				// Change the status of device.
				devices[device] = -devices[device];
				// Get the maximum current.
				maximumCurrent = max(current, maximumCurrent);
				// If the current is bigger than the supported by fuse then It is blown.
				if(limitFuse < current)
					isBlown = true;
			}
		}
		// Data of number test case.
		cout << "Sequence " << currentSequence++ << "\n";
		// If the fuse is not blown then print the maximum current.
		if(!isBlown)
			cout << "Fuse was not blown.\nMaximal power consumption was " << maximumCurrent << " amperes.\n\n";
		else
			cout << "Fuse was blown.\n\n";
	}
	return 0;
}