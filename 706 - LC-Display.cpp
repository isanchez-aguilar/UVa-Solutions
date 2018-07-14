/*
*	User: Isanchez_Aguilar
*	Problem: UVA 706 - LC-Display
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	const char digit[][16] = {
		"-|| ||-", // 0
		" |   | ", // 1
		"-| -| -", // 2
		"-| - |-", // 3
		" ||- | ", // 4
		"- |- |-", // 5
		"- |-||-", // 6
		"-|   | ", // 7
		"-||-||-", // 8
		"-||- |-" // 9
	};

	int size = 0;
	string number;

	while (cin >> size and size)
	{
		cin >> number;

		int height = (size << 1) + 3;

		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < number.length(); ++j)
			{
				int d = number[j] - '0';
				

				if (i > 0 and i < size + 1) 
				{
					cout << digit[d][2];
					
					for (int k = 0; k < size; ++k) 
						cout << " ";
					
					cout << digit[d][1];
				}

				else if (i % (size + 1) == 0) 
				{
					cout << " ";
					
					for (int k = 0; k < size; ++k) 
						cout << digit[d][i / (size + 1) * 3];

					cout << " ";
				}

				else if (i > (size + 1) and i < height - 1) 
				{
					cout << digit[d][4];
					
					for (int k = 0; k < size; ++k) 
						cout << " ";
					
					cout << digit[d][5];
				}
				// Separation between digits.
				if (j != number.length() - 1)
					cout << " ";
			}

			cout << "\n";
		}
		
		cout << "\n";
	}

	return 0;
}