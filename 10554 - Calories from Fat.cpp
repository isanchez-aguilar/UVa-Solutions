/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10554 - Calories from Fat
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<double, char> dc;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string line;
	const double calories[5] = {9, 4, 4, 4, 7};
	
	while (getline(cin, line) and line != "-")
	{
		dc data[5];
		double totalFat = 0;
		double totalCalories = 0;
		
		do
		{
			double subTotal = 0;
			istringstream in(line);
			double totalPorcentage = 0;
			
			for (int i = 0; i < 5; ++i)
			{
				string information;
				in >> information;
				
				double amount = (double)stoi(information);
				char unity = information[information.length() - 1];
				
				switch(unity)
				{
					case 'C':
						if (i == 0)
							totalFat += amount;
						subTotal += amount;
						totalCalories += amount;
					break;
					case '%':
						totalPorcentage += amount;
					break;
					case 'g':
						if (i == 0)
							totalFat += amount * 9;
						subTotal += amount * calories[i];
						totalCalories += amount * calories[i];
					break;
				}
				
				data[i] = make_pair(amount, unity);
			}
			
			if (data[0].second == '%')
				totalFat += data[0].first * subTotal / (100.00 - totalPorcentage);
			
			totalCalories += subTotal * totalPorcentage / (100.00 - totalPorcentage);
		}while (getline(cin, line) and line != "-");
		
		cout << (int)round(totalFat / totalCalories * 100.00) << "%\n";
	}
	
	return 0;
}
