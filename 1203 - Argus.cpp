/*
*	User: Isanchez_Aguilar
*	Problem: UVA 1203 - Argus
*/
#include <bits/stdc++.h>

using namespace std;

typedef multimap<pair< int, pair<int, int> >, int> mpii;
typedef multimap<pair< int, pair<int, int> >, int>::iterator mpiii;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int i = 0;
	mpii activities;

	while(cin >> s && s != "#")
	{
		int id;
		int period;
		cin >> id >> period;
		activities.insert(make_pair(make_pair(period, make_pair(id, period)), 1));
	}

	int activitiesNumber;
	cin >> activitiesNumber;

	while(activitiesNumber--)
	{
		mpiii i = activities.begin();

		int times = i->second + 1;
		int id = i->first.second.first;
		int period = i->first.second.second;
		
		cout << id << "\n";

		activities.erase(i);
		activities.insert(make_pair(make_pair(period * times, make_pair(id, period)), times));
	}
	return 0;
}