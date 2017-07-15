/*
*	User: Isanchez_Aguilar
*	Problem: UVA 466 - Mirror, Mirror
*/
#include <bits/stdc++.h>

using namespace std;

int n;

inline bool isRotated90(vector<string> &pattern, vector<string> &modification)
{
	for(int i = 0, k = n - 1; i < n; ++i, --k)
	{
		for(int j = 0; j < n; ++j)
		{
			if(pattern[i][j] != modification[j][k])
				return 0;
		}
	}
	return 1;
}

inline bool isRotated180(vector<string> &pattern, vector<string> &modification)
{
	for(int i = 0, k = n - 1; i < n; ++i, --k)
	{
		for(int j = 0, l = n - 1; j < n; ++j, --l)
		{
			if(pattern[i][j] != modification[k][l])
				return 0;
		}
	}
	return 1;
}

inline bool isRotated270(vector<string> &pattern, vector<string> &modification)
{
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0, k = n - 1; j < n; ++j, --k)
		{
			if(pattern[i][j] != modification[k][i])
				return 0;
		}
	}
	return 1;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

	while(cin >> n)
	{
		bool preserved = 1;
		vector<string> pattern(n);
		vector<string> modification(n);

		for(int i = 0; i < n; ++i)
		{
			cin >> pattern[i] >> modification[i];
			if(pattern[i] != modification[i])
				preserved = 0;
		}
		if(preserved)
			cout << "Pattern " << t++ << " was preserved.\n";
		else if(n == 1)
			cout << "Pattern " << t++ << " was improperly transformed.\n";
		else
		{
			if(isRotated90(pattern, modification))
				cout << "Pattern " << t++ << " was rotated 90 degrees.\n";
			else
			{
				if(isRotated180(pattern, modification))
					cout << "Pattern " << t++ << " was rotated 180 degrees.\n";
				else
				{
					if(isRotated270(pattern, modification))
						cout << "Pattern " << t++ << " was rotated 270 degrees.\n";
					else
					{
						bool reflection = 1;
						for(int i = 0; i < (n >> 1); ++i)
						{
							swap(pattern[i], pattern[n - i - 1]);
							if(pattern[i] != modification[i])
								reflection = 0;
						}
						if(reflection)
							cout << "Pattern " << t++ << " was reflected vertically.\n";
						else
						{
							if(isRotated90(pattern, modification))
								cout << "Pattern " << t++ << " was reflected vertically and rotated 90 degrees.\n";
							else
							{
								if(isRotated180(pattern, modification))
									cout << "Pattern " << t++ << " was reflected vertically and rotated 180 degrees.\n";
								else
								{
									if(isRotated270(pattern, modification))
										cout << "Pattern " << t++ << " was reflected vertically and rotated 270 degrees.\n";
									else
										cout << "Pattern " << t++ << " was improperly transformed.\n";
								}
							}
						}
					}
				}
			}
		}

	}
	return 0;
}