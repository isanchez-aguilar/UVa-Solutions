/*
*	User: Isanchez_Aguilar
*	Problem: UVA 945 - Loading a Cargo Ship
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int c;
	int t = 0;
	int capacity[9];
	int availableWeight[9];

	while (cin >> c)
	{
		int totalCargoWeight = 0;

		for (int i = 0; i < c; ++i)
		{
			cin >> capacity[i];

			totalCargoWeight += capacity[i];
			availableWeight[i] = capacity[i];
		}
		
		int p;
		int totalPackageWeight = 0;

		cin >> p;
		queue<int> package;

		for (int i = 0; i < p; ++i)
		{
			int pw;
			cin >> pw;

			package.push(pw);
			totalPackageWeight += pw;
		}

		int cargoWeight = 0;
		int maxContainer = 0;
		int loadedPackages = 0;
		stack<int> container[c];

		while (loadedPackages < 1000 and not package.empty())
		{
			vi bestSize;
			int minSize = 1000;

			for (int i = 0; i < c; ++i)
			{
				if (container[i].size() <= minSize)
				{
					if (container[i].size() < minSize)
						bestSize.clear();

					bestSize.push_back(i);
					minSize = container[i].size();
				}	
			}

			int maxAvailable = -1;
			vi bestAvailableWeight;

			for (int i = 0; i < bestSize.size(); ++i)
			{
				if (availableWeight[bestSize[i]] >= maxAvailable)
				{
					if (availableWeight[bestSize[i]] > maxAvailable)
						bestAvailableWeight.clear();

					bestAvailableWeight.push_back(bestSize[i]);
					maxAvailable = availableWeight[bestSize[i]];
				}	
			}

			int currentContainer = bestAvailableWeight.front();
			int packageWeight = package.front();

			if (packageWeight > availableWeight[currentContainer])
				break;

			package.pop();
			container[currentContainer].push(packageWeight);

			cargoWeight += packageWeight;
			availableWeight[currentContainer] -= packageWeight;
			maxContainer = max(maxContainer, (int)container[currentContainer].size());
		}

		if (t++)
			cout << "\n";

		for (int i = maxContainer; i >= 1; --i)
		{
			for (int j = 0; j < c; ++j)
			{
				if (j)
					cout << " ";

				if (container[j].size() == i)
				{
					cout << container[j].top();
					container[j].pop();
				}
				else
					cout << ":";
			}
			cout << "\n";
		}

		for (int i = 0; i < c; ++i)
		{
			if (i)
				cout << "=";

			cout << "=";
		}

		cout << "\n";

		for (int i = 1; i <= c; ++i)
		{
			if (i > 1)
				cout << " ";
			
			cout << i;
		}

		cout << "\n\n";

		cout << "cargo weight: " << cargoWeight << "\n";
		cout << "unused weight: " << totalCargoWeight - cargoWeight << "\n";
		cout << "unloaded weight: " << totalPackageWeight - cargoWeight << "\n";
	}

	return 0;
}