/*
*	User: Isanchez_Aguilar
*	Problem: UVA 624 - CD
*/
#include <bits/stdc++.h>

using namespace std;

int cds;
int sum;
int size;
int tracks[21];
vector<int> tracklist;

inline void searhTracklist(vector<int> currentTracklist, int currentSum, int index)
{
	currentSum += tracks[index];
	if(size < currentSum)
		return;
	
	currentTracklist.push_back(tracks[index]);

	if(sum < currentSum or (sum == currentSum and tracklist.size() < currentTracklist.size()))
	{
		sum = currentSum;
		tracklist = currentTracklist;
	}

	for(int i = index + 1; sum != size and i < cds; ++i)
		searhTracklist(currentTracklist, currentSum, i);
	
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> size)
	{
		cin >> cds;

		for(int i = 0; i < cds; ++i)
			cin >> tracks[i];

		sum = 0;
		tracklist.clear();
		for(int i = 0; i < cds; ++i)
		{
			vector<int> temp;
			searhTracklist(temp, 0, i);
		}

		for(int i = 0; i < tracklist.size(); ++i)
			cout << tracklist[i] << " ";
		cout << "sum:" << sum << "\n";
	}

	return 0;
}