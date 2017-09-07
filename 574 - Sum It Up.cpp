/*
*	User: Isanchez_Aguilar
*	Problem: UVA 574 - Sum It Up
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vi s;
int n;
int total;
int number[20];
bool solution;
map<vi, bool> found;

void findSums(int size, int index, int sum)
{
	if(sum == total)
	{
		if(found[s])
			return;
		
		solution = true;
		found[s] = true;

		for(int i = 0; i < size; ++i)
			cout << s[i] << (i + 1 == size?"\n":"+");

		return;
	}
	
	if(total < sum or n == index)
		return;

	for(int i = index; i < n; ++i)
	{
		s.push_back(number[i]);

		findSums(size + 1, i + 1, sum + number[i]);

		s.pop_back();
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> total >> n and (total or n))
	{
		for(int i = 0; i < n; ++i)
			cin >> number[i];
		
		found.clear();
		solution = false;
		cout << "Sums of " << total << ":\n";
		findSums(0, 0, 0);

		if(!solution)
			cout << "NONE\n";
	}

	return 0;
}