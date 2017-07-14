/*
*	User: Isanchez_Aguilar
*	Problem: UVA 755 - 487--3279
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;
	const char mapping[26] = {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5', '6', '6', '6', '7', 'Q', '7', '7', '8', '8', '8', '9', '9', '9', 'Z'};
	
	while(testCases--)
	{
		int numbers;
		cin >> numbers;
		vector<string> repeated(0);
		map<string, int> frequency;
		while(numbers--)
		{
			string number;
			cin >> number;
			string standarNumber("");
			int length = number.length();

			for(int i = 0; i < length; ++i)
			{
				if(number[i] != '-')
				{
					if(isalpha(number[i]))
					{
						standarNumber += mapping[number[i] - 'A'];
					}
					else
						standarNumber += number[i];
				}
			}
			standarNumber.insert(3, "-");
			
			if(++frequency[standarNumber] == 2)
				repeated.push_back(standarNumber);
		}
		
		int size = repeated.size();
		sort(repeated.begin(), repeated.end());
		
		if(size)
		{
			for(int i = 0; i < size; ++i)
				cout << repeated[i] << " " << frequency[repeated[i]] << "\n";
		}
		else
			cout << "No duplicates.\n";
		if(testCases)
			cout << "\n";
	}
	return 0;
}