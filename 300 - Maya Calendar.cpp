/*
*	User: Isanchez_Aguilar
*	Problem: UVA 300 - Maya Calendar
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	map<string, int> monthHaab;
	vector<string> dayTzolkin(20);
	
	monthHaab["pop"] = 0;
	monthHaab["no"] = 1;
	monthHaab["zip"] = 2;
	monthHaab["zotz"] = 3;
	monthHaab["tzec"] = 4;
	monthHaab["xul"] = 5;
	monthHaab["yoxkin"] = 6;
	monthHaab["mol"] = 7;
	monthHaab["chen"] = 8;
	monthHaab["yax"] = 9;
	monthHaab["zac"] = 10;
	monthHaab["ceh"] = 11;
	monthHaab["mac"] = 12;
	monthHaab["kankin"] = 13;
	monthHaab["muan"] = 14;
	monthHaab["pax"] = 15;
	monthHaab["koyab"] = 16;
	monthHaab["cumhu"] = 17;
	monthHaab["uayet"] = 18;
	
	dayTzolkin[0] = "imix";
	dayTzolkin[1] = "ik";
	dayTzolkin[2] = "akbal";
	dayTzolkin[3] = "kan";
	dayTzolkin[4] = "chicchan";
	dayTzolkin[5] = "cimi";
	dayTzolkin[6] = "manik";
	dayTzolkin[7] = "lamat";
	dayTzolkin[8] = "muluk";
	dayTzolkin[9] = "ok";
	dayTzolkin[10] = "chuen";
	dayTzolkin[11] = "eb";
	dayTzolkin[12] = "ben";
	dayTzolkin[13] = "ix";
	dayTzolkin[14] = "mem";
	dayTzolkin[15] = "cib";
	dayTzolkin[16] = "caban";
	dayTzolkin[17] = "eznab";
	dayTzolkin[18] = "canac";
	dayTzolkin[19] = "ahau";
	
	int testCases;
	cin >> testCases;

	cout << testCases << "\n";

	for (int t = 0; t < testCases; ++t)
	{
		int day;
		int year;
		string month;

		cin >> day;
		cin.ignore(1, '.');
		cin >> month >> year;
		
		long days = day + monthHaab[month] * 20 + year * 365;		
		cout << days % 13 + 1 << " " << dayTzolkin[days % 20] << " " << days / 260 << "\n";
	}

	return 0;
}