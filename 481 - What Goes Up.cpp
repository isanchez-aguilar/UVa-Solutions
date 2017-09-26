/*
*	User: Isanchez_Aguilar
*	Problem: UVA 481 - What Goes Up
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int value;
	vector<int> endValue;
	vector<int> index(1, 0);

	vector<int> values;

	while(cin >> value)
		values.push_back(value);

	int size = values.size();
	vector<int> parent(size);

	parent[0] = -1;
	endValue.push_back(values[0]);

	for(int i = 1; i < size; ++i)
	{
		int j = lower_bound(endValue.begin(), endValue.end(), values[i]) - endValue.begin();

		if(j == endValue.size())
		{
			parent[i] = index[index.size() - 1];
			endValue.push_back(values[i]);
			index.push_back(i);
		}
		else
		{
			if(!j)
				parent[i] = -1;
			else
				parent[i] = index[j - 1];

			index[j] = i;
			endValue[j] = values[i];
		}
	}

	cout << endValue.size() << "\n-\n";

	list<int> ans;
	int i = index[index.size() - 1];
	while(i != -1)
	{
		ans.push_front(values[i]);
		i = parent[i];
	}

	for(list<int>::iterator j = ans.begin(); j != ans.end(); ++j)
		cout << *j << "\n";

	return 0;
}