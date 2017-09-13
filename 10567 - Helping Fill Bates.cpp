/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10567 - Helping Fill Bates
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	char c;
	int i = 0;
	vector<int> index[257];

	while(cin.read(&c, 1) and c != '\n')
		index[c].push_back(i++);

	int q;
	cin >> q;
	while(q--)
	{
		string query;
		cin >> query;

		int first = 0;
		int last = -1;
		bool matched = true;
		int length = query.length();

		for(i = 0; i < length; ++i)
		{
			vector<int>::iterator j = upper_bound(index[query[i]].begin(), index[query[i]].end(), last);
			
			if(j == index[query[i]].end())
			{
				matched = false;
				break;
			}
			last = *j;
			if(!i)
				first = last;
		}

		if(matched)
			cout << "Matched " << first << " " << last << "\n";
		else
			cout << "Not matched\n";
	}

	return 0;
}
