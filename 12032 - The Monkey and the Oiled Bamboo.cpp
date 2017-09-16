/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12032 - The Monkey and the Oiled Bamboo
*/
#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> height(10e5);

inline bool isPossible(int k)
{
	int lastHeight = 0;
	for(int i = 0; i < n; ++i)
	{
		int jump = height[i] - lastHeight;

		if(k < jump)
			return false;
		else if(k == jump)
				--k;
		lastHeight = height[i];
	}

	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;
	for(int t = 1; t <= testCases; ++t)
	{
		cin >> n;

		int maxJump = 0;
		int lastHeight = 0;

		for(int i = 0; i < n; ++i)
		{
			cin >> height[i];

			int jump = height[i] - lastHeight;
			
			if(maxJump < jump)
				maxJump = jump;

			lastHeight = height[i];
		}

		cout << "Case " << t << ": ";

		if(isPossible(maxJump))
			cout << maxJump << "\n";
		else
		{
			int k = maxJump << 1;			
			
			int rigth = k;
			int left = maxJump;
			int m = (left + rigth) >> 1;

			while(left < rigth)
			{
				if(isPossible(m))
				{
					k = m;
					rigth = m;
				}
				else
					left = m + 1;
				m = (left + rigth) >> 1;
			}

			cout << k << endl;
		}

	}
	return 0;
}