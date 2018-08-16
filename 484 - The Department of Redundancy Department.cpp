/*
*	User: Isanchez_Aguilar
*	Problem: UVA 484 - The Department of Redundancy Department
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	vector<int> number;
	map<int, int> frequency;

	while (cin >> n)
	{
		if (frequency.count(n) == 0)
			number.push_back(n);
		
		++frequency[n];
	}

	for (int i = 0; i < number.size(); ++i)
		cout << number[i] << " " << frequency[number[i]] << "\n";

	return 0;
}