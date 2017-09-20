/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10656 - Maximum Sum (II)
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;

	while(cin >> n and n)
	{
		vector<int> numbers;
		for(int i = 0; i < n; ++i)
		{
			int number;
			cin >> number;
			if(number > 0)
				numbers.push_back(number);
		}

		int size = numbers.size();
		if(size)
		{
			for(int i = 0; i < size; ++i)
				cout << numbers[i] << (i + 1 == size?'\n':' ');
		}
		else
			cout << "0\n";
	}

	return 0;
}