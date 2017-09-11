/*
*	User: Isanchez_Aguilar
*	Problem: UVA 416 - LED Test
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	string test[11];
	const string numbers[10] = 
	{
		"YYYYYYN",
		"NYYNNNN",
		"YYNYYNY",
		"YYYYNNY",
		"NYYNNYY",
		"YNYYNYY",
		"YNYYYYY",
		"YYYNNNN",
		"YYYYYYY",
		"YYYYNYY"
	};

	while(cin >> n and n)
	{
		for(int i = 0; i < n; ++i)
			cin >> test[i];

		bool match = false;
		for(int i = 9; i > n - 2; --i)
		{
			bitset<7> burned;
			int numbersMacthed;
			
			for(numbersMacthed = 0; numbersMacthed < n; ++numbersMacthed)
			{
				int ledsMatched;
				for(ledsMatched = 0; ledsMatched < 7; ++ledsMatched)
				{
					if(burned[ledsMatched] and test[numbersMacthed][ledsMatched] == 'Y')
						break;
					if(test[numbersMacthed][ledsMatched] == 'N' and numbers[i - numbersMacthed][ledsMatched] == 'Y')
						burned.set(ledsMatched);
					else if(test[numbersMacthed][ledsMatched] == 'Y' and numbers[i - numbersMacthed][ledsMatched] == 'N')
						break;
				}

				if(ledsMatched < 7)
					break;
			}
			if(numbersMacthed == n)
			{
				match = true;
				break;
			}
		}

		if(not match)
			cout << "MISMATCH\n";
		else
			cout << "MATCH\n";
	}

	return 0;
}