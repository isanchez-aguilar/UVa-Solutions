/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11945 - Financial Management
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int testCases;
	cin >> testCases;
	
	for (int t = 1; t <= testCases; ++t)
	{
		cout << t << " $";
		
		double total = 0;
		for (int i = 0; i < 12; ++i)
		{
			double value;
			cin >> value;
			
			total += value;
		}
		
		total /= 12;
			
		if (total >= 1000)
		{	
			ostringstream out;
			out << fixed << setprecision(2) << total;
			
			string totalStr;
			string n = out.str();
			
			for (int i = n.length() - 1; i >= 0; --i)
			{
				if (n.length() - i == 7)
					totalStr += ",";
				totalStr += n[i];
			}
			
			reverse(totalStr.begin(), totalStr.end());
			
			cout << totalStr << "\n";
		}
		else
			cout << fixed << setprecision(2) << total << "\n";
	}
	
	return 0;
}
