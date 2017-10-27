/*
*	User: Isanchez_Aguilar
*	Problem: UVA 902 - Password Search
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	string s;
	
	while(cin >> n >> s)
	{
		string maxS;
		int maxFreq = 0;
		map<string, int> frequency;
		
		int length = s.length();
		for(int i = 0; i + n <= length; ++i)
		{
			string sub = s.substr(i, n);
			int freq = ++frequency[sub];
			if(freq > maxFreq)
			{
				maxS = sub;
				maxFreq = freq;	
			}
		}
		
		cout << maxS << "\n";
	}
	
	return 0;
}
