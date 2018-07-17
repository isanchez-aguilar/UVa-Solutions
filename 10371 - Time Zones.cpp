/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10371 - Time Zones
*/
#include <bits/stdc++.h>

#define MINUTES_DAY 1440

using namespace std;

int main(void)
{
	map<string, int> minutesDifference;

	minutesDifference["UTC"] = 0;
	minutesDifference["GMT"] = 0;
	minutesDifference["BST"] = 60;
	minutesDifference["IST"] = 60;
	minutesDifference["WET"] = 0;
	minutesDifference["WEST"] = 60;
	minutesDifference["CET"] = 60;
	minutesDifference["CEST"] = 120;
	minutesDifference["EET"] = 120;
	minutesDifference["EEST"] = 180;
	minutesDifference["MSK"] = 180;
	minutesDifference["MSD"] = 240;
	minutesDifference["AST"] = -240;
	minutesDifference["ADT"] = -180;
	minutesDifference["NST"] = -210;
	minutesDifference["NDT"] = -150;
	minutesDifference["EST"] = -300;
	minutesDifference["EDT"] = -240;
	minutesDifference["CST"] = -360;
	minutesDifference["CDT"] = -300;
	minutesDifference["MST"] = -420;
	minutesDifference["MDT"] = -360;
	minutesDifference["PST"] = -480;
	minutesDifference["PDT"] = -420;
	minutesDifference["HST"] = -600;
	minutesDifference["AKST"] = -540;
	minutesDifference["AKDT"] = -480;
	minutesDifference["AEST"] = 600;
	minutesDifference["AEDT"] = 660;
	minutesDifference["ACST"] = 570;
	minutesDifference["ACDT"] = 630;
	minutesDifference["AWST"] = 480;
	
	int testCases;
	cin >> testCases;
	
	while (testCases--)
	{
		string s;
		cin >> s;

		int minutes;
		string status;

		switch (s[0])
		{
			case 'n':
				minutes = 720;
			break;
		
			case 'm':
				minutes = 0;
			break;
		
			default:
				int hours;
				istringstream in(s);
				
				in >> hours;
				in.ignore(1, ':');
				in >> minutes;

				cin >> status;

				minutes += (hours % 12) * 60;

				if (status[0] == 'p')
					minutes += 720;
		}
		
		string zone1;
		string zone2;
		cin >> zone2 >> zone1;

		minutes = (minutes + minutesDifference[zone1] - minutesDifference[zone2] + MINUTES_DAY) % MINUTES_DAY;
		
		if (minutes == 720)
			cout << "noon\n";
		else if (minutes == 0)
			cout << "midnight\n";
		else
		{
			status = (minutes > 720 and minutes < MINUTES_DAY)?"p.m.":"a.m.";

			minutes %= 720;
			
			if (minutes / 60 == 0)
				minutes += 720;
			
			cout << minutes / 60 << ":" << setw(2) << setfill('0') << minutes % 60 << " " << status << "\n";
		}
	}

	return 0;
}