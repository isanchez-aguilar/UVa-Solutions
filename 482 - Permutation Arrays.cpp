/*
*	User: Isanchez_Aguilar
*	Problem: UVA 482 - Permutation Arrays
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	char c;
	string index;
	int testCases;
	cin >> testCases;
	while(testCases--)
	{
		vector<int> p(0);
		// Read permutation indexs.
		do
		{
			int i;
			cin >> index;
			stringstream s(index);
			
			s >> i;
			p.push_back(i);
			cin.read(&c, 1);
		}while(c != '\n');
		
		int size = p.size();
		vector<string> data(size);
		vector<string> permutation(size);
		// Read numbers of array.
		for(int i = 0; i < size; ++i)
			cin >> data[i];
		// Executing the permutation.
		for(int i = 0; i < size; ++i)
			permutation[p[i] - 1] = data[i];
		// Print the permutation.
		for(int i = 0; i < size; ++i)
			cout << permutation[i] << "\n";
		if(testCases)
			cout << "\n";
	}

	return 0;
}