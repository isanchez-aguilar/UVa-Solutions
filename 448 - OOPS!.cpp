/*
*	User: Isanchez_Aguilar
*	Problem: UVA 448 - OOPS!
*/
#include <bits/stdc++.h>

using namespace std;

inline int getValue(char c)
{
	if (isalpha(c))
		return toupper(c) - 'A' + 10;

	return c - '0';
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string instruction[] = {
		"ADD",
		"SUB",
		"MUL",
		"DIV",
		"MOV",
		"BREQ",
		"BRLE",
		"BRLS",
		"BRGE",
		"BRGR",
		"BRNE",
		"BR",
		"AND",
		"OR",
		"XOR",
		"NOT"
	};

	const string opcode[] = {"R", "$", "PC+", ""};
	const int parameters[] = {2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1};

	string aux;
	string line = "";

	while (getline(cin, aux))
		line += aux;

	int i = 0;
	while (i < line.length())
	{
		char command = line[i++];
		int hexCode = getValue(command);

		cout << instruction[hexCode] << " ";

		for (int p = 0; p < parameters[hexCode]; ++p)
		{
			if (p)
				cout << ",";

			int code = getValue(line[i]);

			int op = code & 3;
			int bitCode = code >> 2;

			int value = op; 
			for (int j = 1; j < 4; ++j)
			{

				value = (value << 4) + getValue(line[i + j]);
			}

			cout << opcode[bitCode] << value;

			i += 4;
		}

		cout << "\n";
	}

	return 0;
}