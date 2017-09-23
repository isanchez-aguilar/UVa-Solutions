/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11824 - A Minimum Land Price
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int L[41];
	int testCases;
	
	cin >> testCases;
	while(testCases--)
	{
		int size = 0;
		
		while(cin >> L[size] and L[size])
			++size;

		sort(L, L + size, greater<int>());

		int current = 0;

		for(int i = 0; i < size; ++i)
		{
			current += (int)pow(L[i], i + 1) << 1;
			if(current > 5000000)
				break;
		}

		if(current <= 5000000)
			cout << current << "\n";
		else
			cout << "Too expensive\n";
	}

	return 0;
}