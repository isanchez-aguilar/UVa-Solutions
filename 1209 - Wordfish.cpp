/*
*	User: Isanchez_Aguilar
*	Problem: UVA 1209 - Wordfish
*/
#include <bits/stdc++.h>

using namespace std;

int size;

inline int getMinimum(string s)
{
	int minimum = INT_MAX;

	for(int i = 0; i < size - 1; ++i)
		minimum = min(minimum, abs((int)s[i] - (int)s[i + 1]));

	return minimum;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string username;
	while(cin >> username)
	{
		size = username.length();
		string permutation = username;
		int maximum = getMinimum(username);

		string aux = username;
		for(int i = 0; i < 10 and prev_permutation(aux.begin(), aux.end()); ++i)
		{
			int difference = getMinimum(aux);
			
			if(maximum <= difference)
			{
				maximum = difference;
				permutation = aux;
			}
		}
		
		aux = username;
		for(int i = 0; i < 10 and next_permutation(aux.begin(), aux.end()); ++i)
		{
			int difference = getMinimum(aux);
			
			if(maximum < difference)
			{
				maximum = difference;
				permutation = aux;
			}
		}

		cout << permutation << maximum << "\n";
	}

	return 0;
}