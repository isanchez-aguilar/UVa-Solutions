/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10924 - Prime Words
*/
#include <bits/stdc++.h>

using namespace std;

#define MAX 1200

bitset<MAX> noPrime;

void criba()
{
	noPrime[0] = true;

	for(int i = 2; i < MAX; ++i)
	{
		if(not noPrime[i])
		{
			for(int j = i * 2; j < MAX; j += i)
				noPrime[j] = true;
		}
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	map<char, int> value;
	for(char i = 'a'; i <= 'z'; ++i)
		value[i] = i - 'a' + 1;
	for(char i = 'A'; i <= 'Z'; ++i)
		value[i] = i - 'A' + 27; 

	string s;
	criba();
	while(cin >> s)
	{
		int sum = 0;
		for(int i = 0; i < s.length(); ++i)
		{
			sum += value[s[i]];
		}
		if(noPrime[sum])
			cout << "It is not a prime word.\n";
		else
			cout << "It is a prime word.\n";
	}

	return 0;
}