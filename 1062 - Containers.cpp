/*
*	User: Isanchez_Aguilar
*	Problem: UVA 1062 - Containers
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	string containers;
	while(cin >> containers && containers[0] != 'e')
	{
		vector<char> stacks(1, containers[0]);
		int length = containers.length();

		for(int i = 1; i < length; ++i)
		{
			int k = -1;
			int minDifference = 'Z' + 1;

			for(int j = 0; j < stacks.size(); ++j)
			{
				if(stacks[j] >= containers[i] &&  stacks[j] - containers[i] < minDifference)
				{
					k = j;
					minDifference = containers[i] - stacks[j];
				}
			}

			if(k == -1)
				stacks.push_back(containers[i]);
			else
				stacks[k] = containers[i]; 
		}

		cout << "Case " << t++ << ": " << stacks.size() << "\n";
	}

	return 0;
}