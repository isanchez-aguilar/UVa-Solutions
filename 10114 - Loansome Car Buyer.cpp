/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10114 - Loansome Car Buyer
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Variables to information of loan.
	double months;
	double downPayment;
	double loan;
	int depreciations;
	// Vector to save the depreciations.
	vector<double> depreciationValue(101);
	// While the months are positive.
	while(cin >> months >> downPayment >> loan >> depreciations and months >= 0)
	{
		// Read the depreciations while there is.
		while(depreciations--)
		{
			// Variable to know the month whit value of depreciation.
			int month;
			// Depreciation of month.
			double depreciation;
			cin >> month >> depreciation;
			// Assign depreciation to rest of months
			for(int i = month; i < 101; ++i)
				depreciationValue[i] = 1 - depreciation;

		}
		// Variable to know the current month of loan.
		int currentMonth = 0;
		// Monthly payment of loan for months.
		double monthlyPayment = loan / months;
		// Current value from the initial debt.
		double currentValue = (loan + downPayment) * depreciationValue[0];
		// While the debt is bigger tha value's car.
		while(currentValue < loan)
		{
			loan -= monthlyPayment;
			currentValue = currentValue * depreciationValue[++currentMonth];
		}
		// Print the month when the loan is lesser than current value's car.
		// If is just one month.
		if(currentMonth == 1)
			cout << currentMonth << " month\n";
		// If It is plural that is more tha one month.
		else
			cout << currentMonth << " months\n";
	}
	return 0;
}
