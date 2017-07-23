/*
*	User: Isanchez_Aguilar
*	Problem: UVA 978 - Lemmings Battle!
*/
#include <bits/stdc++.h>

using namespace std;

typedef queue<int> qi;
typedef multiset<int, greater<int> > msi;
typedef multiset<int, greater<int> >::iterator msii;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while(testCases--)
	{
		int blue;
		int green;
		int battlefield;
		msi bluePower;
		msi greenPower;

		cin >> battlefield >> green >> blue;
		
		for(int i = 0; i < green; ++i)
		{
			int power;
			cin >> power;
			greenPower.insert(power);
		}

		for(int i = 0; i < blue; ++i)
		{
			int power;
			cin >> power;
			bluePower.insert(power);
		}

		while(!bluePower.empty() && !greenPower.empty())
		{
			qi blueFighters;
			qi greenFighters;
			int minSize = min(battlefield, (int)min(bluePower.size(), greenPower.size()));
			
			for(int i = 0; i < minSize; ++i)
			{
				msii b = bluePower.begin();
				msii g = greenPower.begin();

				blueFighters.push(*b);
				greenFighters.push(*g);

				bluePower.erase(b);
				greenPower.erase(g);
			}
			for(int i = 0; i < minSize; ++i)
			{
				int b = blueFighters.front();
				int g = greenFighters.front();
			
				blueFighters.pop();
				greenFighters.pop();
			
				if(b == g)
					continue;
				if(b < g)
					greenPower.insert(g - b);
				else
					bluePower.insert(b - g);
			}
		}
		
		msii begin;
		msii end;

		if(bluePower.empty() && greenPower.empty())
		{
			cout << "green and blue died\n";
			if(testCases)
				cout << "\n";
			continue;
		}

		if(bluePower.empty())
		{
			cout << "green wins\n";

			end = greenPower.end();
			begin = greenPower.begin();
		}
		else
		{
			cout << "blue wins\n";

			end = bluePower.end();
			begin = bluePower.begin();
		}
		
		for(msii i = begin; i != end; ++i)
			cout << *i << "\n";
		if(testCases)
			cout << "\n";
	}

	return 0;
}