/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10107 - What is the Median?
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int size = 0;
	bool pair = 0;
	vector<int> numbers;

	while(cin >> n)
	{
		++size;
		numbers.push_back(n);
		sort(numbers.begin(), numbers.end());
		
		if(pair)
			cout << ((numbers[size >> 1] + numbers[(size >> 1) - 1]) >> 1) << endl;
		else
			cout << numbers[size >> 1] << endl;
		pair = !pair;
	}

	return 0;
}