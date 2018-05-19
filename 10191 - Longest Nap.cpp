/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10191 - Longest Nap
*/
#include <bits/stdc++.h>

using namespace std;

inline int getMinutes(int h, int m)
{
	return h * 60 + m;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int day = 0;
	int appointments;
	bool schedule[481];
	while (cin >> appointments)
	{
		memset(schedule, false, sizeof schedule);
		
		for (int i = 0; i < appointments; ++i)
		{
			int hEnd;
			int mEnd;
			char dots;
			int hStart;
			int mStart;
			string name;
			
			cin >> hStart >> dots >> mStart >> hEnd >> dots >> mEnd;
			
			for (int i = getMinutes(hStart, mStart) - 600; i < getMinutes(hEnd, mEnd) - 600; ++i)
				schedule[i] = true;
			
			getline(cin, name);
		}
		
		int startH;
		int startM;
		int maxNap = -1;
		
		for (int i = 0; i < 480; ++i)
		{
			if (not schedule[i])
			{
				int m = i % 60;
				int startI = i;
				int h = i / 60 + 10;

				while (i + 1 < 480 and not schedule[i + 1])
					++i;
					
				if (i - startI + 1 > maxNap)
				{
					startH = h;
					startM = m;
					maxNap = i - startI + 1;
				}
			}
		}
		
		cout << "Day #" << ++day << ": the longest nap starts at " << setfill('0') << setw(2) << startH << ":" << setfill('0') << setw(2) << startM << " and will last for ";
		
		if (maxNap >= 60)
			cout << maxNap / 60 << " hours and ";
			
		cout << maxNap % 60 << " minutes.\n";
	}
	
	return 0;
}
