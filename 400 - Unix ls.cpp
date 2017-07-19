/*
*	User: Isanchez_Aguilar
*	Problem: UVA 400 - Unix ls
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<string> vs;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >> n)
	{
		vs filenames(n);
		int maxLength = 0;

		for(int i = 0; i < n; ++i)
		{
			cin >> filenames[i];
			maxLength = max(maxLength, (int)filenames[i].length());
		}
		
		sort(filenames.begin(), filenames.end());

		int columns = 62 / (maxLength + 2);
		int rows = ceil((double)n / (double)columns);

		cout << "------------------------------------------------------------\n";
		for(int i = 0; i < rows; ++i)
		{
			for(int j = i; j < n; j += rows)
			{
				cout << filenames[j];
				if(j + rows < n)
				{
					for(int k = filenames[j].length(); k < maxLength + 2; ++k)
						cout << " ";
				}
			}
			cout << "\n";
		}
	}

	return 0;
}