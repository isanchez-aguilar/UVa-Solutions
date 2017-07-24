/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11827 - Maximum GCD
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	vector<int> number(100);

	cin >> testCases;
	cin.ignore();
	
	while(testCases--)
	{
		string numbers;

		getline(cin, numbers);
		istringstream in(numbers);
		
		int index = 0;
		while(in >> number[index] && ++index);

		int gcd = 0;
		
		for(int i = 0; i < index; ++i)
		{
			for(int j = i + 1; j < index; ++j)
				gcd = max(gcd, __gcd(number[i], number[j]));
		}
		
		cout<< gcd << "\n";
	}
}